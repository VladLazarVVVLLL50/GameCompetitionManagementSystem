#include "stive.h"


void push(Team **top, Team *team_being_pushed){

 Team *newTeam = (Team*)malloc(sizeof(Team));
 if(newTeam == NULL) printf("eroare");
 newTeam->number_of_members = team_being_pushed->number_of_members;
 newTeam->team_score = team_being_pushed->team_score;
 newTeam->team_name=(char*)malloc(strlen(team_being_pushed->team_name)*sizeof(char)+5);
 strcpy(newTeam->team_name,team_being_pushed->team_name);
 newTeam->list_of_members=team_being_pushed->list_of_members;

 newTeam->next_team = (*top);
 (*top) = newTeam;

 

}

void pop(Team **top){

 Team *temp = (*top);

 *top = (*top)->next_team;

  free(temp->team_name);
    free_player_list(&temp->list_of_members);
   free(temp);
   
}

int is_the_stack_Empty(Team *top){
    return top == NULL;
}

void deleteStack(Team **top){
 Team *temp;
 while((*top)!= NULL){
    temp = (*top);
    (*top) = (*top)->next_team;
    free(temp->team_name);
    free_player_list(&temp->list_of_members);
    free(temp);
  
 
 }

}