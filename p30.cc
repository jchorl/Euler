#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

//compile with -fopenmp to utilize all cores

bool checkNum(int n){
	int i= n;
	vector<int> digits;
	while(i>10){
		digits.push_back(i%10);
		i/=10;
	}
	digits.push_back(i%10);
	sort(digits.begin(), digits.end(), greater<int>());
	int sum= 0;
	for(vector<int>::const_iterator it=digits.begin(); it!=digits.end(); it++){
		int p= pow(*it, 5);
		if(p>n || sum>n){
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
	//#pragma omp parallel for reduction(+:sum)
	for(int i= 10; i<(pow(9,5)*(to_string(i).size())); i++){
		if(checkNum(i)){
			sum+=i;
		}
	}
	cout << "Sum: " << sum << endl;
}

