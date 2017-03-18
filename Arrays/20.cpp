#include <iostream>
#include <cmath>

using namespace std;

struct pair{
  int min;
  int max;
};


void findMinMax(int a[],int n){
  
  struct pair p;
  int i;

  if(n%2==0){
   
     if(a[0]<a[1]){
       p.min=a[0];
       p.max=a[1];
     }
     else{
      p.min=a[1];
      p.max=a[0];
     }
   i=2;  
  }

  else{
      p.min=a[0];
      p.max=a[0];
      i=1;
  }

  while(i<n-1){

     if(a[i]<a[i+1]){ 
         if(a[i]<p.min)
          p.min=a[i];
        else if(a[i+1]>p.max)
          p.max=a[i+1];
     }
     else{
        
         if(a[i]>p.max)
          p.max=a[i];
        else if(a[i+1]<p.min)
          p.min=a[i];
     }
     i+=2;
  }

  cout<<p.min<<" "<<p.max<<endl;





}


int main(){

	int a[]={1000, 11, 445, 1, 330, 3000};
	int n=sizeof(a)/sizeof(a[0]);
  findMinMax(a,n);

 return 0;
}