#include <iostream>
using namespace std;

//This approach solves the 'overflow' issue.
//We take subtract the 'given' numbers from 'known' numbers
//and take the absolute of the final result.

int findMissing(int a[],int n){

    int i;
    int sum=0;
    int k=1;
    for(i=0;i<n;i++){
    	sum+=k-a[i];
    
    		k++;

    }
    return abs(sum+k);

}



int main(){

   int a[]={1, 2,4,5,6,7,8};
   int n=sizeof(a)/sizeof(a[0]);
   cout<<findMissing(a,n)<<endl;
   return 0;
}