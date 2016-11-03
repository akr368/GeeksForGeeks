#include <iostream>
using namespace std;

/*
Algo-
1. Find the element that repeats most number of time.
2. Check if the above element is a majority element

*/

void findFrequentElement(int a[],int n){
 
 int count=0;
 int i;
 int max;
 for(i=0;i<n;i++){
 	if(count==0){
 		max=a[i];
 	}
    if(max==a[i]){
    	count++;
    }else{
    	count--;
    }

 }

B(a,max,n);

}

void B(int a[],int x,int n){
  
  int i;
  int count=0;
  for(i=0;i<n;i++){
     if(a[i]==x){
     	count++;
     	if(count>n/2){
     		cout<<"Majority element:"<<a[i]<<endl;
     		return;
     	}
     }
  }

  cout<<"Majority Element doesn't exists.";

}


int main() {
   

   int a[]={2,2,3,3,3,4,3};
   int n=sizeof(a)/sizeof(a[0]);
   findFrequentElement(a,n);
   


    return 0;

}