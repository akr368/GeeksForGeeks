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


bool getAncestors(struct node *root,int key){
  
   if(root==NULL)
    return false;

   if(root->data==key)
    return true;

   if(getAncestors(root->left,key) || getAncestors(root->right,key))
    {
      cout<<root->data<<" ";
      return true;
    }

   return false;
    

}


int main() { 

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left=newnode(8);
    root->right->left->left=newnode(10);
    getAncestors(root,10);
    

    return 0;

}

