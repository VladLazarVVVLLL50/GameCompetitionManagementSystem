#include "liste.h"

struct N{
    Winner *content;
    struct N *left,*right;
};
typedef struct N Node;

struct N_AVL{
    Winner *content;
    int height;
    struct N_AVL *left, *right;
};
typedef struct N_AVL Node_AVL;


Node* newNode(Winner *team_being_added);

Node* insert(Node *node, Winner *team_inserted);

void reverseInorder(Node *root,FILE *g);

int nodeHeight(Node_AVL *root);

int maximum(int a,int b);

Node_AVL *RightRotation(Node_AVL *z);

Node_AVL* insert_in_avl(Node_AVL *node, Winner *team_inserted);

void printlevel(Node_AVL *root, int level, FILE *g);




