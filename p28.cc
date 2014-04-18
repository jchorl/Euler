#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
using namespace std;

int main(int argc, const char* argv[]){
	long long sum= 1;
	for(int i= 1; i<501; i++){
		sum+=pow(2*i+1, 2);
		sum+=(pow(2*i+1, 2)-2*i);
		sum+=(1+4*pow(i,2));
		sum+=(1+4*pow(i,2)-2*i);
	}
	cout << sum << endl;
}

