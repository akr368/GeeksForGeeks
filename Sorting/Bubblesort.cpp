#include <iostream>
#include <limits>

using namespace std;

void swap(int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;

}

int main(){
    
    int a[]={123,2,10,3002,11,0,30};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j;

    for(i=0;i<n-1;i++){
      
       for(j=0;j<n-i-1;j++){

          if(a[j]>a[j+1])
             swap(&a[j],&a[j+1]);

      }
    }

    for(int k=0;k<n;k++)
      cout<<a[k]<< " ";

    cout<<endl;


    return 0;

}