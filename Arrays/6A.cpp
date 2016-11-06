#include <iostream>
using namespace std;


int binarySearch(int a[],int n,int x,int l,int h);
int findPivotedIndex(int a[],int n,int l,int h);

/*
Approach: find the pivot (the index where a[current]>a[current+1] in an increasing array)
Compare the a[0] with 'key' and decide to recurse right or left (using binary search).
*/


int searchPivotedArray(int a[],int n,int x) {
  
   int l=0;
   int h=n-1;
   int pivoted_index=findPivotedIndex(a,n,l,h);
   cout<<a[pivoted_index]<<endl;
   if(x==a[pivoted_index])
   	return pivoted_index;
   int search_index=0;
   if(a[0]<x)
   
   	search_index=binarySearch(a,n,x,l,pivoted_index-1);
   else 
   		search_index=binarySearch(a,n,x,pivoted_index+1,h);

 return search_index;

}

int binarySearch(int a[],int n,int x,int l,int h){

	int mid=((l-h)/2 )+ h;
    if(a[mid]==x)
    	return mid;
    else if(x>a[mid])
    	return binarySearch(a,n,x,mid+1,h);
    else 
    	return binarySearch(a,n,x,l,mid-1);


}


int findPivotedIndex(int a[],int n,int l,int h){
  
     if (l==h)
     	return l;
     if (l>h)
     	return -1;

     int mid=((l-h)/2)+h;

     if(a[mid]>a[mid+1])
     	return mid;
     else if(a[mid-1]>a[mid])
     	return mid-1;
     else if(a[l]<a[mid])
     	return findPivotedIndex(a,n,mid+1,h);
     else                                        //else is not required here (exists for clarity! :)
     	return findPivotedIndex(a,n,l,mid-1);


}



int main(){

	 int a[]={1,2,3,4,5,-2,-1,0};
	 int n=sizeof(a)/sizeof(a[0]);
    
     int ans=searchPivotedArray(a,n,-2);
     cout<< "Index:"<<ans<<endl;
     cout<<"Element:"<<a[ans]<<endl;
    

	return 0;
}