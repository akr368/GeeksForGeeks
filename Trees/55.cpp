#include <iostream>
#include <stack>

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


void postorder(struct node *node){
 
  if(node==NULL)
    return;

  stack<struct node *> s1;
  stack<struct node *> s2;
  s1.push(node);

  while(!s1.empty()){
    
     struct node *temp=s1.top();
     s1.pop();
     s2.push(temp);
     if(temp->left!=NULL)
      s1.push(temp->left);
     if(temp->right!=NULL)
      s1.push(temp->right);

  }  

  while(!s2.empty()){
    struct node *temp=s2.top();
    s2.pop();
    cout<<temp->data<<" ";
  }


}




int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(-10);
   root->right=newnode(11);
   root->left->right=newnode(5);
   root->left->right->right=newnode(3);
   root->right->left=newnode(13);
   root->right->right=newnode(16);
   postorder(root);
   
   return 0;

}

