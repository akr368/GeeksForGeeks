#include <iostream>
using namespace std;

int findMissing(int a[],int n){

   int sum=((n+1)*(n+2))/2;
   int total=0;
   int i;
   for(i=0;i<n;i++){
   	total+=a[i];
   }
   return sum-total;

 
}



int main(){

   int a[]={1, 2, 4,6, 3, 7, 8};
   int n=sizeof(a)/sizeof(a[0]);
   cout<<findMissing(a,n)<<endl;
    
    return 0;

}