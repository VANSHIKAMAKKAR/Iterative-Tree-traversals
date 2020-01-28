#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node *root=NULL;
struct node *ptr;
int arr[100];
int d=0;
struct node* new(int item)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=item;
  newnode->left=NULL;
  newnode->right=NULL;
}
void path(int inst,struct node *root)
{
  if(root==NULL)
    return;
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
      if(root==NULL)
      {
        root=new(item);
      }
      else
      {
        struct node *pt=root;
        while(pt!=NULL)
        {
          printf("Current Node : %d\n",pt->data);
          printf("Press 1 for in insertion in left\nPress 2 for insertion in right\nPress 3 to break\n");
          int side;
          int k=0;
          scanf("%d",&side);
          if(side==1)
          {
            if(pt->left==NULL)
            {
              pt->left=new(item);
              k=1;
            }
            if(k==1)
            {
              break;
            }
            pt=pt->left;
          }
          else if(side==2)
          {
            if(pt->right==NULL)
            {
              pt->right=new(item);
              k=1;
            }
            if(k==1)
            {
              break;
            }
            pt=pt->right;
          }
          else if(side==3)
          {
            break;
          }
        }
      }
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