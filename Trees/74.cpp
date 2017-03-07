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


struct node* nextRight(struct node *root,int k){
  
   if(root==NULL)
    return NULL;

   queue<struct node *> qn;
   queue<int> ql;

   int level=1;
   qn.push(root);
   ql.push(level);

   while(!qn.empty()){
      
       struct node *temp=qn.front();
       qn.pop();
       int level=ql.front();
       ql.pop();

       if(temp->data==k){
          if(ql.front()!=level)
            return NULL;
          return qn.front();
       }

       if(temp->left)
       {
         qn.push(temp->left);
         ql.push(level+1);
       }

       if(temp->right){
        qn.push(temp->right);
        ql.push(level+1);
       }

   }

   return NULL;

}


int main() { 
     
     struct node *root=newnode(10);
     root->left=newnode(2);
     root->right=newnode(6);
     root->left->left=newnode(8);
     root->left->right=newnode(4);
     root->right->right=newnode(5);
     struct node *ans=nextRight(root,4);
     if(ans)
        cout<<ans->data<<endl;
    
  
    return 0;

}