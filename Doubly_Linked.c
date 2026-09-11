#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;

void insert(int value) {
   struct node *newnode, *temp;

   newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = value;
   newnode->prev = NULL;
   newnode->next = NULL;

   if (head == NULL) {
      head = newnode;
   }else{
      temp = head;

      while (temp->next != NULL) 
         temp = temp->next;

       temp->next = newnode;
       newnode->prev = temp;
   
   }
}

void displayBackward() 
{
   struct node *temp = head;
   if (temp == NULL) {
      printf("List is empty.\n");
      return;
   }

   while (temp->next != NULL)
      temp = temp->next;

      printf("Doubly Linked List (Backward):");

      while (temp != NULL) {
         printf("%d", temp->data);
         temp = temp->prev;
      }

      printf("\n");

}

void displayForward()
{
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
int main() {
   int n, value, i;

   printf("Enter number of nodes:");
   scanf("%d", &n);

   for (i=0; i<n; i++) {
      printf("Enter value: ");
      scanf("%d", &value);
      insert(value);
   }
   displayForward();
   displayBackward();

   return 0;
}