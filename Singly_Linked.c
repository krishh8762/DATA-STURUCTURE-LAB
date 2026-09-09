#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

void insertBeginning()
{
   struct node *newNode;
   int value;

   newNode = (struct node *)malloc(sizeof(struct node));

   printf("Enter value:");
   scanf("%d", &value);

   newNode->data = value;
   newNode->next = head;
   head = newNode;

   printf("Node inserted successfully.\n");
}

void insertEnd()
{
   struct node *newNode, *temp;
   int value;

   newNode = (struct node*)malloc(sizeof(struct node));

   printf("Enter Value:");
   scanf("%d",&value);

   newNode->data = value;
   newNode->next = NULL;

   if (head==NULL)
   {
      head= newNode;
   }
   else
   {
      temp = head;

      while (temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = newNode;
   }

   printf("Node inserted successfully.\n");
}

void deleteBeginning()
{
   struct node *temp;

   if (head == NULL)
   {
      printf("List is empty.\n");
      return;
   }

   temp = head;
   head = head->next;

   printf("Deleted element: %d\n", temp->data);

   free(temp);
}

void deleteEnd()
{
   struct node *temp, *prev;

   if (head == NULL)
   {
      printf("List is empty.\n");
      return;
   }
   
   if (head->next == NULL)
   {
      printf("Deleted Element: %d\n", head->data);
      free(head);
      head = NULL;
      return;
   }

   temp = head;
   
   while (temp->next != NULL)
   {
      prev = temp;
      temp = temp->next;
   }

   prev->next = NULL;

   printf("deleted element: %d\n", temp->data);

   free(temp);
}

void display()
{
   struct node*temp;

   if (head == NULL)
   {
      printf("List is empty.\n");
      return;
   }
      while (temp != NULL)
      {
         printf("%d -> ", temp->data);
         temp = temp->next;
      }

      printf("NULL\n");
   }

   void search()
   {
      struct node*temp;
      int value, position = 1;

      printf("Enter value to search:");
      scanf("%d", &value);

      temp = head;

      while (temp != NULL)
      {
         if (temp->data == value)
         {
            printf("Element found at position %d.\n", position);
            return;
         }
         temp = temp->next;
         position++;
      }
      printf("Element not found.\n");
   }

   int main()
   {
      int choice;

      while (1)
      {
         printf("\n--- SINGHLY LINKED LIST ---\n");
         printf("1. Insert at Beginning\n");
         printf("2. Insert at End\n");
         printf("3. Delete from Beginning\n");
         printf("4. delete from End\n");
         printf("5. Display\n");
         printf("6. Search\n");
         printf("7. Exit\n");

         printf("Enter your choice:");
         scanf("%d", &choice);
         
         switch (choice)
         {
            case 1:
               insertBeginning();
               break;

            case 2:
               insertEnd();
               break;
            
            case 3:
               deleteBeginning();
               break;

            case 4:
               deleteEnd();
               break;

            case 5:
               display();
               break;
            
            case 6:
               search();
               break;
            
            case 7:
               exit(0);

            default:
               printf("Invalid choice!\n");

         }

      }
      return 0;
   }
   
