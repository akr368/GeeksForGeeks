#include <iostream>


using namespace std;

void swap(int *x,int *y){
  
  int temp=*x;
  *x=*y;
  *y=temp;

}

int partition(int a[],int l,int r){

  
    int x=a[r];
    int i=l-1;
    int j;

    for(j=l;j<r;j++){

        if(a[j]<=x){
          i++;
          swap(&a[i],&a[j]);
        }

    }

    swap(&a[i+1],&a[r]);
    return i+1;

}


void quicksort(int a[],int l,int r){

   if(l<r){
    
       int q=partition(a,l,r);
       quicksort(a,l,q-1);
       quicksort(a,q+1,r);

   }

}

int main(){
      

    int a[]={10,9,8,7,6,5,4};
    int n=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,n-1);

    int k;
    for(k=0;k<n;k++)
      cout<<a[k]<<" ";
    cout<<endl;
   
    return 0;

}

