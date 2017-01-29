#include <iostream>
#include <algorithm>

using namespace std;


void findPair(int a[],int n,int sum){

    sort(a,a+n);
    int l=0;
    int r=n-1;
    int i=0;
    for(i=0;i<n;i++){
    	if(a[l]+a[r]==sum){
    		cout<<"Pairs:"<<a[l]<<" "<<a[r]<<endl;
    		return;
    	}
    	else if(a[l]+a[r]<sum){
    		l++;
    	}else{
    		r--;
    	}

    }

    cout<<"No Pairs"<<endl;

}

int main(){

   int a[]={5,4,3,2,1};
   int n=sizeof(a)/sizeof(a[0]);
   int sum=5;
   findPair(a,n,sum);


}
