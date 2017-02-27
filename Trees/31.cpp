#include <iostream>
using namespace std;

struct node {
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

void doubleTree(struct node *node){
   
   if(node==NULL)
    return;

   doubleTree(node->left);
   doubleTree(node->right);
   struct node *temp=node->left;
   node->left=newnode(node->data);
   node->left->left=temp;

}

void inorder(struct node *node){
   
   if(node==NULL)
    return;
   inorder(node->left);
   cout<<node->data<<" ";
   inorder(node->right);

}


int main() { 

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    inorder(root);
    cout<<endl;
    doubleTree(root);
    inorder(root);


    return 0;

}

