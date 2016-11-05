#include <iostream>
using namespace std;

int findMissing(int a[],int n){
   
   int ans=0;
   int i;
   for(i=1;i<=n+1;i++){
   	ans^=i;
   }
   for(i=0;i<n;i++){
   	ans^=a[i];
   }
 
  return ans;

}

int main(){


   int a[]={1, 2, 4,6, 3, 7, 8};
   int n=sizeof(a)/sizeof(a[0]);
   cout<<findMissing(a,n);

	return 0;
}