#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool check(string str){
	if(str.size()!=9){
		return false;
	}
	if(str.find("1")!=string::npos&&str.find("2")!=string::npos&&str.find("3")!=string::npos&&str.find("4")!=string::npos&&str.find("5")!=string::npos&&str.find("6")!=string::npos&&str.find("7")!=string::npos&&str.find("8")!=string::npos&&str.find("9")!=string::npos){
		return true;
	}
	return false;
}

int main(int argc, const char* argv[]){
	int largest= 0;
	for(int i= 1; i<100000000; i++){
		string str= "";
		string potentialAddition= to_string(i);
		for(int j= 1; (str+potentialAddition).size()<10; j++){
			potentialAddition= to_string(j*i);
			str= str+potentialAddition;
		}
		if(check(str)&&atoi(str.c_str())>largest&&!check(to_string(i))){
			largest= atoi(str.c_str());
		}
	}
	cout << largest << endl;
}

