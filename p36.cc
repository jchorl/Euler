#include <iostream>
#include <string>
#include <cassert>
using namespace std;

string convertToBinary(int n){
	string str= "";
	if(n==0){
		return 0;
	}
	while(n!=0){
		int r= n%2;
		str= to_string(r)+str;
		n/=2;
	}
	return str;
}

bool checkPalindrome(string s, int left, int right){
	if(right<=left){
		return true;
	}
	else if(s.at(left)==s.at(right)){
		return checkPalindrome(s, left+1, right-1);
	}
	return false;
}
bool checkPalindrome(string s){
	return checkPalindrome(s, 0, s.size()-1);
}

int main(int argc, const char* argv[]){
	int sum=0;
	#pragma omp parallel for reduction(+:sum)
	for(int i= 1; i<1000000; i++){
		if(checkPalindrome(to_string(i))&&checkPalindrome(convertToBinary(i))){
			sum+=i;
		}
	}
	cout << sum << endl;
}

