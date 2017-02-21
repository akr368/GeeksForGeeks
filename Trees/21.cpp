#include <iostream>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* newnode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int countLeaf(struct node *temp){

   if(temp==NULL)
    return 0;

   if(temp->left==NULL && temp->right==NULL)
    return 1;

   return countLeaf(temp->left)+countLeaf(temp->right);

}


int main() {

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    cout<<countLeaf(root)<<endl;
   
    return 0;

}

