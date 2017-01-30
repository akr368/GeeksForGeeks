#include <iostream>
#include <limits>

using namespace std;

int main(){
    
    int a[]={10,1,2,10,3002,11,0,30};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j;
    int min_index=0;
    int temp;
    int k;

    for(i=0;i<n-1;i++){

      min_index=i;

      for(j=i+1;j<n;j++){
      	 if(a[j]<=a[min_index])
      	 	min_index=j; 
      }

      temp=a[i];
      a[i]=a[min_index];
      a[min_index]=temp;

    }

    for(k=0;k<n;k++)
    	cout<<a[k]<<" ";
    cout<<endl;

    return 0;

}