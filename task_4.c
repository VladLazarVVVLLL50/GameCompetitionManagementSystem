#include "task_4.h"

void create_AVL(Node *root, Node_AVL **root_avl){
    if(root){
        
         
         
         create_AVL(root->right,root_avl);
         (*root_avl) = insert_in_avl(*root_avl,root->content);
         create_AVL(root->left,root_avl);
         
    }
}

void print(Node_AVL *root, FILE *g){
    if(root == NULL)return;
    Node_AVL ** currentLevel = (Node_AVL**)malloc(sizeof(Node_AVL*));
    Node_AVL ** nextLevel = (Node_AVL**)malloc(sizeof(Node_AVL*));
    int currentlevelsize =0, nextlevelsize =0,level=0;
    currentLevel[currentlevelsize++]=root;
    while(currentlevelsize>0){
        int i;
        for(i=0;i<currentlevelsize;i++){
            Node_AVL *current = currentLevel[i];
            if(level == 2)fprintf(g,"%s\n",current->content->name);
            
            if(current->right !=NULL)
            nextLevel[nextlevelsize++] = current->right;
            if(current->left !=NULL)
            nextLevel[nextlevelsize++] = current->left;
        }
        
        Node_AVL **temp = currentLevel;
        currentLevel = nextLevel;
        nextLevel = temp;
        currentlevelsize = nextlevelsize;
        nextlevelsize =0;
        level++;
    }

}

void solve_task_4(Winner *list_of_winners, FILE *g,int task){
    Node *root = NULL;
    while(list_of_winners != NULL){
        root = insert(root,list_of_winners);
        list_of_winners = list_of_winners->next_winner;
    }
    fprintf(g,"\nTOP 8 TEAMS:\n");

    reverseInorder(root,g);
    if(task == 5 ){
        fprintf(g,"\nTHE LEVEL 2 TEAMS ARE:\n");
        Node_AVL *root_avl = NULL;
         
        create_AVL(root, &root_avl);
       // printlevel(root_avl,2,g);
        print(root_avl,g);
    }
    

    
}