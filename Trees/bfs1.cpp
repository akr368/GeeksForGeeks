#include <iostream>

using namespace std;

int height(struct node *node); 
void printNodesInLevel(struct node * node,int level);

struct node{
  int data;
  struct node *left;
  struct node *right;
};


int max(int a,int b){
   if(a>b)
    return a;
   else
    return b;
}

struct node* newnode(int data){

    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;

}

void goToLevel(struct node *node){
  
  int h=height(node);
  int i;
  for(i=1;i<=h;i++){
      printNodesInLevel(node,i);
  }
}

void printNodesInLevel(struct node * node,int level){

     if(node==NULL)
      return;
     if(level==1)
       cout<<node->data<<" ";
     else if(level>1){
         printNodesInLevel(node->left,level-1);
         printNodesInLevel(node->right,level-1);
     }
}

int height(struct node *node){
   
   if(node==NULL)
    return 0;

   int lheight=height(node->left);
   int rheight=height(node->right);
   return 1+ max(lheight,rheight);

}

int main() { 

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    goToLevel(root);
    
    return 0;

}

