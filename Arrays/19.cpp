#include <iostream>
#include <cmath>

using namespace std;

int binarySearch(int [],int,int,int);

int isMajority(int a[],int n,int x){
  
  int index=binarySearch(a,0,n-1,x);
  if((index+n/2)<=n-1 && a[index+n/2]==x)
    return 1;
  else
    return 0;
}

int binarySearch(int a[],int low,int high,int x){

   int mid=(low)-(low-high)/2;
   if((mid==0 || a[mid-1]<x ) && a[mid]==x)
      return mid;
   if(x>a[mid])
    return binarySearch(a,mid+1,high,x);
   else
    return binarySearch(a,0,mid-1,x);

}


int main(){

	int a[]={3, 3, 3, 3, 13, 13, 10};
	int n=sizeof(a)/sizeof(a[0]);
  int x=3;
	if(isMajority(a,n,x))
    cout<<"Yes."<<endl;
  else
    cout<<"No."<<endl;
	
 return 0;
}