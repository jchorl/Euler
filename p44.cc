#include <iostream>
#include <string>
#include <cassert>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;
int pentagonal(int n){
	return (n*(3*n-1))/2;
}

int main(int argc, const char* argv[]){
	unordered_set<int> pentagonals;
	unordered_set<int> checked;
	for(int i = 1; i < 8000; i++){
		pentagonals.insert(pentagonal(i));
	}
	int minD = 9999999;

	for(unordered_set<int>::iterator oit = pentagonals.begin(); oit!=pentagonals.end(); oit++){
		for(unordered_set<int>::iterator iit = pentagonals.begin(); iit!=pentagonals.end(); iit++){
			if(checked.find(((*oit+*iit)*(*oit + *iit + 1))/2+min(*oit, *iit)) == checked.end()){
				if(pentagonals.find(*oit + *iit) != pentagonals.end()){
					if(pentagonals.find(*oit - *iit) != pentagonals.end()){
						if(abs(*oit-*iit)<minD){
							minD = abs(*oit - *iit);
						}
					}
				}
				checked.insert(((*oit+*iit)*(*oit + *iit + 1))/2+min(*oit, *iit));
			}
		}
	}
	cout << minD << endl;
}

