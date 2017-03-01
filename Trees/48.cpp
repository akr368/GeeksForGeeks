#include <iostream>
#include <queue>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* newnode(int data){

    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;

}

void printLeaves(struct node *node){
   
    if(node==NULL)
      return;
    
    if(node->left==NULL && node->right==NULL)
      cout<<node->data<<" ";
    
    printLeaves(node->left);
    printLeaves(node->right);

}

void printLeft(struct node *node){
   
   
    if(node->left!=NULL){
      cout<<node->data<<" ";
      printLeft(node->left);
    }

    else if(node->right!=NULL){
       cout<<node->data<<" ";
       printLeft(node->right);
    }

}

void printRight(struct node *node){

   if(node->right!=NULL){

      printRight(node->right);
      cout<<node->data<<" ";

   }

   else if(node->left!=NULL){
    
    printRight(node->left);
    cout<<node->data<<" ";

   }

}



int main() { 
  
   struct node *root=newnode(20);
   root->left=newnode(8);
   root->right=newnode(22);
   root->left->left=newnode(4);
   root->left->right=newnode(12);
   root->left->right->left=newnode(10);
   root->left->right->right=newnode(14);
   root->right->right=newnode(25);
   
   cout<<root->data<<" ";
   printLeft(root->left);
   printLeaves(root);
   printRight(root->right);
    

   return 0;

}

