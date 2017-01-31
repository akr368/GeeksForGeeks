#include <iostream>


using namespace std;


void merge(int a[],int l,int m,int r){
   
   int n1=m-l+1;
   int n2=r-m;
    
   int L[n1];
   int R[n2];

   int i,j;
   for(i=0;i<n1;i++)
      L[i]=a[l+i];

   for(j=0;j<n2;j++)
      R[j]=a[m+j+1];

   i=0;
   j=0;
   int k=l;

   while(i<n1 && j<n2){

      if(L[i]<=R[j]){
         a[k]=L[i];
         i++;
      }

      else{
           a[k]=R[j];
           j++;

      }

      k++;

   }

   while(i<n1){
    
      a[k]=L[i];
      i++;
      k++;

   }

   while(i<n2){
   
      a[k]=R[j];
      j++;
      k++;

   }



}

void mergesort(int a[],int l,int r){

  if(l<r){
    
    int mid=l+(r-l)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);

  }

}


int main(){
      

    int a[]={10,9,8,7,6,5,4};
    int n=sizeof(a)/sizeof(a[0]);
    mergesort(a,0,n-1);

    int i;
    for(i=0;i<n;i++)
      cout<<a[i]<<" ";
    cout<<endl;

    return 0;

}

