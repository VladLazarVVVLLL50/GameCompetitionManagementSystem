#include "task_3.h"

int find_round_with_8_teams(int number){
  int count =0;
  while(number>8){
   count++;
   number /= 2;
  }
  return count;
}

Team *find_team(Team *list, char *name)
{Team *head = list;
 while(head != NULL){
    if(!strcmp(head->team_name,name))return head;
    head = head->next_team;
 }
 return NULL;
}

void raise_score(Team *team){
 team->team_score = team->team_score+1;
 while(team->list_of_members != NULL){
    team->list_of_members->points = team->list_of_members->points+1;
    team->list_of_members=team->list_of_members->next_player;
 }


}


Winner* solve_task_3(Team *initial_list, int number_of_teams, FILE *g1){

 Team *stack_of_winners = NULL;
 Team *stack_of_loosers = NULL;
 Queue *queue_of_matches = create_Queue();
 int round_number = 1;
 int round_of_winners = find_round_with_8_teams(number_of_teams);
 Winner *list_of_winners = NULL;
 display(initial_list,g1);

 Team *val = initial_list;
 while(val != NULL){
    enQueue(queue_of_matches,val->team_name,(val->next_team)->team_name);
    val = val->next_team->next_team;
 }

 while(!is_the_queue_Empty(queue_of_matches)){
    fprintf(g1,"\n--- ROUND NO:%d\n",round_number);
    Match *aux = queue_of_matches->Front;
    while(aux != NULL){
      if(aux->second_team[strlen(aux->second_team)-1] == ' ')
      {fprintf(g1,"%-33s-",aux->first_team,aux->second_team);
       int i;
       for(i=1;i<33-strlen(aux->second_team)+2;i++)
        fprintf(g1," ");
       for(i=0;i<strlen(aux->second_team)-1;i++)
        fprintf(g1,"%c",aux->second_team[i]);
        fprintf(g1,"\n");
      }
        
       else fprintf(g1,"%-33s-%33s\n",aux->first_team,aux->second_team);
        Team *team_1 = find_team(initial_list,aux->first_team);
        Team *team_2 = find_team(initial_list,aux->second_team);
        if(team_1->team_score > team_2->team_score){
         raise_score(team_1);
         push(&stack_of_winners,team_1);
         push(&stack_of_loosers,team_2);
        }
        else{
          raise_score(team_2);
          push(&stack_of_winners,team_2);
          push(&stack_of_loosers,team_1);
        }
        aux = aux->next_match;
        deQueue(queue_of_matches);
    }
    fprintf(g1,"\n");
    fprintf(g1,"WINNERS OF ROUND NO:%d\n",round_number);
    val = stack_of_winners;
    while(val != NULL){
     fprintf(g1,"%-34s-  %0.2f\n",val->team_name,val->team_score);
     if(round_of_winners == round_number){
       add_winner_in_list(&list_of_winners,val->team_name,val->team_score);
       add_winner_in_list(&list_of_winners,val->next_team->team_name,val->next_team->team_score);
     }
     if(val->next_team != NULL){
        fprintf(g1,"%-34s-  %0.2f\n",val->next_team->team_name,val->next_team->team_score);
        enQueue(queue_of_matches,val->team_name,val->next_team->team_name);
        pop(&stack_of_winners);pop(&stack_of_winners);
        val = val->next_team->next_team;
     }
     else{pop(&stack_of_winners); val = val->next_team;}
    }
    deleteStack(&stack_of_loosers);
    round_number++;
  }
 
 return list_of_winners;

}