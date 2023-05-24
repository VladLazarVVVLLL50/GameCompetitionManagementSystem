#ifndef LISTE_H
#define LISTE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct P{
    char *firstName;
    char *secondName;
    int points;
    struct P *next_player;
};
typedef struct  P Player;

struct T{
    int number_of_members;
    float team_score;
    char *team_name;
    Player *list_of_members;
    struct T *next_team;
};
typedef struct T Team;

struct W{
    char *name;
    float score;
    struct W *next_winner;
};
typedef struct W Winner;

void add_winner_in_list(Winner **head, char *name_of_team, float final_score);


void add_player_at_beginning_of_team(Player **head, char *first_n, char *second_n, int p);

void add_player_at_end_of_team(Player **head, char *first_n, char *second_n, int p);

void add_team_at_beginning_of_list(Team **head, Player *member_list, int nr_members, char *name);

void display(Team *head, FILE *g1);

void free_player_list(Player **head);

void free_team_list(Team **head);

void free_winner_list(Winner **head);




#endif // LISTE_H