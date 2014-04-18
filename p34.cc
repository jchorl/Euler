#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
using namespace std;

int factorials[]{1,1,2,6,24,120,720,5040,40320,362880};
bool check(long n){
	string str= to_string(n);
	if(str.find("1")!=string::npos&&n%2==0){
		return false;
	}
	long sum= 0;
	for(string::const_iterator it= str.cbegin(); it!=str.cend(); it++){
		sum+= factorials[*it-'0'];
	}
	if(sum==n){
		return true;
	}
	return false;
}

int main(int argc, const char* argv[]){
	long sum= 0;
	#pragma omp parallel for reduction(+:sum)
	for(long long i= 10; i<1000000000; i++){
		if(check(i)){
			sum+=i;
		}
	}
	cout << sum << endl;
}

