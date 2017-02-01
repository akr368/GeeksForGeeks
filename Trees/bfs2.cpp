#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

void bfs(Node *root){

  if(root==NULL)
   return;

  queue<Node*> q;

  q.push(root);

  while(!q.empty()){
     
     Node *node=q.front();
     cout<<node->data;
     if(node->left!=NULL)
      q.push(node->left);
     if(node->right!=NULL)
      q.push(node->right);
     q.pop();

  }
}

struct Node* newnode(int data){

    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int main() { 

    struct Node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    bfs(root);
    return 0;

}

