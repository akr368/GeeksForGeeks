#include <iostream>

using namespace std;

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


bool checkSum(struct node *root,int sum){

    if(root==NULL)
      return (sum==0);

    else 

    {
      bool ans=0;
      int subsum=sum- root->data;

      if(subsum==0 && root->left==NULL && root->right==NULL)
        return 1;
      

      if(root->left)
        ans=ans||checkSum(root->left,subsum);
      if(root->right)
        ans=ans||checkSum(root->right,subsum);

      return ans;

    }
 
}



int main() { 

   struct node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);

    if(checkSum(root,14))
      cout<<"True."<<endl;
    else
      cout<<"False."<<endl;
 
    return 0;

}

