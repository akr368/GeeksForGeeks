#include <iostream>
#include <queue>

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


bool isCompleteBT(struct node *root){

   if(root==NULL)
    return true;
  

   queue<struct node *> q;
   q.push(root);
   bool flag=false;

   while(!q.empty()){

     struct node *temp=q.front();
     
     q.pop();

     if(temp->left!=NULL){
       if(flag)
        return false;
        q.push(temp->left);
     }
     else
      flag=true;

    if(temp->right!=NULL){
       if(flag)
        return false;
      q.push(temp->right);
    }
    else
      flag=true;
   }

   return true;

} 



int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   root->right->right=newnode(6);
  
    if(isCompleteBT(root))
      cout<<"Yes."<<endl;
    else
      cout<<"No."<<endl;
   
   

   return 0;

}

