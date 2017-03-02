#include <iostream>
#include <stack>

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

void morris(struct node *root){

     
    while(root){

       if(root->left==NULL){
          cout<<root->data<<" ";
          root=root->right;
       }

       else{

          struct node *curr=root->left;
          while(curr->right!=NULL && curr->right!=root)
            curr=curr->right;

          if(curr->right==root){
            curr->right=NULL;
            root=root->right;
          }
          else{
            cout<<root->data<<" ";
            curr->right=root;
            root=root->left;
          }

       }


    }



}


int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   morris(root);
   

   return 0;

}

