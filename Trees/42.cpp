#include <iostream>
using namespace std;
void preorder(struct node *);

struct node{
  int data;
  struct node *left;
  struct node *right;
  struct node *next;
};

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


int convertSumTree(struct node *node){

    if(node==NULL)
      return 0;

    int old_val=node->data;

    node->data=convertSumTree(node->left)+convertSumTree(node->right);

    return old_val+node->data;


}


void inorder(struct node *root){

   if(root){
     
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);

   }

}

int main() { 

   struct node *root;
  root = newnode(10);
  root->left = newnode(-2);
  root->right = newnode(6);
  root->left->left = newnode(8);
  root->left->right = newnode(-4);
  root->right->left = newnode(7);
  root->right->right = newnode(5);
  inorder(root);
  cout<<endl;
  convertSumTree(root);
  inorder(root);
  cout<<endl;


 

    return 0;

}

