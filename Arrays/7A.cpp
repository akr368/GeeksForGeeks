#include <iostream>
using namespace std;
#define NA -1

void move(int a[],int n){

    int i=n-1;
    int j;

    for(j=n-1;j>=0;j--){

       if(a[j]!= NA){
       	a[i]=a[j];
       	i--;
       }

    }

}

void merge(int a[],int b[],int m,int n){

	int i=n; 
	int j=0;
	int k=0;

	while(k<(m+n)){

        if((i<(m+n) && a[i]<=b[j] )|| j==n){
        	a[k]=a[i];
        	k++;
        	i++;

        }else{
        	a[k]=b[j];
        	j++;
        	k++;
            
        }

	}


}

void print(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}


int main(){
  
   int a[] = {5, 6, NA, NA, NA, 7, NA, 8, 9};
  int N[] = {1, 2, 3, 4};
  int m=sizeof(a)/sizeof(a[0]);
  int n=sizeof(N)/sizeof(N[0]);
  
  print(a,m);
  move(a,m);
  print(a,m);
  print(N,n);
  merge(a,N,m,n);
  print(a,m);

return 0;

}