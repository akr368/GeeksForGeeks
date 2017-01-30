#include <iostream>

using namespace std;

int search(int a[],int n,int k){

    int i;
    for(i=0;i<n;i++){
        if(a[i]==k){
            cout<<"Element Found"<<endl;
            return 1;
        }
    }

    cout<<"Element NOT found"<<endl;
    return 0;

}



int main(){
 
    int k;
    cout<<"Search: ?"<<endl;
    cin>>k;
    int a[]={10,20,30,40,5};
    int n=sizeof(a)/sizeof(a[0]);
    search(a,n,k);

    return 0;

}