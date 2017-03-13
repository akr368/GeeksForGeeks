#include <iostream>
using namespace std;

/*
Algo-
1. Find the element that repeats most number of time.
2. Check if the above element is a majority element

*/

void isMajority(int a[],int x,int n);

void findFrequentElement(int a[],int n){
 
 int count=0;
 int i;
 int max;
 for(i=0;i<n;i++){
 	if(count==0){
 		max=a[i];
    count=1;
 	}
    if(max==a[i]){
    	count++;
    }else{
    	count--;
    }

 }

cout<<max;

//isMajority(a,max,n);

}

void isMajority(int a[],int x,int n){
  
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
   

   int a[]={3,3,4,2,2,2,2,2};
   int n=sizeof(a)/sizeof(a[0]);
   findFrequentElement(a,n);
   


    return 0;

}