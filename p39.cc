#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <set>
using namespace std;

double p(double a, double b){
	return a+b+sqrt(pow(a,2)+pow(b,2));
}
int main(int argc, const char* argv[]){
	double maxSize= 0;
	double maxP= 0;
	for(double perimeter= 1.0; perimeter<1000; perimeter++){
		set<double> sides;
		for(double a= 1.0; a<perimeter; a++){
			for(double b= 1.0; b<perimeter; b++){
				if(sides.find(a)==sides.end()&&sides.find(b)==sides.end()&&p(a,b)==perimeter){
					sides.insert(a);
				}
			}
		}
		if(sides.size()>maxSize){
			maxSize= sides.size();
			maxP= perimeter;
		}
	}
	cout << "Perimeter: " << maxP << ", Solutions:" << maxSize << endl;
}

