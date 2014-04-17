#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
#include <vector>
using namespace std;

vector<int> primes(){
	vector<int> p(1000);
	p.at(0)= 0;
	p.at(1)= 0;
	for(int i= 2; i<p.size(); i++){
		p.at(i)= 1;
	}
	for(int i= 2; i<p.size(); i++){
		if(p.at(i)==1){
			for(int j= i*2; j<p.size(); j+=i){
				p.at(j)= 0;
			}
		}
	}
	vector<int> v;
	for(int i= 0; i<p.size(); i++){
		if(p.at(i)==1){
			v.push_back(i);
		}
	}
	return v;
}
int f(int n, int a, int b){
	return (int)(pow(n,2)+a*n+b);
}
bool prime(int n){
	if(n<2){
		return false;
	}
	for(int i= 2; i<=sqrt(n); i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(int argc, const char* argv[]){
	int numConsecutive= 0;
	int a= 0;
	int b= 0;
	vector<int> bv= primes();
	vector<int> av;
	for(int i= -999; i<1000; i++){
		av.push_back(i);
	}
	for(vector<int>::const_iterator bit=bv.begin(); bit!=bv.end(); bit++){
		for(vector<int>::const_iterator ait= av.begin(); ait!=av.end(); ait++){
			int n= 0;
			while(prime(f(n,*ait,*bit))){
				n++;
			}
			if(n>numConsecutive){
				numConsecutive= n;
				a= *ait;
				b= *bit;
			}
		}
	}
	cout << "a: " << a << ", b: " << b << ", consecutive: " << numConsecutive << endl;
	cout << "Product of coefficients: " << a*b << endl;
}

