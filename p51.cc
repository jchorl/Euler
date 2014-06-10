#include <iostream>
#include <bitset>
#include <unordered_set>
#include <string>
#include <cassert>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int checkDuplicateDigits(int n){
	unordered_set<int> s;
	while (n) {
		if(s.count(n % 10) == 1){
			return n%10;
		}
		s.insert(n % 10);
		n /= 10;
	}
	return -1;
}
vector<int> listPrimesOver57000WithDuplicates(int n){
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
		int dup = checkDuplicateDigits(i);
		if(numbers.at(i) == 1 && i > 57000 && (-1 != dup)){
			primes.push_back(i);
		}
	}
	return primes;
}

int main(int argc, const char* argv[]){
	vector<int> primes = listPrimesOver57000WithDuplicates(1000000);	
	vector<int> options;
	for(int i = 1; i < pow(2, 5); i++){
		options.push_back(atoi(bitset<6>(i*2).to_string().c_str()));
	}
	for(auto it = primes.begin(); it!=primes.end(); ++it){
		bool checks[9];
		for(int j = 0; j < options.size(); j++){
			for(int i = 1; i < 10; ++i){
					int temp = (*it)+i*(options[j]);
					int temp2 = *it;
					while(temp){
						if(temp%10 < temp2%10){
							checks[0] = false;
							checks[1] = false;
							checks[2] = false;
						}
						temp /= 10;
						temp2 /= 10;
					}
				if(binary_search(primes.begin(), primes.end(), (*it)+i*(options[j]))){
					checks[i-1] = true;
				}
				else{
					checks[i-1] = false;
				}
			}
			int count = 0;
			for(int q = 0; q < 9; q++){
				if(!checks[q]){
					count++;
				}
			}
			if(count < 3){
				cout << *it << endl;
				exit(0);
			}
		}
	}
}

