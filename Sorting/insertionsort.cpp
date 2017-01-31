#include <iostream>


using namespace std;


int main(){
    
    int a[]={10,18,7,4,2};
    int i,j;
    int key;
    int n=sizeof(a)/sizeof(a[0]);
    j=0;

    for(i=1;i<n;i++){

      key=a[i];
      j=i-1;

      while(j>=0 && a[j]>key){
         a[j+1]=a[j];
         j--;
      }

      a[j+1]=key;


    }

    int k;
    for(k=0;k<n;k++)
      cout<<a[k]<<" ";




    return 0;

}