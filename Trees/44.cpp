#include <iostream>
#include <limits>

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

int printPath(struct node *root,struct node *target){

    if(root==NULL)
      return 0;

    if(root->data==target->data || printPath(root->left,target) || 
      printPath(root->right,target)) {
      cout<<root->data<<" ";
      return 1;
    }

    return 0;
}


void findTarget(struct node *root,int *maxSum,int curr_sum,struct node **target_leaf){
  
    if(root==NULL)
      return;

    curr_sum+=root->data;

    if(root->left==NULL && root->right==NULL){

          if(curr_sum>*maxSum){
            *maxSum=curr_sum;
            *target_leaf=root;
           
          }    
    }

    findTarget(root->left,maxSum,curr_sum,target_leaf);
    
    findTarget(root->right,maxSum,curr_sum,target_leaf);

}


int findSum(struct node *root){
     
      if(root==NULL)
        return 0;

      int maxsum=INT_MIN;
      struct node *target_leaf;
      findTarget(root,&maxsum,0,&target_leaf);
      printPath(root,target_leaf); 
      return maxsum;

}



int main() { 

  struct node *root;
  root = newnode(12);
  root->left = newnode(-2);
  root->right = newnode(17);
  root->left->left = newnode(8);
  root->left->right = newnode(-4);
  int sum=findSum(root); 
  cout<<endl;
  cout<<"Max Sum:"<<sum<<endl;

   return 0;

}

