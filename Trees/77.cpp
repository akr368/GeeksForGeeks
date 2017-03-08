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

struct node* lca(struct node *root,int n1,int n2){
   
     if(root==NULL)
      return NULL;

     if(root->data==n1 || root->data==n2)
      return root;

     struct node *left1=lca(root->left,n1,n2);
     struct node *right1=lca(root->right,n1,n2);

     if(left1 && right1)
     return root;

     return (left1!=NULL)?left1:right1; 

}



int main() { 
     
     struct node *root=newnode(1);
     root->left=newnode(2);
     root->right=newnode(6);
     root->left->left=newnode(8);
     root->left->right=newnode(4);
     root->right->right=newnode(5);
     struct node *ans=lca(root,8,5);
     if(ans)
     cout<<ans->data<<endl;
     
    
    
    
  
    return 0;

}