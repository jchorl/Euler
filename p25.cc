#include <iostream>
#include <string>
#include <cassert>
#include <math.h>
using namespace std;

double phi= (1+sqrt(5))/2;

int length(int n){
	return (int)n*log10(phi)-log10(sqrt(5))+1;
}

int main(int argc, const char* argv[]){
	int l= 0;
	for(l= 0; length(l)<1000; l++){}
	cout << l << endl;
}

