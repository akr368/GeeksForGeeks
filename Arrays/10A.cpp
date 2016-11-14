#include <iostream>
using namespace std;


int main(){
	int a[]={1,2,3,4,5,6,7,8};
	int r=2;
	int n=sizeof(a)/sizeof(a[0]);
	int temp[r];
	int i=0;
	int count=r;

	
	for(i=0;i<r;i++){
		temp[i]=a[i];
	}
	

    while(count){
	  for(i=0;i<n-1;i++)
		a[i]=a[i+1];
	
	count--;
    }


	int j=0;
	for(i=n-r;i<n;i++){
		a[i]=temp[j];
		j++;
	} 

    for(i=0;i<n;i++){
    	cout<<a[i]<<" ";
    }
    cout<<endl;
   

}