#include <iostream>
#include <stack>

using namespace std;

int pathlength=0;

int i=0;

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

void printPath(struct node *node,int path[],int pathlength){
    
     if(node==NULL)
       return;

       path[pathlength]=node->data;
       pathlength++;
     

     if(node->left==NULL && node->right==NULL){
        for(i=0;i<pathlength;i++)
          cout<<path[i]<<" ";
        cout<<endl;
     }

     printPath(node->left,path,pathlength);
     printPath(node->right,path,pathlength);
}

int main() {

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    int path[1000];
    printPath(root,path,pathlength);
  
   
    return 0;

}

