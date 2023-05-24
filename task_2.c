#include "task_2.h"


int reduce_number(int val){
 int p=0;
 int power_of_2=1;
 while(power_of_2 <= val/2){
    power_of_2*=2;
    p++;
 }
 return power_of_2;
}

float find_score(Team *team){
 float score=0;
 while(team->list_of_members != NULL){
    score += team->list_of_members->points;
    team->list_of_members=team->list_of_members->next_player;
 }

 score /= team->number_of_members;
 return score;
}

void eliminate_teams(Team **head,int number,float max_score){

 while(number>0){

    Team *aux=(*head);
    float min_nr=max_score+1;
    char *name=NULL;
    while(aux != NULL){
     if(aux->team_score<min_nr){
       min_nr=aux->team_score;
       if(name != NULL)free(name);
       name=(char*)malloc(strlen(aux->team_name)*sizeof(char)+5);
       strcpy(name,aux->team_name);
      }
      aux=aux->next_team;
     }
    eliminate_team(head,name);
    free(name);
    number--;
   }
}




void solve_task_2(Team **list_of_teams,int *number_of_teams){

 int new_number_of_teams=reduce_number(*number_of_teams);
 int nr_of_eliminated_teams=(*number_of_teams)- new_number_of_teams;
 int max_score=0;
 Team *aux = (*list_of_teams);
 while(aux != NULL){
  aux->team_score = find_score(aux);
  if( aux->team_score > max_score) max_score = aux->team_score;
  aux = aux->next_team;
 }

 eliminate_teams(list_of_teams,nr_of_eliminated_teams,max_score);
 *number_of_teams=new_number_of_teams;

}