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


int check(struct node* node) {
   
    if (node==NULL || (node->left==NULL && node->right==NULL))
      return 1;

    else {

    int l_value=0;
    int r_value=0;

    if(node->left!=NULL)
       l_value=node->left->data;
    if(node->right!=NULL)
       r_value=node->right->data;

    return (node->data==l_value+r_value) && check(node->left) 
             && check(node->right);   
    }
}


int main() { 

    struct node* root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(5);
    root->left->left=newnode(2);
    root->left->right=newnode(3);
    cout<<check(root)<<endl;


    return 0;

}

