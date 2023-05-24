#include "cozi.h"

Queue* create_Queue(){
 Queue *q;
 q = (Queue*)malloc(sizeof(Queue));
 if(q == NULL)return NULL;
 q->Front = q->Rear = NULL;
 return q;
}

int is_the_queue_Empty(Queue *q){
 return (q->Front == NULL);
}

void enQueue(Queue *q, char *first_team_added, char *second_team_added){
 Match* newMatch = (Match*)malloc(sizeof(Match));
 newMatch->first_team = (char*)malloc(strlen(first_team_added)*sizeof(char)+5);
 newMatch->second_team = (char*)malloc(strlen(second_team_added)*sizeof(char)+5);
  strcpy(newMatch->first_team,first_team_added);
  strcpy(newMatch->second_team,second_team_added);
 
 newMatch->next_match = NULL;

 if(q->Rear == NULL) q->Rear = newMatch;
 else{
    (q->Rear)->next_match = newMatch;
    (q->Rear) = newMatch;
 }
 if(q->Front == NULL) q->Front = q->Rear;

 

}

void deQueue(Queue *q){

 Match *aux;
 aux = q->Front;
 q->Front = (q->Front)->next_match;
 free(aux->first_team);
 free(aux->second_team);
 free(aux);
 
}

void deleteQueue(Queue *q){

 Match *aux;
 while(!is_the_queue_Empty(q)){
    aux = q->Front;
    q->Front = (q->Front)->next_match;
    free(aux->first_team);
    free(aux->second_team);
    free(aux);
    
 }
 free(q);
}