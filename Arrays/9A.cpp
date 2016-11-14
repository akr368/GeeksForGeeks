#include <iostream>
using namespace std;

void reverse(int a[],int n){
  
  int l=0;
  int r=n-1;
  int temp;
  while(l<r){
     temp=a[l];
     a[l]=a[r];
     a[r]=temp;
     l++;
     r--;
  }


}

void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i];

	}
	cout<<endl;
}


int main(){

  
     int a[]={1,2,3,4,5,6};
     int n=sizeof(a)/sizeof(a[0]);
     print(a,n);
     reverse(a,n);
     print(a,n);




}