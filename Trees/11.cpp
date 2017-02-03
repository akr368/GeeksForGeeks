#include <iostream>
#include <stack>

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

void inorder(struct node *temp){
  
    stack<struct node*> s;
    struct node *curr=temp;
    struct node *temp2;
    
    while(curr!=NULL || !s.empty()){
      
        if(curr){

           while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
           }
        }

        else{

          temp2=s.top();
          cout<<temp2->data<<" ";
          s.pop();
          curr=temp2->right;


        }

    }


}


int main() { 

    struct node* root=newnode(1);
    
    root->right=newnode(2);
    
    root->right->right=newnode(4);
    inorder(root);


    return 0;

}

