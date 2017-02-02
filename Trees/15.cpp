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

int check(struct node *node1,struct node *node2){
   
   if(node1==NULL && node2==NULL)
     return 1;

   else if(node1!=NULL && node2!=NULL)
    {
      return node1->data==node2->data && check(node1->left,node2->left)
             && check(node1->right,node2->right);


    }

    return 0;

   }




int main() { 

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);

    struct node* root2=newnode(1);
    root2->left=newnode(2);
    root2->right=newnode(3);
    root2->left->right=newnode(5);

    if(check(root,root2))
      cout<<"Identical";
    else
      cout<<"Not Identical";
    
    
    return 0;

}

