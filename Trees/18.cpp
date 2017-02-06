#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *temp;

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


void mirror(struct node *node){
   
   if(node==NULL)
    return ;
   
   else{ 

    struct node *temp;
    mirror(node->left);
    mirror(node->right);
    temp=node->left;
    node->left=node->right;
    node->right=temp;
    
    }
}

void inorder(struct node *node){

  if(node==NULL)
    return;
  inorder(node->left);
  cout<<node->data;
  inorder(node->right);
}


int main() { 

    struct node* root=newnode(1);
    root->left=newnode(3);
    root->right=newnode(2);
    root->right->left=newnode(5);
    root->right->right=newnode(4);
    inorder(root);
    cout<<endl;
    mirror(root);
    inorder(root);
    cout<<endl;

    return 0;

}

