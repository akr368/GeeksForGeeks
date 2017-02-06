#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

int max(int a,int b) {
  if(a>b)
    return a;
  else 
    return b;
}

struct node* newnode(int data){

    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


int size(struct node *node){
   
   if(node==NULL)
    return 0;

   return 1+max(size(node->left),size(node->right));

}


int main() { 

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->left->left=newnode(10);

    root->left->left->left->left=newnode(12);
    root->left->right=newnode(5);
    cout<<size(root)<<endl;

    return 0;

}

