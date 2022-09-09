#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char * word ) {
    if(*root==NULL){
        struct bst_node *newNode = (char *) malloc(sizeof(bst_node));
        newNode->data = word;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return;
    }    
    addRep(root,word);
    printf("\n");
    return;
}

void addRep(bst_node **current, char* word){
    printf("%s->",(*current)->data);
    int cmp = strcmp(word,(*current)->data);
    if(cmp>0){
        if((*current)->right!=NULL) addRep(&((*current)->right),word);
        else{
            struct bst_node *newNode = (bst_node *) malloc(sizeof(bst_node));
            newNode->data = word;
            newNode->left = NULL;
            newNode->right = NULL;
            (*current)->right=newNode;            
        }
        return;
    }
    if(cmp<0){
        if((*current)->left!=NULL) addRep(&((*current)->left),word);
        else{
            struct bst_node *newNode = (bst_node *) malloc(sizeof(bst_node));
            newNode->data = word;
            newNode->left = NULL;
            newNode->right = NULL;
            (*current)->left=newNode;
        }
        return;
    }   
    printf("Error: Identical Value\n");
    return;
}

 
void inorder ( bst_node * root ) {
    if(root!=NULL) inorderRep(root);
    return;
}

void inorderRep(bst_node *current){
    printf("%s ",current->data);
    printf("L:\t");
    if(current->left!=NULL) inorderRep(current->left);    
    printf("R:\t");
    if(current->right!=NULL) inorderRep(current->right);
    return;
}

 
char * removeSmallest (  bst_node ** root ){    
    if(*root==NULL) return NULL;
    else return removeSmallestRep(root);
}

char * removeSmallestRep(bst_node **current){
    if((*current)->left!=NULL)
        return removeSmallestRep(&(*current)->left);
    char * rep = (char*) malloc(256 * sizeof(char));
    strcpy(rep,(*current)->data);
    if((*current)->right==NULL){
        free(*current);
        *current = NULL;
        return rep;
    }
    struct bst_node * cr = (*current)->right;
    char * dt = (char *) malloc(256 * sizeof(char));
    strcpy(dt,cr->data);
    (*current)->data = dt;
    (*current)->right = cr->right;
    (*current)->left = cr->left;
    free(cr);
    return rep;
}

char * removeLargest (bst_node ** root ){
    if(*root==NULL) return NULL;
    else return removeLargestRep(root);
}

char * removeLargestRep(bst_node **current){
    if((*current)->right!=NULL)
        return removeLargestRep(&(*current)->right);
    char * rep = (char*) malloc(256 * sizeof(char));
    strcpy(rep,(*current)->data);
    if((*current)->left==NULL){
        free(*current);
        *current = NULL;
        return rep;
    }
    struct bst_node * cr = (*current)->left;
    char * dt = (char *) malloc(256 * sizeof(char));
    strcpy(dt,cr->data);
    (*current)->data = dt;
    (*current)->right = cr->right;
    (*current)->left = cr->left;
    free(cr);
    return rep;
}
 



