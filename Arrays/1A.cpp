#include <iostream>
using namespace std;


void findPairs(int a[],int n,int sum){
	 
   
   int i,j;
   for(i=0;i<n-1;i++){
   	 for(j=i+1;j<n;j++){
   	 	
   	 	if(a[i]+a[j]==sum){
   	 		
   	 		cout<<"Pairs:"<<a[i]<<"+"<<a[j]<<"="<<sum<<endl;
   	 		return;
   	 	}

   	 }
   }
}


int main(){

 int a[]={1,2,3,4,10};
 int n=sizeof(a)/sizeof(a[0]);
 int sum=7;
 findPairs(a,n,sum);

    

}