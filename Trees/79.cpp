#include <iostream>
#define MAX_HEIGHT 100000

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


void print(struct node *node,int path[],int k,bool visited[],int pathlength){

   if(node==NULL)
    return;

  path[pathlength]=node->data;
  visited[pathlength]=true;
  pathlength++;

  if(node->left==NULL && node->right==NULL && visited[pathlength-k-1]){
     cout<<path[pathlength-k-1]<<" ";
     visited[pathlength-k-1]=false;
     return;
  }

  print(node->left,path,k,visited,pathlength);
  print(node->right,path,k,visited,pathlength);

}


int main() { 
     
     struct node *root=newnode(1);
     root->left=newnode(2);
     root->right=newnode(3);
     root->left->left=newnode(4);
     root->left->right=newnode(5);
     root->right->left=newnode(6);
     root->right->left->right=newnode(8);
     root->right->right=newnode(7);

     bool visited[MAX_HEIGHT]={false};
     int path[MAX_HEIGHT];
     print(root,path,2,visited,0);

     return 0;

}