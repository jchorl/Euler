#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_set>
using namespace std;

unordered_set<int> listPrimes(int n){
	vector<int> numbers(n);
	unordered_set<int> primes;
	for(int i = 2; i<numbers.size(); i++){
		numbers.at(i) = 1;
	}
	for(int i = 2; i<numbers.size(); i++){
		if(numbers.at(i) == 1){
			for(int j = i*2; j<numbers.size(); j+=i){
				numbers.at(j) = 0;
			}
		}
	}
	for(int i = 2; i<numbers.size(); i++){
		if(numbers.at(i) == 1){
			primes.insert(i);
		}
	}
	return primes;
}
int main(int argc, const char* argv[]){
	int n = 10000;
	vector<int> numbers(2*n*n+n);
	unordered_set<int> primes = listPrimes(n);
	for(int i = 0; i < numbers.size(); i++){
		if(i < 10){
			numbers[i] = 1;
		}
		if((2*i)<numbers.size()){
			numbers[2*i] = 1;
		}
	}
	for(unordered_set<int>::iterator it = primes.begin(); it!=primes.end(); it++){
		for(int i = 1; i < n; i++){
			numbers[(*it) + 2*(i*i)] = 1;
		}
	}
	bool found = false;
	for(int i = 9; !found; i++){
		if(numbers[i]==0 && primes.find(i) == primes.end()){
			found = true;
			cout << i << endl;
		}
	}
}

