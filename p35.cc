#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

bool checkPrime(int n){
	for(int i= 2; i<=sqrt(n); i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

bool checkCircular(int n){
	string str= to_string(n);
	if(str.find("2")!=string::npos&&n>2){
		return false;
	}
	for(string::const_iterator it= str.cbegin(); it!=str.cend(); it++){
		if(!checkPrime(atoi(str.c_str()))){
			return false;
		}
		rotate(str.begin(), str.begin()+1, str.end());
	}
	return true;
}

int main(int argc, const char* argv[]){
	int sum= 0;
	#pragma omp parallel for reduction(+:sum)
	for(int i= 2; i<1000000; i++){
		if(checkCircular(i)){
			sum+=1;
		}
	}
	cout << sum << endl;
}

