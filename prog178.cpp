#include<iostream>
using namespace std ;
int main(){
	int n=3;
	for(int lower=0;lower<n;lower++){
		for(int upper=lower;upper<n;upper++){	
		cout<<"low : " <<lower <<"\n";
		cout<<"up : "<<upper<<endl;
       }
	}
}