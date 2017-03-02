#include <iostream>
#include <queue>

using namespace std;


queue<struct node *> q1;
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

void insert(struct node **root,int data,queue<struct node*> &q){
   
   struct node *curr=newnode(data);

   if(*root==NULL)
     *root=curr;

   else {

    struct node *temp=q.front();
    

    if(temp->left==NULL)
      temp->left=curr;

    else if(temp->right==NULL)
      temp->right=curr;

    if(temp->left!=NULL && temp->right!=NULL)
      q.pop();

   }
   
   q.push(curr);
    
}

void printLevel(struct node *root){

  if(root==NULL)
    return;

  queue<struct node *> q1;
  q1.push(root);

  while(!q1.empty()){
   
    struct node *temp=q1.front();
    q1.pop();
    cout<<temp->data<<" ";

    if(temp->left!=NULL)
      q1.push(temp->left);
    if(temp->right!=NULL)
      q1.push(temp->right);

  }                                           

}



int main() { 
  
   struct node *root;
   queue<struct node *> q;

   for(int i=1;i<=5;i++)
    insert(&root,i,q);
   
   printLevel(root);



   return 0;

}

