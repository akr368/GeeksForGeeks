#include <iostream>

using namespace std;

void increment(struct node *,int);

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node* newnode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


void convertTree(struct node *node){

    int l_data=0;
    int r_data=0;
    int diff;
    
   
   if(node==NULL || (node->left==NULL && node->right==NULL))  
    return;
  

   else{



     convertTree(node->left);
     convertTree(node->right);
    // cout<<"111..."<<endl;

     if(node->left!=NULL)
      l_data=node->left->data;

     if(node->right!=NULL)
       r_data=node->right->data;

     diff=(l_data+r_data)-node->data;
     

     if(diff>0)
      node->data+=diff;
   

     if(diff<0)
       increment(node,-diff);
    

   }

}

void increment(struct node *node,int diff){


    if(node->left!=NULL){
       node->left->data+=diff;
       increment(node->left,diff);

    }

    else if(node->right!=NULL){
      node->right->data+=diff;
      increment(node->right,diff);
    }

}

void inorder(struct node *node){
   
   if(node!=NULL){
   inorder(node->left);
   cout<<node->data<<" ";
   inorder(node->right);
 }

}


int main() {

    struct node* root=newnode(50);
    root->left=newnode(7);
    root->right=newnode(2);
    root->left->left=newnode(3);
    root->left->right=newnode(5);
    root->right->left=newnode(1);
    root->right->right=newnode(30);
    inorder(root);
    cout<<endl;
    convertTree(root);
    inorder(root);

    
    return 0;

}

