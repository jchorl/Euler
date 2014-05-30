#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;
vector<int> primes(int n){
	vector<int> p(n);
	p.at(0)= 0;
	p.at(1)= 0;
	for(int i= 2; i<p.size(); i++){
		p.at(i)= 1;
	}
	for(int i= 2; i<p.size(); i++){
		if(p.at(i)==1){
			for(int j= i*2; j<p.size(); j+=i){
				p.at(j)= 0;
			}
		}
	}
	vector<int> v;
	for(int i= 1000; i<p.size(); i++){
		if(p.at(i)==1){
			v.push_back(i);
		}
	}
	return v;
}

bool checkPermutation(int a, int b, int c){
	string as = to_string(a);
	string bs = to_string(b);
	string cs = to_string(c);
	sort(as.begin(), as.end());
	sort(bs.begin(), bs.end());
	sort(cs.begin(), cs.end());
	return as==bs && as==cs;
}

int main(int argc, const char* argv[]){
	vector<int> prime = primes(10000);
	for(vector<int>::iterator oit = prime.begin(); oit != prime.end()-1; oit++){
		for(vector<int>::iterator iit = oit+1; iit != prime.end(); iit++){
			if(binary_search(iit, prime.end(), (*iit)+(*iit-*oit))){
				if(checkPermutation(*oit, *iit, ((*iit)+(*iit-*oit)))){
					cout << *oit << *iit << ((*iit)+(*iit-*oit))<< endl;
				}
			}
		}
	}
		
}

