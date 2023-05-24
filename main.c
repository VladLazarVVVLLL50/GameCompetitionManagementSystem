#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
int main(int argc, char *argv[]){

 FILE *f,*g;
 
 f=fopen(argv[1],"r");
 if(f==NULL){
  printf("eroare");
  exit(1);
 }
 g=fopen(argv[3],"w");
 if(g==NULL){
  printf("eroare");
  exit(1);
 }
 int i,number_of_teams=0;
 Team* list_of_teams=NULL;
 Winner *list_of_winners = NULL;

 int *tasks = (int*)malloc(6*sizeof(int));
 for(i=1;i<=5;i++)fscanf(f,"%d",&tasks[i]);

 list_of_teams=solve_task_1(&number_of_teams,argv[2]);

 if(tasks[1] && !tasks[2])display(list_of_teams,g);

 solve_task_2(&list_of_teams,&number_of_teams);
 
 if(tasks[2] && !tasks[3])display(list_of_teams,g);
 
 if(tasks[3]) list_of_winners =  solve_task_3(list_of_teams,number_of_teams,g);
 
 if(tasks[4] && !tasks[5]) solve_task_4(list_of_winners,g,4); 
 else if(tasks[4] && tasks[5]) solve_task_4(list_of_winners,g,5); 
 
 free_team_list(&list_of_teams);
 free_winner_list(&list_of_winners);
 free(tasks);
 fclose(f); fclose(g);
 
 return 0;
}