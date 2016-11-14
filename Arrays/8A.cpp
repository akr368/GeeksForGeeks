#include <iostream>
using namespace std;

//The two given arrays sizes are of 'equal' sizes 'n'.


//This function returns the median of two sorted arrays of equal sizes after they're combined.
int findMedian(int a[],int b[],int n){

  
  int count;
  int i=0;
  int j=0;
  int m1;
  int m2;

  for(count=0;count<=n;count++){
     
       if((i<n && a[i]<=b[j])|| (j==n)){
       	m1=a[i];
       	i++;
       	cout<<"m1:"<<m1<<endl;
       }else{
       	m2=b[j];
       	j++;
       	cout<<"m2:"<<m2<<endl;
       }
  


  }

  return (m1+m2)/2;


}



int main(){

  int a[]={2,5,7,9,10,12};
  int b[]={1,3,6,9,11,13};
  
  int n=sizeof(b)/sizeof(b[0]);
  cout<<findMedian(a,b,n)<<endl;


}