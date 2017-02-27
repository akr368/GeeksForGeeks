#include <iostream>
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

int calculateSum(struct node *root){
  
  if(root==NULL)
    return 0;

  return root->data + calculateSum(root->left)+calculateSum(root->right);

}

bool isSumTree(struct node *root){

   if(root==NULL || (root->left==NULL && root->right==NULL))
    return true;

   if((root->data==calculateSum(root->left)+calculateSum(root->right)
      && isSumTree(root->left) && isSumTree(root->right) ))
    return true;

   return false; 

}

int main() { 

    struct node *root = newnode(26);
    root->left = newnode(6);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(10);
    root->right->right=newnode(3);
    cout<<isSumTree(root)<<endl;

    return 0;

}

