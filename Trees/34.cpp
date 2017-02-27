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

void printK(struct node *root,int level,int k){
   

    if(root==NULL)
      return;


    if(level==k)
      cout<<root->data<<" ";

    else {
    
       printK(root->left,level+1,k);
       printK(root->right,level+1,k);
    }
}


int main() { 

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left=newnode(8);
    printK(root,0,2);
    

    return 0;

}

