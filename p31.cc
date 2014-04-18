#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int options(int curr, int smallest){
	if(curr==200){
		return 1;
	}
	else if(curr>200){
		return 0;
	}
	else{
		if(smallest<2){
			return options(curr+1,1)+options(curr+2,2)+options(curr+5,5)+options(curr+10,10)+options(curr+20,20)+options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<3){
			return options(curr+2,2)+options(curr+5,5)+options(curr+10,10)+options(curr+20,20)+options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<6){
			return options(curr+5,5)+options(curr+10,10)+options(curr+20,20)+options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<11){
			return options(curr+10,10)+options(curr+20,20)+options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<21){
			return options(curr+20,20)+options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<51){
			return options(curr+50,50)+options(curr+100,100)+options(curr+200,200);
		}
		else if(smallest<101){
			return options(curr+100,100)+options(curr+200,200);
		}
		else{
			return options(curr+200,200);
		}
	}
}

int main(int argc, const char* argv[]){
	cout << options(0, 0) << endl;
}

