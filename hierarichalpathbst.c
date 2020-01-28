#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
int i=0; 
struct node *root=NULL;
struct node *ptr;
void insertt(int item)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=item;
  newnode->left=NULL;
  newnode->right=NULL;
	ptr=root;
  struct node *parent=NULL;
	    while(ptr!=NULL)
	    { 
        parent = ptr; 
        if (item < ptr->data) 
            ptr = ptr->left; 
        else
            ptr = ptr->right; 
      } 
      if(parent==NULL)
      {
        parent=root=newnode;
      }
      else if(item<parent->data)
      {
        parent->left=newnode;
      }
      else
      {
        parent->right=newnode;
      }
}
void path(int inst,struct node *root)
{
  int arr[100];
  int d=0;
  int g=0;
  struct node *pt=root;
      while(pt!=NULL)
      {
         arr[d]=pt->data;
         d++;
         if(pt->data==inst)
         {
           g=1;
             break;
         }
         else if(inst<pt->data)
         {
          pt=pt->left;
         }
         else
         {
          pt=pt->right;
         }
      }
      if(g==0)
      {
        printf("Element not found");
        return;
      }
      for(int i=0;i<d;i++)
      {
        printf("%d ",arr[i]);
      }
      printf("\n");
}
int main()
{
   int item;
   int option;
   while(1)
   {
    printf("Press 1 for insertion\nPress 2 for printing hierarichal path of a node\n");
     scanf("%d",&option);
     if(option==1)
     {
      scanf("%d",&item);
      insertt(item);
     }
     else if(option==2)
     {
      int inst;
      printf("Enter element for its hierarichal path\n");
      scanf("%d",&inst);
      path(inst,root);
     }
   }
   return 0;
}