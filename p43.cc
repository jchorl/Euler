#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

bool checkPandigital(string str){
	int size= str.size();
	if(size!=10){
		return false;
	}
	for(int i= 0; i<size; i++){
		if(str.find(to_string(i))==string::npos){
			return false;
		}
	}
	return true;
}

int main(int argc, const char* argv[]){
	vector<string> three;
	vector<string> seven;
	vector<string> eleven;
	vector<string> thirteen;
	vector<string> seventeen;
	for(int i = 1; 3*i<1000; i++){
		if(3*i<10){
			three.push_back("00"+to_string(3*i));
		}
		else if( 3*i<100){
			three.push_back("0"+to_string(3*i));
		}
		else{
			three.push_back(to_string(3*i));
		}
		if(7*i<10){
			seven.push_back("00"+to_string(7*i));
		}
		else if(7*i<100){
			seven.push_back("0"+to_string(7*i));
		}
		else if(7*i>999){}
		else{
			seven.push_back(to_string(7*i));
		}
		if(11*i < 100){
			eleven.push_back("0"+to_string(11*i));
		}
		else if(11*i>999){}
		else{
			eleven.push_back(to_string(11*i));
		}
		if(13*i < 100){
			thirteen.push_back("0"+to_string(13*i));
		}
		else if(13*i>999){}
		else{
			thirteen.push_back(to_string(13*i));
		}
		if(17*i < 100){
			seventeen.push_back("0"+to_string(17*i));
		}
		else if(17*i>999){}
		else{
			seventeen.push_back(to_string(17*i));
		}
	}
	vector<string> seveneleven;
	for(vector<string>::iterator eit = eleven.begin(); eit!=eleven.end(); eit++){
		for(vector<string>::iterator sit = seven.begin(); sit!=seven.end(); sit++){
			if((*sit).substr(1)==(*eit).substr(0,2) && ((*sit).substr(1,1)=="5"||(*sit).substr(1,1)=="0")){
				seveneleven.push_back((*sit)+(*eit).substr(2));
			}
		}
	}

	vector<string> seveneleventhirteen;
	for(vector<string>::iterator sit = seveneleven.begin(); sit!=seveneleven.end(); sit++){
		for(vector<string>::iterator tt = thirteen.begin(); tt!=thirteen.end(); tt++){
			if((*sit).substr(2)==(*tt).substr(0,2)){
				seveneleventhirteen.push_back((*sit)+(*tt).substr(2));
			}
		}
	}
	vector<string> seveneleventhirteenseventeen;
	for(vector<string>::iterator sit = seveneleventhirteen.begin(); sit!=seveneleventhirteen.end(); sit++){
		for(vector<string>::iterator st = seventeen.begin(); st!=seventeen.end(); st++){
			if((*sit).substr(3)==(*st).substr(0,2)){
				seveneleventhirteenseventeen.push_back((*sit)+(*st).substr(2));
			}
		}
	}
	for(vector<string>::iterator it = seveneleventhirteenseventeen.begin(); it!=seveneleventhirteenseventeen.end(); ){
		if((*it).at(1)!='5'&&(*it).at(1)!='0'){
			it = seveneleventhirteenseventeen.erase(it);
		}
		else {
			++it;
		}
	}
	vector<string> five;
	for(vector<string>::iterator it = seveneleventhirteenseventeen.begin(); it!=seveneleventhirteenseventeen.end(); it++){
		for(int i = 0; i<10; i++){
			five.push_back(to_string(i)+(*it));
		}
	}
	vector<string> th;
	for(vector<string>::iterator tt = three.begin(); tt!=three.end(); tt++){
		for(vector<string>::iterator sit = five.begin(); sit!=five.end(); sit++){
			if((*tt).substr(1)==(*sit).substr(0,2)){
				th.push_back((*tt).substr(0,1)+(*sit));
			}
		}
	}
	for(vector<string>::iterator it = th.begin(); it!=th.end(); ){
		if((*it).at(1)!='0'&&(*it).at(1)!='2'&&(*it).at(1)!='4'&&(*it).at(1)!='6'&&(*it).at(1)!='8'){
			it = th.erase(it);
		}
		else {
			++it;
		}
	}
	vector<string> one;
	for(vector<string>::iterator it = th.begin(); it!=th.end(); it++){
		for(int i = 0; i<10; i++){
			for(int j = 0; j<10; j++){
				one.push_back(to_string(i)+to_string(j)+(*it));
			}
		}
	}

	long sum = 0;
	for(vector<string>::iterator it = one.begin(); it!=one.end(); it++){
		if(checkPandigital(*it)){
			sum+=atol((*it).c_str());
		}
	}
	cout << sum << endl;
}
