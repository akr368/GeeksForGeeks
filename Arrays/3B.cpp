#include <iostream>
#define MAX 10000

using namespace std;

void findOdd(int a[],int n){

    int hashmap[MAX]={0};
    int i;
    for(i=0;i<n;i++){
    	hashmap[a[i]]++;
    }
    for(i=0;i<n;i++){
    	if(a[i]%2==1){
    		cout<<"Odd Element:"<<a[i]<<endl;
    		return;
    	}
    }
 

}



int main(){
 
    int a[]={1,2,3,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    findOdd(a,n);


}