#include <iostream>

using namespace std;
void reverseArray(int [],int,int);
void printArray(int [],int);

void rotate(int a[],int n,int d){

   reverseArray(a,0,d-1);
   reverseArray(a,d,n-1);
   reverseArray(a,0,n-1);
}


void reverseArray(int a[],int start,int end){

    int temp;
    while(start<end){
      temp=a[start];
      a[start]=a[end];
      a[end]=temp;
      start++;
      end--;
    }

}

void printArray(int a[],int n){

   for(int i=0;i<n;i++)
      cout<<a[i]<<" ";

  cout<<endl;

}

int main(){

	int a[]={1,2,3,4,5,6,7};
	int d=2;
	int n=sizeof(a)/sizeof(a[0]);

	rotate(a,n,d);
   printArray(a,n);
	



}