#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

int main(int argc, const char* argv[]){
	vector<char> chars;
	for(int i= 1; chars.size()<1000000; i++){
		string str= to_string(i);
		for(string::const_iterator it= str.begin(); it!=str.end(); it++){
			chars.push_back(*it);
		}
	}
	cout << (chars[0]-'0')*(chars[9]-'0')*(chars[99]-'0')*(chars[999]-'0')*(chars[9999]-'0')*(chars[99999]-'0')*(chars[999999]-'0')  << endl;
}
