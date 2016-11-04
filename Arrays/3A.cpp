#include <iostream>

using namespace std;

void findOddElement(int a[],int n){
  
  int count=0;
  int i,j;
  int temp;

  for(i=0;i<n;i++){
  	temp=a[i];
  	for(j=0;j<n;j++){
  		if(a[j]==temp){
  			count++;
  		}
  	}

  		if(count%2==1){
  		   cout<<"Odd Element:"<<temp<<endl;	
  		   return;
  		}else{
  			count=0;
  		}
  }


}


int main(){

   int a[]={2,2,3,3,3,5,5};
   int n=sizeof(a)/sizeof(a[0]);
   findOddElement(a,n);

}