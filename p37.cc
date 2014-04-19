#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

bool prime(int n){
	if(n<2){
		return false;
	}
	for(int i= 2; i<=sqrt(n); i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

bool truncatable(int n){
	if(!prime(n)){
		return false;
	}
	//right to left
	int copy= n;
	copy/=10;
	while(copy>0){
		if(!prime(copy)){
			return false;
		}
		copy/=10;
	}
	//left to right
	int starting= pow(10,to_string(n).size()-1);
	while(starting>9){
		n%=starting;
		if(!prime(n)){
			return false;
		}
		starting/=10;
	}
	return true;
}


int main(int argc, const char* argv[]){
	int sum= 0;
	#pragma omp parallel for reduction(+:sum)
	for(int i= 10; i<1000000; i++){
		if(truncatable(i)){
			sum+=i;
		}
	}
	cout << sum << endl;
}

