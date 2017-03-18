#include <iostream>

using namespace std;


void printLeaders(int a[],int n){
   
   int cur_max=0;
   for(int i=n-1;i>=0;i--){
   
      if(a[i]>cur_max)
         {
            cout<<a[i]<<" ";
            cur_max=a[i];
         }
      
       
   }


}



int main(){

	int a[]={16, 17, 4, 3, 5, 2};
	int n=sizeof(a)/sizeof(a[0]);
	printLeaders(a,n);
	



}