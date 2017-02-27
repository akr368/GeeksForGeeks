#include <iostream>
using namespace std;

int height(struct node *);
int getMax(int a[],int);
void preorder(struct node *,int a[],int);
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

int width(struct node *root){

    if(root==NULL)
      return 0;

    int h=height(root);
    int *count = (int *)calloc(sizeof(int),h);
    int level=0;
    preorder(root,count,level);

    return getMax(count,h);

}

void preorder(struct node *root,int count[],int level){

   if(root){
    count[level]++;
    preorder(root->left,count,level++);
    preorder(root->right,count,level++);
   }
}

int getMax(int count[],int h){

   int max=count[0];
   for(int i=1;i<h;i++){
    if(count[i]>max)
       max=count[i];
   }
   return max;
}


int height(struct node *root){
  
  if(root==NULL)
    return 0;
  else
    return 1+max(height(root->left),height(root->right));

}



void inorder(struct node *node){
   
   if(node==NULL)
    return;
   inorder(node->left);
   cout<<node->data<<" ";
   inorder(node->right);

}


int main() { 

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->right=newnode(8);
    root->right->right->left=newnode(6);
    root->right->right->right=newnode(7);
    cout<<width(root)<<endl;

    return 0;

}

