#include <iostream>
#include <queue>

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


void height(struct node *node){
    
    if(node==NULL)
      return;

    queue<struct node *> q;
    q.push(node);
    
    int height=0;
    
    while(!q.empty()){
        
        int count=q.size();
        if(count==0)
          break;

         height++; 

        while(count){
            struct node *temp=q.front();
            q.pop();
            if(temp->left!=NULL)
              q.push(temp->left);
            if(temp->right!=NULL)
              q.push(temp->right);
            count--;
        }
        
        

    }

    cout<<height<<endl;


}



int main() { 
  
   struct node *root=newnode(1);
   root->left=newnode(2);
   root->right=newnode(3);
   root->left->left=newnode(4);
   root->left->right=newnode(5);
   height(root);
 
    return 0;

}