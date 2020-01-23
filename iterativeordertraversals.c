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
void push(struct node *head)
{
   i++;
   nodeStack[i]=head;
}
struct node * top()
{
  return nodeStack[i];
}
struct node * pop()
{
  i--;
  return nodeStack[i+1];
}
void preorder(struct node *root)
{
    push(root); 
    while (nodeStack!=NULL) 
    { 
        struct node *node = top(); 
        printf ("%d ", node->data); 
        pop(); 
        if (node->right) 
            push(node->right); 
        if (node->left) 
            push(node->left); 
    } 
}
void inorder(struct node *root)
{
  struct node *curr=root;
  while(i!=0||curr!=NULL)
  {
     if(curr!=NULL)
     {
      push(curr);
      curr=curr->left;
     }
     else
     {
      curr=top();
      pop();
      printf("%d ",curr->data);
      curr=curr->right;
     }
  }
}
void postorder(struct node *root)
{
  if(root==NULL)
    return;
  do{
    while(root)
    {
      if(root->right)
      {
        push(root->right);
      }
      push(root);
      root=root->left;
    }
    root=pop();
    if(root->right && top()==root->right)
    {
      pop();
      push(root);
      root=root->right;
    }
    else
    {
      printf("%d ",root->data);
      root=NULL;
    }
  }while(i!=0);
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
      preorder(root);
     }
     else if(option==3)
     {
      inorder(root);
     }
     else if(option==4)
     {
      postorder(root);
     }
   }
   return 0;
 }