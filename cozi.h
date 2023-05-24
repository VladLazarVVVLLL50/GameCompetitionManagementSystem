#ifndef COZI_H
#define COZI_H

#include "liste.h"

struct M{
 char *first_team, *second_team;
 struct M *next_match;
};
typedef struct M Match;



struct Q{
  Match *Front,*Rear;
};
typedef struct Q Queue;

Queue* create_Queue();

int is_the_queue_Empty(Queue *q);

void enQueue(Queue *q, char *first_team_added, char *second_team_added);

void deQueue(Queue *q);

void deleteQueue(Queue *q);







#endif //COZI_H