#ifndef STIVE_H
#define STIVE_H

#include "liste.h"

void push(Team **top, Team *team_being_pushed);

void pop(Team **top);

int is_the_stack_Empty(Team *top);

void deleteStack(Team **top);


#endif //STIVE_H