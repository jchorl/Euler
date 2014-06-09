#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

set<int> getDigits(int n){
	set<int> s;
	while (n) {
		s.insert(n % 10);
		n /= 10;
	}
	return s;
}
int main(int argc, const char* argv[]){
	bool found = false;
	for(int i = 1; !found; i++){
		set<int> s = getDigits(2*i);
		if(getDigits(3*i)==s){
			if(getDigits(4*i)==s){
				if(getDigits(5*i)==s){
					if(getDigits(6*i)==s){
						cout << i << endl;
						found = true;
					}
				}
			}
		}
	}
}

