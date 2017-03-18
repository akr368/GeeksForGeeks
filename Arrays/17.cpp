#include <iostream>
#include <cmath>

using namespace std;


void findPair(int a[],int n){

   int l=0;
   int r=n-1;
   sort(a,a+n);
   int min_sum=INT_MAX;
   int curr_sum;
   int min_l=l;
   int min_r=r;

   while(l<r){
     
      curr_sum=a[l]+a[r];
      if(abs(curr_sum)<abs(min_sum)){

        min_sum=curr_sum;
         min_l=l;
         min_r=r;
      }

      if(curr_sum<0)
         l++;
      else
         r--;

   }

   cout<<"Pair: "<<a[min_l]<<" "<<a[min_r]<<endl;

}

int main(){

	int a[]={1, 60, -10, 70, -80, 85};
	int n=sizeof(a)/sizeof(a[0]);
	findPair(a,n);
	

}