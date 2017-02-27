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


bool isIdentical(struct node *a,struct node *b){
    
    if(a==NULL && b==NULL)
      return true;

    if(a==NULL || b==NULL)
      return false;

    return (a->data==b->data && isIdentical(a->left,b->left) && 
      isIdentical(a->right,b->right));

}


bool isSubTree(struct node *T,struct node *S){
  
    if(S==NULL)
      return true;

    if(T==NULL)
      return false;

    return isIdentical(T,S) || isIdentical(T->left,S) || isIdentical(T->right,S);
     

}



int main() { 

    struct node *T = newnode(26);
    T->left = newnode(10);
    T->right = newnode(3);
    T->left->left = newnode(4);
    T->left->right = newnode(6);
    T->left->left->right=newnode(30);
    T->right->right=newnode(3);

    struct node *S=newnode(10);
    S->right=newnode(6);
    S->left=newnode(4);
    S->left->right=newnode(30);

     if(isSubTree(T,S))
        cout<<"YES."<<endl;
     else
        cout<<"NO"<<endl;    

    return 0;

}

