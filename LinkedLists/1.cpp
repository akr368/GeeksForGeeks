#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

void traverse(struct node *node){

	while(node!=NULL){
		cout<<node->data<<" ";
		node=node->next;
	}


}


int main(){

	struct node *head=NULL;
	struct node *second=NULL;
	struct node *third=NULL;

	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=second;
	second->data=2;
	second->next=third;
	third->data=3;
	third->next=NULL;
	traverse(head);


    

    return 0;

}