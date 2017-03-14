#include <iostream>
using namespace std;

void leftRotate(int [],int,int);
void leftRotatebyOne(int [],int,int);

void leftRotate(int a[],int n,int d){

   for(int i=0;i<d;i++)
   	leftRotatebyOne(a,n,d);

}

void leftRotatebyOne(int a[],int n,int d){
   
    int temp=a[0];
    int i;
    for(i=0;i<n;i++)
     a[i]=a[i+1];
     a[i-1]=temp;   
}

void printArray(int a[],int n){

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}

int main(){
	int a[]={1,2,3,4,5,6,7,8};
	int d=2;
	int n=sizeof(a)/sizeof(a[0]);
	leftRotate(a,n,d);
	printArray(a,n);
	

}