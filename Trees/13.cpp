#include <iostream>

using namespace std;

struct node{
  int data;
  struct node *left;
  struct node *right;
  bool rightThread;
};

void morris(struct node *node);

struct node* newnode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void morris(struct node *node){
   
   if(node==NULL)
    return;

   struct node *curr,*pre;
   curr=node;

   while(curr!=NULL){
      
       if(curr->left==NULL){
        cout<<curr->data<<" ";
        curr=curr->right;
       }

       else {

        pre=curr->left;
        while(pre->right!=NULL && pre->right!=curr){
          pre=pre->right;
        }

        if(pre->right==NULL){
          pre->right=curr;
          curr=curr->left;
        }

        else{
          
          pre->right=NULL;
          cout<<curr->data<<" ";
          curr=curr->right;

        }




       }
   }
}


int main() {

    struct node* root=newnode(2);
    root->left=newnode(1);
    root->right=newnode(3);
    root->left->left=newnode(5);
    root->left->right=newnode(6);
    
    morris(root);

    return 0;

}

