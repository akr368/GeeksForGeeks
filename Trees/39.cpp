#include <iostream>
using namespace std;
void preorder(struct node *);

struct node{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


void connect(struct node *p){
  
   p->nextRight=NULL;
   preorder(p);
}

void preorder(struct node *p){
   
   if(!p)
    return;

   if(p->left!=NULL)
    p->left->nextRight=p->right;

   if(p->right!=NULL)
    p->right->nextRight=(p->nextRight)?p->nextRight->left:NULL;

   preorder(p->left);
   preorder(p->right);

}


int main() { 

   struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
 
 
  connect(root);
 

    return 0;

}

