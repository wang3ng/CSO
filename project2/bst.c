#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {    
    struct bst_node *current = *root;
    if(current==0){
        struct bst_node *newNode = (bst_node*) malloc (sizeof(bst_node));
        newNode->data = word;
        *root = newNode;
        return;
    }
    while (current!=0)
    {
        int cmp = strcmp(word,current->data);
        if(cmp<0){
            if(current->left==0){
                struct bst_node *newNode = (bst_node*) malloc (sizeof(bst_node));
                newNode->data = word;
                newNode->left = NULL;
                newNode->right = NULL;
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        
        else if(cmp>0) {
            if(current->right==0){
                struct bst_node *newNode = (bst_node*) malloc (sizeof(bst_node));
                newNode->data = word;
                newNode->left = NULL;
                newNode->right = NULL;
                current->right = newNode;
                return;
            }
            current = current->right;
        }        
        else return;
    }
        
    return NULL;
}

 
void inorder ( bst_node * root ) {
    if(root!=NULL) inorderRep(root);
    return;
}

void inorderRep(bst_node *current){
    if(current->left!=NULL) inorderRep(current->left);    
    printf("%s ",current->data);
    if(current->right!=NULL) inorderRep(current->right);
    return;
}


 
char * removeSmallest (  bst_node ** root ){
    if(*root==NULL) return NULL;
    struct bst_node *current = *root;
    if((*root)->left == 0){
        char * rep = (char*) malloc(256 * sizeof(char));
        strcpy(rep,(*root)->data);
        *root = (*root)->right;
        free(current);
        return rep;
    }    
    while(current->left->left!=0){
        current = current->left;
    }
    char * rep = (char*) malloc(256 * sizeof(char));
    strcpy(rep,(current->left)->data);
    free(current->left);
    current->left = current->left->right;    
    return rep;
}

 
char * removeLargest (  bst_node ** root ){
    if(*root==NULL) return NULL;
    struct bst_node *current = *root;
    if((*root)->right == 0){
        char * rep = (char*) malloc(256 * sizeof(char));
        strcpy(rep,(*root)->data);
        *root = (*root)->left;
        free(current);
        return rep;
    }    
    while(current->right->right!=0){
        current = current->right;
    }
    char * rep = (char*) malloc(256 * sizeof(char));
    strcpy(rep,(current->right)->data);
    free(current->right);
    current->right = current->right->left;    
    return rep;
}




