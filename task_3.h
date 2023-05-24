#include "cozi.h"
#include "stive.h"

int find_round_with_8_teams(int number);

Team *find_team(Team *list, char *name);

void raise_score(Team *team);

Winner* solve_task_3(Team *initial_list, int number_of_teams, FILE *g1);