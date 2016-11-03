#include <iostream>
using namespace std;


void findMajority(int a[],int n) {
 
  int i,j;
  i=j=0;
  int count=0;
  
  for(i=0;i<n;i++){
  	for(j=0;j<n;j++){
 		if(a[j]==a[i]){
  			count++;
  			if(count>n/2){
  		       cout<<"Element:"<<a[j]<<endl;
  		       return;
  	      }
  		}
  	  }
   	count=0;
  	}
}

int main() {

   int a[]={2,2,2,3,4,5,3,3,3,3,3,3};
   int n=sizeof(a)/sizeof(a[0]);
   findMajority(a,n);
   return 0;

}