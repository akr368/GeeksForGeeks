#include <iostream>

using namespace std;

int binarysearch(int a[],int n,int k){

    int l=0;
    int h=n-1;

    while(l<=h){
      
        int mid=l-(l-h)/2;
        if(a[mid]==k){
            cout<<"Element found."<<endl;
            return 1;
        }

        if(k>a[mid])
           l=mid+1;
        else
           h=mid-1;    

    }

    cout<<"Element NOT found";

    return 0;
   
}


int main(){

    int a[]={1,2,3,10,20,30,50};
    int k=502;
    int n=sizeof(a)/sizeof(a[0]);
    binarysearch(a,n,k);

    return 0;

}