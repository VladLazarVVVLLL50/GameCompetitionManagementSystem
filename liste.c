#include "liste.h"

void add_winner_in_list(Winner **head, char *name_of_team, float final_score){
 
 Winner *newWinner = (Winner*)malloc(sizeof(Winner));
 newWinner->name = (char*)malloc(strlen(name_of_team)*sizeof(char)+5);
 strcpy(newWinner->name,name_of_team);
 newWinner->score = final_score;
 newWinner->next_winner = *head;
 *head = newWinner;
}


void add_player_at_beginning_of_team(Player **head, char *first_n, char *second_n, int p){

    Player *newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->firstName=(char*)malloc(strlen(first_n)*sizeof(char)+5);
    strcpy(newPlayer->firstName,first_n);
    newPlayer->secondName=(char*)malloc(strlen(second_n)*sizeof(char)+5);

    strcpy(newPlayer->secondName,second_n);
    newPlayer->points=p;
    newPlayer->next_player=*head;
    *head=newPlayer;
}

void add_player_at_end_of_team(Player **head, char *first_n, char *second_n, int p){


    Player *aux=*head;
    Player *newPlayer = (Player*)malloc(sizeof(Player)+5);
    newPlayer->firstName=(char*)malloc(strlen(first_n)*sizeof(char)+5);
    strcpy(newPlayer->firstName,first_n);
    newPlayer->secondName=(char*)malloc(strlen(second_n)*sizeof(char)+5);
    strcpy(newPlayer->secondName,second_n);
    newPlayer->points=p;
    if(*head == NULL) add_player_at_beginning_of_team(&*head,first_n,second_n,p);
    else{
         while(aux->next_player != NULL)aux=aux->next_player;
         aux->next_player = newPlayer;
         newPlayer->next_player = NULL;
    }
 
}

void add_team_at_beginning_of_list(Team **head, Player *member_list, int nr_members, char *name){

    Team *newTeam = (Team*)malloc(sizeof(Team));
    newTeam->number_of_members = nr_members;
    newTeam->team_name=(char*)malloc(strlen(name)*sizeof(char)+5);
    strcpy(newTeam->team_name,name);
    newTeam->list_of_members = member_list;
    newTeam->next_team = *head;
    *head = newTeam;
 
}

void display(Team *head, FILE *g1){


   while(head != NULL){
    int len = strlen(head->team_name);
    int i;
    for(i=0;i<len;i++)
     if(i!= (len-1) ||(i==len-1 && head->team_name[len-1]!= ' '))
    fprintf(g1,"%c",head->team_name[i]);
    fprintf(g1,"\n");
    head=head->next_team;
   }



}

void eliminate_team(Team **head , char *name){

 if(*head == NULL )return;
 Team *head_copy = *head;

 if(!strcmp(name,head_copy->team_name)){
    *head = (*head)->next_team;
    free(head_copy->team_name);
    free_player_list(&head_copy->list_of_members);
    free(head_copy);
    return;
 }

 Team *prev=*head;
 while(head_copy != NULL){
    if(strcmp(name,head_copy->team_name)){
        prev = head_copy;
        head_copy = head_copy->next_team;
    }
    else {
        prev->next_team = head_copy->next_team;
        free(head_copy->team_name);
        free_player_list(&head_copy->list_of_members);
        free(head_copy);
        return;
    }
 }
}

void free_player_list(Player **head){
 
 Player *current= (*head);
 while(current != NULL){
    Player *temp = current;
    current=current->next_player;
    free(temp->firstName);
    free(temp->secondName);
    free(temp);
 }
 
}

void free_team_list(Team **head){
 Team *current = (*head);
 while(current != NULL){
    Team *temp=current;
    current=current->next_team;
    free(temp->team_name);
    free_player_list(&temp->list_of_members);
    free(temp);
 }
 
}

void free_winner_list(Winner **head){
    Winner *current = (*head);
    while(current != NULL){
        Winner *temp = current;
        current = current->next_winner;
        free(temp->name);
        free(temp);
    }
}

