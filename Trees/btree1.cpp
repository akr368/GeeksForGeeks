#include <iostream>

using namespace std;

struct node{
   int data;
   struct node *left;
   struct node *right;
};

struct node* newnode(int data){

    struct node* node= (struct node*) malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;

}

int main(){

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

    return 0;

}