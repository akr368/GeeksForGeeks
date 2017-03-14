#include <iostream>

using namespace std;

int gcd(int,int);
void print(int [],int);

void rotate(int a[],int n,int d){

   int i,j,k;
   
   for(i=0;i<gcd(d,n);i++){

      int temp=a[i];
      j=i;
      while(1){
      	
      	cout<<endl;
      	k=j+d;
      	if(k>=n)
      	  k=k-n;
      	if(k==i)
      	 break;
      	a[j]=a[k];
      	j=k;
      	print(a,n);
      }

      a[j]=temp;
      print(a,n);
      cout<<endl;
   }

}

void print(int a[],int n){

  for(int i=0;i<n;i++)
  	cout<<a[i]<<" ";
}


int gcd(int a,int b){

   if(b==0)
   	return a;
   else
   return gcd(b,a%b);

}


int main(){

	int a[]={1,2,3,4,5,6,7};
	int d=2;
	int n=sizeof(a)/sizeof(a[0]);

	rotate(a,n,2);
	



}