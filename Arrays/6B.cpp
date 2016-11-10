#include <iostream>
using namespace std;


int searchPivotedArray(int a[],int l,int h,int key){

   if(l>h)
   	return -1;
  
   int mid=(l-h)/2+h;
   if(a[mid]==key){
   	return mid;
   }

   if(a[l]<=a[mid]){

       if(key>=a[l] && key<=a[mid]){
       	return searchPivotedArray(a,l,mid-1,key);
       }
       return searchPivotedArray(a,mid+1,h,key);
   }

   if(key>=a[mid] && key<=a[h])
   	  return searchPivotedArray(a,mid+1,h,key);
   	else
   		return searchPivotedArray(a,l,mid-1,key);



}

int main(){

	 int a[]={6,7,0,1,2,3,4,5};
	 int n=sizeof(a)/sizeof(a[0]);
    
     int ans=searchPivotedArray(a,0,n-1,5);
     if(ans!=-1){
     cout<< "Index:"<<ans<<endl;
     cout<<"Element:"<<a[ans]<<endl;
     }
     else
     	cout<<"ELEMENT NOT FOUND!"<<endl;

    

	return 0;
}