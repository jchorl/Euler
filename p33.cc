#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

double reduce(int n, int d){
	string strnum= to_string(n);
	string strden= to_string(d);
	int newnum= 0;
	int newden= 0;
	if(strnum.at(0)==strden.at(0)){
		newnum= strnum.at(1)-'0';
		newden= strden.at(1)-'0';
	}
	else if(strnum.at(0)==strden.at(1)){
		newnum= strnum.at(1)-'0';
		newden= strden.at(0)-'0';
	}
	else if(strnum.at(1)==strden.at(0)){
		newnum= strnum.at(0)-'0';
		newden= strden.at(1)-'0';
	}
	else if(strnum.at(1)==strden.at(1)){
		newnum= strnum.at(0)-'0';
		newden= strden.at(0)-'0';
	}
	else{
		return -1;
	}
	if(newden!=0){
		return newnum/((double)newden);
	}
	else{
		return -1;
	}
}
int gcd(int a, int b){
	while(b!=0){
		int c= a;
		a= b;
		b= c%b;
	}
	return a;
}
int main(int argc, const char* argv[]){
	vector<int> numerators;
	vector<int> denominators;
	for(int a= 10; a<100; a++){
		for(int b= 10; b<100; b++){
			if(a%10==0&&b%10==0){
				b++;
			}
			if(b<100){
				if(((double)a)/b==reduce(a,b)&&((double)a)/b<1){
					numerators.push_back(a);
					denominators.push_back(b);
				}
			}
		}
	}
	int numprod= 1, denprod= 1;
	for(vector<int>::const_iterator it= numerators.cbegin(); it!=numerators.cend(); it++){
		numprod*=*it;
	}
	for(vector<int>::const_iterator it= denominators.cbegin(); it!=denominators.cend(); it++){
		denprod*=*it;
	}
	int div= gcd(numprod, denprod);
	cout << denprod/div << endl;
	return 0;
}

