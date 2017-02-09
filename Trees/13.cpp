#include <iostream>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
  bool rightThread;
};

struct node* newnode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


struct node* leftMost(struct node *node){

  if(node==NULL)
    return NULL;

   while(node->left!=NULL)
    node=node->left;

  return node;

}


void inorder(struct node *node){

    struct node *cur=leftMost(node);

    while(cur!=NULL){

        cout<<cur->data<<" ";
        if(cur->rightThread)
          cur=cur->right;
        else
          cur=leftMost(cur->right);

    }

}


int main() {

    struct node* root=newnode(2);
    root->left=newnode(1);
    root->right=newnode(3);
    root->left->left=newnode(0);
    root->left->right=root;
    root->left->rightThread=true;
    root->left->left->right=root->left;
    
    root->left->left->rightThread=true;
    inorder(root);


   
   
    return 0;

}

