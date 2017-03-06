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


void findDeep(struct node *node,int level,int *maxLevel,bool isLeft,struct node **ans){
    
    
    if(node==NULL)
      return;

    if(node->left==NULL && node->right==NULL && isLeft){
      if(level>*maxLevel){
        *maxLevel=level;
        *ans=node;
       
        return;
      }
    }

    findDeep(node->left,level+1,maxLevel,true,ans);
    findDeep(node->right,level+1,maxLevel,false,ans);

}


int main() { 
  
    struct node* root = newnode(1);
    root->left = newnode(2);
    
    root->left->left=newnode(4);
    root->right = newnode(3);
    root->right->left = newnode(5);
    root->right->right = newnode(6);
    root->right->left->right = newnode(7);
    root->right->left->right->left = newnode(9);
    root->right->left->right->left->left = newnode(19);
    root->right->right->right=newnode(8);
    root->right->right->right->right=newnode(10);
    int maxLevel=0;
    struct node *ans=NULL;
    findDeep(root,1,&maxLevel,true,&ans);
    cout<<ans->data<<endl;
  
    return 0;

}