#include <iostream>
using namespace std;

void findOdd(int a[],int n){

   int i;
   int ans=0;

   for(i=0;i<n;i++){
   	  ans=a[i]^ans;
   }

   cout<<ans<<endl;
   
}

int main(){
 

    int a[]={1,2,3,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    findOdd(a,n);
    

}