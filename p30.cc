#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <math.h>
#include <limits>
using namespace std;

bool checkNum(long n){
	int i= n;
	vector<int> digits;
	while(i>10){
		digits.push_back(i%10);
		i/=10;
	}
	digits.push_back(i%10);
	int sum= 0;
	for(vector<int>::const_iterator it=digits.begin(); it!=digits.end(); it++){
		int p= pow(*it, 5);
		if(p>n){
			return false;
		}
		else{
			sum+=p;
		}
	}
	if(sum==n){
		return true;
	}
	return false;
}
int main(int argc, const char* argv[]){
	int sum= 0;
	for(long i= 10; i<numeric_limits<long>::max(); i++){
		if(checkNum(i)){
			sum+=i;
		}
	}
	cout << "Sum: " << sum << endl;
}

