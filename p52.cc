#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

set<int> getDigits(int n){
}
bool checkPermutation(int a, int b){
	set<int> s1, s2;
	while (a) {
		s1.insert(a % 10);
		a /= 10;
	}
	while (b) {
		s2.insert(b % 10);
		b /= 10;
	}
	return s1==s2;
}
int main(int argc, const char* argv[]){
	bool found = false;
	for(int i = 1; !found; i++){
		if(checkPermutation(2*i, 3*i)){
			if(checkPermutation(2*i, 4*i)){
				if(checkPermutation(2*i, 5*i)){
					if(checkPermutation(2*i, 6*i)){
						cout << i << endl;
						found = true;
					}
				}
			}
		}
	}
}

