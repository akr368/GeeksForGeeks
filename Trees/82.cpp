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


void findMinMax(struct node *node,int *min,int *max,int h){

    if(node==NULL)
       return;

    if(h<*min)
     *min=h;
    else if(h>*max)
     *max=h;

    findMinMax(node->left,min,max,h-1);
    findMinMax(node->right,min,max,h+1);

}

void print(struct node *node,int level,int node_level){

    if(node==NULL)
        return;

    if(level==node_level)
     cout<<node->data<<" ";

   print(node->left,level-1,node_level);
   print(node->right,level+1,node_level);

}

void printVertical(struct node *node){

    int min=0;
    int max=0;
    findMinMax(node,&min,&max,0);
    
    for(int i=min;i<=max;i++)
     {   print(node,0,i);
        cout<<endl;
     }

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
     root->right->right->right=newnode(9);
     printVertical(root);


     return 0;

}