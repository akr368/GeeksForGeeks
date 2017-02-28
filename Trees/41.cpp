#include <iostream>
using namespace std;
void preorder(struct node *);

struct node{
  int data;
  struct node *left;
  struct node *right;
  struct node *next;
};

struct node* newnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}


//Point to Inorder Successor.

void populateNext(struct node *p){

   static struct node *temp=NULL;

    if(p){
      
       populateNext(p->right);
       p->next=temp;
       temp=p;
       populateNext(p->left);

 


    }



}




int main() { 

   struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
 
 
  populateNext(root);
  cout<<root->next->data<<endl;
  cout<<root->left->next->data<<endl;
  
  cout<<root->left->left->next->data<<endl;

 

    return 0;

}

