#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int pentagonal(int n){
	return (n*(3*n-1))/2;
}

bool checkPentagonal(long p){
	double n = (1 + sqrt(1+24*p))/6;
	if(abs(floor(n)-n)<0.000001){
		return true;
	}
	return false;
}

int main(int argc, const char* argv[]){
	vector<int> pentagonals;
	bool found = false;
	for(int i = 0; !found; i++){
		pentagonals.push_back(pentagonal(i+1));
		for (int j = 0; j < pentagonals.size(); ++j)
		{
			int diff = pentagonals[i]-pentagonals[j];
			if(checkPentagonal(diff)){
				if(checkPentagonal(pentagonals[i]+pentagonals[j])){
					cout << diff << endl;
					found = true;
				}
			}
		}
	}
}

