#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

bool checkPermutation(int a, int b){
	vector<int> v1, v2;
	while (a) {
		v1.push_back(a % 10);
		a /= 10;
	}
	while (b) {
		v2.push_back(b % 10);
		b /= 10;
	}
	return is_permutation(v1.begin(), v1.end(), v2.begin());
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

