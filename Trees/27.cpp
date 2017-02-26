#include <iostream>

using namespace std;



struct node {
  int data;
  struct node *left;
  struct node *right;
};

int max(int a,int b){
  return (a>=b)?a:b;
}

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int height(struct node *node){

   if(node==NULL)
    return 0;
  else
    return 1 + max(height(node->left),height(node->right));

}

bool isbalanced(struct node *root){

  if(root==NULL)
    return true;

  int l_height=height(root->left);
  int r_height=height(root->right);

   if(abs(l_height-r_height)<=1 && isbalanced(root->left) && isbalanced(root->right))
     return true;

  return false;
   
}


int main() { 

   struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->left->left->left = newnode(8);
 
    if(isbalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced"); 


    return 0;

}

