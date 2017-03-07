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


int calculate(struct node *node,int val){

    if(node==NULL)
      return 0;

     val=val*10+node->data;

    if(node->left==NULL && node->right==NULL)
      return val;

    return calculate(node->left,val) + calculate(node->right,val);

}


int main() { 
     
     struct node *root=newnode(1);
     root->left=newnode(2);
     root->right=newnode(6);
     root->left->left=newnode(8);
     root->left->right=newnode(4);
     root->right->right=newnode(5);
     cout<<calculate(root,0)<<endl;
    
    
    
  
    return 0;

}