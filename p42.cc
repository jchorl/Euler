#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <unordered_set>
using namespace std;

int value(char a){
	return a+1-'a';
}
int sum(string s){
	int sum= 0;
	for(string::const_iterator it= s.begin(); it!=s.end(); it++){
		sum+=value(tolower(*it));
	}
	return sum;
}
int main(int argc, const char* argv[]){
	ifstream wis("words.txt");	
	int triang= 0;
	unordered_set<int> triangleNumbers; //largest string is 14 chars. if all chars are z, the sum is 14*26=364.
	for(int i= 1; triang<364; i++){
		triang= (i*(i+1))/2;
		triangleNumbers.insert(triang);
	}
	string str;
	int total= 0;
	while(wis >> str){
		if(triangleNumbers.find(sum(str))!=triangleNumbers.end()){
			total++;
		}
	}
	cout << total << endl;
}

