#include <iostream>

using namespace std;

int max(int a,int b){
  return (a>b)?a:b;
}

int findSum(int a[],int n){

   int inc=a[0];
   int exc=0;
   int inc_temp;

   for(int i=1;i<n;i++){
      
      inc_temp=exc+a[i];
      exc=max(inc,exc);
      inc=inc_temp; 
   }
   return max(inc,exc);

}


int main(){

	int a[]={5,5,10,40,50,35};
	int n=sizeof(a)/sizeof(a[0]);

	cout<<findSum(a,n)<<endl;
	



}