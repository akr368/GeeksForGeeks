#include <iostream>


using namespace std;


void segregate(int a[],int n){

  int left=0;
  int right=n-1;
  while(left<right){

    while(a[left]==0 && left<right)
      left++;

    while(a[right]==1 && left<right)
      right--;

    if(left<right){
      a[left]=0;
      a[right]=1;
      left++;
      right--;
    }


  }

}

void print(int a[],int n){

  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}


int main(){

	int a[]={0,1,0,1,0,0,1,1,1,0};
	int n=sizeof(a)/sizeof(a[0]);
  segregate(a,n);
  print(a,n);
  

 return 0;
}