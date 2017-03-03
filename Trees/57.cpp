#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void inorder(struct node *);

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


void reverse(struct node *node){
 
  if(node==NULL)
    return;

  stack<struct node *> s;
  queue<struct node *> q;
  q.push(node);
  

  while(!q.empty()){

      struct node *temp=q.front();
      q.pop();
      s.push(temp);

      if(temp->right!=NULL)
          q.push(temp->right);
      
      if(temp->left!=NULL)
          q.push(temp->left);
      
  }

  while(!s.empty()){

     cout<<s.top()->data<<" ";
     s.pop();

  } 


}




int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   reverse(root);
   
   return 0;

}

