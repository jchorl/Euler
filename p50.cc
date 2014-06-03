#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

vector<int> listPrimes(int n){
	vector<int> numbers(n);
	vector<int> primes;
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
			primes.push_back(i);
		}
	}
	return primes;
}

int main(int argc, const char* argv[]){
	int n = 1000000;
	vector<int> primes = listPrimes(n);
	int total = 0;
	int num_primes = 0;
	for(int i = 0; primes[i]<n/2; i++){
		int tempNum = 1;
		int tempTot = primes[i];
		for(int t = (i+1); t<primes.size() && tempTot<n; t++){
			if(binary_search(primes.begin(), primes.end(), tempTot) && tempNum>num_primes){
				num_primes = tempNum;
				total = tempTot;
			}
			tempNum++;
			tempTot+=(primes[t]);
		}
	}
	cout << total << endl;
	cout << num_primes << endl;
}

