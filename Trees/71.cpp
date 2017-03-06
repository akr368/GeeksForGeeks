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


struct node* truncate(struct node *node,int sum){

   if(node==NULL)
    return NULL;
   
   node->left=truncate(node->left,sum-node->data);
   node->right=truncate(node->right,sum-node->data);

   if(node->left==NULL && node->right==NULL){
     
      if(node->data<sum){
        free(node);
        return NULL;
      }

   }

   return node;

}


void inorder(struct node *root){
  
  if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }

}


int main() { 
  
    struct node* root = newnode(12);
    root->left = newnode(10);
    root->right = newnode(30);
    root->right->left = newnode(25);
    root->right->right = newnode(40);
    root=truncate(root,30);
    inorder(root);


 
    return 0;

}