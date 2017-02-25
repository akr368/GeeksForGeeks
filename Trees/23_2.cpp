#include <iostream>
#include <stack>

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

void levelOrder(struct node *root){

   if(root==NULL)
    return;

   stack <struct node*> s1;
   stack <struct node*> s2;

   s1.push(root);
   
   while(!s1.empty() || !s2.empty()){

       while(!s1.empty()){

           struct node *temp=s1.top();
           cout<<temp->data<<" ";
           s1.pop();
           if(temp->right)
            s2.push(temp->right);
           if(temp->left)
            s2.push(temp->left);
       }

       while(!s2.empty()){
          
           struct node *temp=s2.top();
          cout<<temp->data<<" ";
          s2.pop();
          if(temp->left)
            s1.push(temp->left);
          if(temp->right)
            s1.push(temp->right);

       }
   }
}


int main() {

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    levelOrder(root);
    
    return 0;

}


