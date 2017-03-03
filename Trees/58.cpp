#include <iostream>

#include <queue>

using namespace std;
void inorder(struct node *);

struct ListNode{
  int data;
  ListNode* next;
};

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

struct ListNode* push(ListNode **head_ref,int new_data){
   
   struct ListNode *newnode=(struct ListNode *)malloc(sizeof(struct ListNode));
   newnode->data=new_data;
   newnode->next=*head_ref;
   *head_ref=newnode;
   return newnode;
}

struct node * convertToTree(struct ListNode* head,struct node **root_tree){
   
   struct node *root=*root_tree;

   if(head==NULL){
    root=NULL;
    return NULL;
   }

   queue<struct node *> q;
   root=newnode(head->data);
   q.push(root);
   head=head->next;

   while(head){
     

      struct node *parent=q.front();
    
      
      q.pop();
      parent->left=newnode(head->data);
      q.push(parent->left);
      head=head->next;


      if(head)
      {
        
        parent->right=newnode(head->data);
        q.push(parent->right);
        head=head->next;
      }

   }
  
  return root;
 
}

void inorder(struct node *root){

  if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
  }
}


int main() { 
  
   
   struct ListNode* head=NULL;
   push(&head,36);
   push(&head,30);
   push(&head,25);
   push(&head,15);
   push(&head,12);
   push(&head,10);
   struct node *root;
   struct node *root2=convertToTree(head,&root);
   inorder(root2);
   




   
   return 0;

}

