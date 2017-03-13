#include <iostream>
using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}

void kandane(int a[],int n){
  
  int max_so_far=0;
  int max_ending_here=0;
  int s_index=0;
  int e_index=0;

  for(int i=0;i<n;i++){
  	 
  	 max_ending_here+=a[i];
  	 if(max_ending_here<0)
  	 	{
  	 		max_ending_here=0;
  	 		s_index=i+1;
  	 	}
  	 else if(max_so_far<max_ending_here){
  	 	max_so_far=max_ending_here;
  	 	e_index=i;
  	 }

  }
  
  for(int i=s_index;i<=e_index;i++)
  	cout<<a[i]<<" ";

}


//negative numbers too - Dynamic Programming

void kandanedp(int a[],int n){

   int curr_max=a[0];
   int max_so_far=a[0];

   for(int i=1;i<n;i++){
     
     curr_max=max(a[i],curr_max+a[i]);
     max_so_far=max(curr_max,max_so_far);

   }

   cout<<"Max Sum:"<<max_so_far<<endl;

}

int main(){

  int a[]={-2,-3,4,-1,-2,1,5,-3};
  int n=sizeof(a)/sizeof(a[0]);
	kandanedp(a,n);

}