#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;

bool checkPentagonal(long p){
	double n = (1 + sqrt(1+24*p))/6;
	if(abs(floor(n)-n)<0.0001){
		return true;
	}
	return false;
}

bool checkHexagonal(long h){
	double n = (1+sqrt(1+8*h))/4;
	if(abs(floor(n)-n)<0.0001){
		return true;
	}
	return false;
}

long triangle(long n){
	return (n*(n+1))/2;
}

int main(int argc, const char* argv[]){
	bool found = false;
	for(long i = 40755; found == false; i++){
		long num = triangle(i);
		if(checkHexagonal(num)){
			if(checkPentagonal(num)){
				found = true;
				cout << num << endl;
			}
		}
	}
}