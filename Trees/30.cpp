#include <iostream>

using namespace std;
void print(int [],int );
int path[1000];


struct node {
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

void printPaths(struct node *node,int path[],int pathlength){
   
   if(node==NULL)
    return;


  path[pathlength++]=node->data;

   if(node->left==NULL && node->right==NULL)
    print(path,pathlength);
   
   else{

       printPaths(node->left,path,pathlength);
       printPaths(node->right,path,pathlength);
   }

}


void print(int path[],int l){
  
  for(int i=0;i<l;i++)
    cout<<path[i]<<" ";
  cout<<endl;

}



int main() { 

   struct node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
    printPaths(root,path,0);

    
    return 0;

}

