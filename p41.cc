#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <vector>
using namespace std;

bool checkPrime(int n){
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

bool checkPandigital(string str){
	int size= str.size();
	if(size>9){
		return false;
	}
	for(int i= 1; i<=size; i++){
		if(str.find(to_string(i))==string::npos){
			return false;
		}
	}
	return true;
}


int main(int argc, const char* argv[]){
	vector<int> p;
#pragma omp parallel for
	for(int i= 999999999; i>1000000; i--){
		if(checkPandigital(to_string(i))){
			if(checkPrime(i)){
				p.push_back(i);		
			}
		}
	}
	int max= 0;
	for(vector<int>::const_iterator it= p.cbegin(); it!=p.cend(); it++){
		if((*it)>max){
			max= *it;
		}
	}
	cout << max << endl;
}

