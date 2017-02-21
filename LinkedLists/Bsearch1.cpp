#include <iostream>

using namespace std;

int binarysearch(int a[],int k,int l,int h){
   
    if(l<=h){
     
    int mid=l-(l-h)/2; 

    if(a[mid]==k){
        cout<<"Element found"<<endl;
        return 1;
    }

    if(k>a[mid])
        return binarysearch(a,k,mid+1,h);
    else
        return binarysearch(a,k,0,mid-1);
  
   }

   return 0;


}


int main(){

    int a[]={1,2,3,10,20,30,50};
    int k=-2;
    int n=sizeof(a)/sizeof(a[0]);
    if(!binarysearch(a,k,0,n-1))
        cout<<"Element NOT found"<<endl;

    return 0;

}