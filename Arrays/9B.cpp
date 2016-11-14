#include <iostream>
using namespace std;

void reverse(int a[],int start,int end){
  
  if(start>=end){
    return;
  }

  int temp;
  if(start<=end){
    temp=a[start];
    a[start]=a[end];
    a[end]=temp;
  }

  reverse(a,start+1,end-1);

}

void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i];

	}
	cout<<endl;
}


int main(){

  
     int a[]={1,2,3,4,5,6,7};
     int n=sizeof(a)/sizeof(a[0]);
     print(a,n);
     reverse(a,0,n-1);
     print(a,n);




}