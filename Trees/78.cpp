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

int findlevel(struct node *root,int level,int k){
   
   if(root==NULL)
    return 0;
   
   if(root->data==k)
    return level; 

   int l=findlevel(root->left,level+1,k);
   int r=0;
   
   if(l==0)
     r=findlevel(root->right,level+1,k);

   return (l!=0)?l:r; 

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
     int ans1=findlevel(root,0,2)+findlevel(root,0,4);

     int temp=0;
     struct node *lca_node=lca(root,2,4);
     temp=findlevel(root,0,lca_node->data);
     temp*=2;
     cout<<ans1-temp<<endl;
     


    return 0;

}