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


void preorder(struct node *node){
   
   if(node==NULL)
    return;

   stack<struct node *> s;
   s.push(node);

   while(!s.empty()){
      
      struct node *temp=s.top();
      s.pop();
      cout<<temp->data<<" ";
      if(temp->right!=NULL)
        s.push(temp->right); 
      if(temp->left!=NULL)
       s.push(temp->left);
        
   }

}


int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   preorder(root);
   

   return 0;

}

