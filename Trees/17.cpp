#include <iostream>
#include <stack>

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

void deleteTree(struct node *temp){

   if(temp==NULL)
    return;

   deleteTree(temp->left);
   deleteTree(temp->right);
   cout<<"Delete: "<<temp->data<<endl;
   free(temp);

}

void callDelete(struct node **root){

     deleteTree(*root);
     *root=NULL;

}


int main() { 

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    callDelete(&root);
    if(root==NULL)
      cout<<"Root is NULL";
   
    return 0;

}

