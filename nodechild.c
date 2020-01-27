#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
int i=0; 
struct node *nodeStack[20]; 
struct node *root=NULL;
struct node *ptr;
int arr[100];
int arr1[100];
int k=0;
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
int length(struct node *root)
{
  if(root==NULL)
  {
    return 0;
  }
  else
  {
    int leftheight=length(root->left);
    int rightheight=length(root->right);
    if(leftheight>rightheight)
    {
      return leftheight+1;
    }
    else
    {
      return rightheight+1;
    }
  }
}
void child(struct node* root,int it)
{    
   if(root==NULL)
   {
    return;
   }
   else
   {
    arr[k]=root->data;
    arr1[k]=it;
    k++;
    child(root->left,it+1);
    child(root->right,it+1);
    return;
   }
}
int main()
{
   int item;
   int option;
   while(1)
   {
     scanf("%d",&option);
     if(option==1)
     {
      scanf("%d",&item);
      insertt(item);
     }
     else if(option==2)
     {
      int it=0;
      int l=length(root);
      child(root,it);
      while(l--)
      {
        for(int i=0;i<k;i++)
        {
          if(arr1[i]==it)
          {
             printf("%d ",arr[i]);
          }
        }
        it++;
        printf("\n");
      }
     }
   }
   return 0;
}