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


void printLeft(struct node *node,int level,int *maxLevel){

    if(node==NULL)
      return;

    if(*maxLevel<level){
      *maxLevel=level;
      cout<<node->data<<" ";
    }

    printLeft(node->left,level+1,maxLevel);
    printLeft(node->right,level+1,maxLevel);

}

int main() { 
  
    struct node* root = newnode(12);
    root->left = newnode(10);
    root->right = newnode(30);
    root->right->left = newnode(25);
    root->right->right = newnode(40);
    int maxLevel=0;
    printLeft(root,1,&maxLevel);
  

 
    return 0;

}