#include <iostream>

using namespace std;

int height(struct node *node);
void printLevelNodes(struct node *node,int level,int flag);

struct node{
  int data;
  struct node *left;
  struct node *right;
};

int max(int a,int b){
  if(a>b)
    return a;
  else
    return b;
}


struct node* newnode(int data) {
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void goToEachLevel(struct node *node){

  int i;
  int h=height(node);
  int flag=1;
  for(i=1;i<=h;i++){
     printLevelNodes(node,i,flag);
     cout<<endl;
     flag=~flag;
  }
}

void printLevelNodes(struct node *node,int level,int flag){
     
     if(node==NULL)
      return;
     else if(level==1)
        cout<<node->data<<" ";
     
     else if(flag){
        printLevelNodes(node->left,level--,flag);
        printLevelNodes(node->right,level--,flag);
     }
     else{
         printLevelNodes(node->right,level--,flag);
         printLevelNodes(node->left,level--,flag);
     }

}


int height(struct node *node) {

    if(node==NULL)
      return 0;
    return 1+ max(height(node->left),height(node->right));
}

int main() {

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    goToEachLevel(root);
    cout<<"-----"<<endl;
    return 0;

}


