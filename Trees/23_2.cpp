#include <iostream>
#include <queue>

using namespace std;

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

void levelOrder(struct node *node){
  
  queue<struct node *> q;
  struct node *temp;
  
  if(node!=NULL)
    q.push(node);
  
  while(!q.empty()){

    int n_nodes=q.size();

   while(n_nodes--){
    temp=q.front();
    cout<<temp->data<<" ";
    if(temp->left!=NULL)
      q.push(temp->left);
    if(temp->right!=NULL)
      q.push(temp->right);
    q.pop();

   }

   cout<<endl;

  }
}

int main() {

    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    levelOrder(root);
    
    return 0;

}


