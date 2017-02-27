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


int getLevel(struct node *root,int level,int key){
   
    if(root==NULL)
      return 0;
    
    if(root->data==key)
      return level;

       int ans=getLevel(root->left,level+1,key);

       if(ans!=0)
        return ans;
       ans= getLevel(root->right,level+1,key);

       return ans;

}


int main() { 

    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left=newnode(8);
    cout<<getLevel(root,1,81)<<endl;
    

    return 0;

}

