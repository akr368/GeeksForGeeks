#include <iostream>
#include <cmath>

using namespace std;

void calculate(int a[],int n){
  
  int f_min=INT_MAX;
  int s_min=INT_MAX;
  
  for(int i=0;i<n;i++){
      
      if(a[i]<f_min){
         s_min=f_min;
         f_min=a[i];
      }
   
      else if(a[i]<s_min && a[i]!=f_min){
         s_min=a[i];
      }

  }

  cout<<f_min<<" "<<s_min<<endl;

}



int main(){

	int a[]={12, 13, 1, 10, 34, 2};
	int n=sizeof(a)/sizeof(a[0]);
	calculate(a,n);
	

}