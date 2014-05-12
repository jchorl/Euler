#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool checkPandigital(string str){
	int size= str.size();
	if(size!=9){
		return false;
	}
	for(int i= 0; i<=size; i++){
		if(str.find(to_string(i))==string::npos){
			return false;
		}
	}
	return true;
}

bool check(string str){
	if(checkPandigital(str)){
		if((str[3]-'0')%2==0){
			if(atoi((str.substr(2,3)).c_str())%3==0){
				if(str[5]==5||str[5]==0){
					return true;
				}
			}
		}
	}
	return false;
}

int main(int argc, const char* argv[]){
	cout << check("43043") << endl;	
}

