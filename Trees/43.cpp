#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


struct node{
  int data;
  struct node *left;
  struct node *right;
};

map<int,int> m;

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void sum(struct node *node,int level,int broad){

   if(!node)
    return;

   m[broad]+=node->data;
   sum(node->left,level+1,broad-1);
   sum(node->right,level+1,broad+1);
    
}


int main() { 

  struct node *root;
  root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->right->left = newnode(6);
  root->right->right = newnode(7);
   sum(root,0,0);
   for(map<int,int>::iterator it=m.begin(); it!=m.end();it++)
    cout<<it->second<<endl;

   return 0;

}

