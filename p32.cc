#include <iostream>
#include <string>
#include <cassert>
#include <set>
using namespace std;

bool check(int a, int b){
	string str= to_string(a)+to_string(b)+to_string(a*b);
	if(str.size()>9){
		return false;
	}
	if(str.find("1")!=string::npos&&str.find("2")!=string::npos&&str.find("3")!=string::npos&&str.find("4")!=string::npos&&str.find("5")!=string::npos&&str.find("6")!=string::npos&&str.find("7")!=string::npos&&str.find("8")!=string::npos&&str.find("9")!=string::npos){
		return true;
	}
	return false;
}

int main(int argc, const char* argv[]){
	set<int> s;
	int sum= 0;
	for(int a= 1; a<100; a++){
		for(int b= 100; b<10000; b++){
			if(check(a,b)){
				s.insert(a*b);
			}
		}
	}
	for(set<int>::const_iterator it= s.cbegin(); it!=s.cend(); it++){
		sum+=*it;
	}
	cout << sum << endl;

}

