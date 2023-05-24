#include "arbori.h"



Node* newNode(Winner *team_being_added){
    
    Node *node = (Node*)malloc(sizeof(Node));
    node->content = team_being_added;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node *node, Winner *team_inserted){
     
    if(node == NULL) return newNode(team_inserted);
    
    if(team_inserted->score < node->content->score || (team_inserted->score == node->content->score && strcmp(team_inserted->name,node->content->name)<0))
     node->left = insert(node->left,team_inserted);
    else if(team_inserted->score > node->content->score || (team_inserted->score == node->content->score && strcmp(team_inserted->name,node->content->name)>0))
     node->right = insert(node->right,team_inserted);
    return node;
}

void reverseInorder(Node *root,FILE *g){
  
  if(root == NULL) return;
  reverseInorder(root->right,g);
  fprintf(g,"%-33s -  %0.2f\n",root->content->name,root->content->score);
  reverseInorder(root->left,g);

}

int nodeHeight(Node_AVL *root){
  int hs,hd;
  if(root == NULL)return -1;
  hs = nodeHeight(root->left);
  hd = nodeHeight(root->right);
  return 1+((hs>hd)? hs:hd);
}

int maximum(int a,int b){
  if(a>=b)return a;
  return b;
}

Node_AVL *RightRotation(Node_AVL *z){
  Node_AVL *y = z->left;
  Node_AVL *T3 = y->right;
  y->right = z;
  z->left = T3;
  z->height = maximum(nodeHeight(z->left),nodeHeight(z->right))+1;
  y->height = maximum(nodeHeight(y->left),nodeHeight(y->right))+1;
  return y;
}

Node_AVL* insert_in_avl(Node_AVL *node, Winner *team_inserted){
  
 if(node == NULL){
  node = (Node_AVL*)malloc(sizeof(Node_AVL));

  node->content = team_inserted;
  node->height =0;
  node->left = node->right = NULL;
  return node;
 }
 else node->left = insert_in_avl(node->left,team_inserted);
 
 node->height = 1+maximum(nodeHeight(node->left),nodeHeight(node->right));
 int k = (nodeHeight(node->left) - nodeHeight(node->right));
 

  if(k>1) return RightRotation(node); 
 return node;
}

void printlevel(Node_AVL *root, int level, FILE *g){
  if(root) {
   printlevel(root->right,level,g);
   fprintf(g,"%s %d\n",root->content->name,root->height);
   printlevel(root->left,level,g);
    
  }
}