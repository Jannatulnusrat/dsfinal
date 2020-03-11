
include<stdio.h>
#include<conio.h>
typedef struct node
{
  int data;
  struct node *next;
} node;

int empty(node *list)
{
  if(list == NULL)
    return 1;
  return 0;
}


void display(node *list)
{ if(empty(list))
  {
    printf("\n\tQueue is empty, cannot display queue.\n");
  }
  else
  {
    printf("\n\tElements in linked list : ");
    while(list != NULL)
    {
    printf("  %d",list->data);
    list = list->next;
    }
    printf("\n");
  }
}
void main()
{
  node *front, *rear, *newnode;
  int choice=1,data;
  front = NULL;
  rear = NULL;

  clrscr();
  while(choice<=3)
  {
    printf("\n1.insert.  2.delete.  3.display");
    printf("\nEnter your chioce : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	printf("\n\tEnter the data for new node : ");
	scanf("%d",&data);
	newnode =  (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->next = NULL;
	if(empty(front))
	{
	  front = newnode;
	  rear = newnode;
	}else{
	  rear->next = newnode;
	  rear = newnode;
	}
	printf("\tElement inserted in queue.\n");
      break;
      case 2:
	if(empty(front))
	{
	  printf("\n\tQueue is already empty!!!\n");
	}
	else
	{
	  front  = front->next;
	  if(empty(front))
	    printf("\n\tQueue is empty now!!!\n");
	  else
	    printf("\n\tElement deleted\n");
	}

      break;
      case 3:
	display(front);
      break;
    }
  }
getch();
}
