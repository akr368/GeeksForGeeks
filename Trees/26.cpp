#include <iostream>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

int max(int a,int b){
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


int height(struct node *node){

  if(node==NULL)
    return 0;
  return 1+ height(node->left)+ height(node->right));

}


void diameter(struct node *node){


}




int main() { 

    struct node* root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(5);
    root->left->left=newnode(2);
    root->left->right=newnode(3);
    cout<<diameter(root)<<endl;


    return 0;

}

