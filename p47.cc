#include <iostream>
#include <string>
#include <cassert>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set<int> primeFactors(int n){
	unordered_set<int> f;
	int z = 2;
	while(z*z <= n){
		if(n%z==0){
			f.insert(z);
			n/=z;
		}
		else{
			z++;
		}
	}
	if(n > 1){
		f.insert(n);
	}
	return f;
}
int main(int argc, const char* argv[]){
	bool found = false;
	for(int i = 2; !found; i++){	
		unordered_set<int> s1 = primeFactors(i);
		unordered_set<int> s2 = primeFactors(i+1);
		unordered_set<int> s3 = primeFactors(i+2);
		unordered_set<int> s4 = primeFactors(i+3);
		if(s1.size()>=4 && s2.size()>=4 && s3.size()>=4 && s4.size()>=4){
			found = true;
			cout << i << endl;
		}
	}
}

