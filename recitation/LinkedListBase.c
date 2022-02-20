#include <stdio.h>
struct node {
  char * word;
  struct node * next;
};

void addFront(struct node * n, struct node ** head);
struct node* reverseOrder (struct node ** current, struct node * previous);
void delete(struct node ** head, int num);
int main()
{  
  struct node * head = 0; // head p o i n t e r for the list
  struct node n1 = { "hello", 0}; 
  struct node n2 = { "cso201", 0}; 
  struct node n3 = { "students", 0};
  
  
  addFront (&n1, &head); 
  addFront (&n2, &head);
  addFront (&n3, &head);
  struct node * current = head;
  printf("\norigonal:\n");
  while (current != 0 ) {
  printf ("%s	", current->word ); current = current->next;
  }
  printf("\nReversed:\n");
  head = reverseOrder(&head,0);
  current = head;
  while (current != 0 ) {
    printf ("%s	", current->word ); current = current->next;
  }
  printf("\ndelected(2):\n");
  delete(&head,2);
   current = head;
  while (current != 0 ) {
    printf ("%s	", current->word ); current = current->next;
  }
  return 0;
}
 
void addFront(struct node * n, struct node ** head) {
  n->next =   *head  ;
  *head  = n;
  printf ("%s	", (*head)->word ); 
}

struct node* reverseOrder(struct node ** current, struct node * previous){
  struct node *RE;
  if((*current)->next != 0) RE = reverseOrder(&((*current)->next),(*current));
  else RE = *current;
  (*current)->next = previous;
  return RE;
}

void delete(struct node ** head, int num){
  int i;
  struct node * current = *head;
  if(num!=1){
    for(i=1;i<num-1;i++){
      current = (current)->next;
    }
    current->next = (current->next)->next;
  }
  else{
    *head = (*head)->next;
  }
}

 

 
 
