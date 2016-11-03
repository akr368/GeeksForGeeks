#include <iostream>
#define MAX 100000

using namespace std;
//This method works if we know the range of numbers
//beforehand. 


void findPair(int a[],int n,int sum){

   bool hashmap[MAX]={0};
   int i=0;
   int temp;
   for(i=0;i<n;i++){
      temp=sum-a[i];
   	 if(temp>=0 && hashmap[temp]]==1){
   	 	cout<<"Pair:"<<sum-a[i]<<"+"<<a[i]<<endl;
   	 	return;
   	 }
   	 	hashmap[a[i]]=1;

   }

   cout<<"No such pair exists!";

}

int main(){

   int a[]={5,4,3,2,1};
   int sum=7;
   int n=sizeof(a)/sizeof(a[0]);
   findPair(a,n,sum);
    

}
