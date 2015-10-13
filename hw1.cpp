#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Word{
public:
	Word(string a, int num){
		s=a;
		newOrder(num);
	}
	const string getstr(){
		return s;
	}
	void newOrder(unsigned int num){
		order.push_back(num);
	}
	void printOrder(){
		for(int i=0;i<order.size();i++)
			cout<<order[i]<<" ";
		cout<<endl;
	}
	const int AppearTimes(){
		return order.size();
	}
private:
	string s;
	vector<unsigned int> order;

};

int main(){
	string a;
	vector<Word> dictionary;
	unsigned int count=0;
	fstream file;
	file.open("test.txt");
	while(file>>a){
		if(48<=a[0] && a[0]<=57) continue;
		count++;
		if(!((a[a.size()-1]>=65 && a[a.size()-1]<=90) || (a[a.size()-1]>=97 && a[a.size()-1]<=122)))
			a.erase(a.begin()+a.size()-1);
		if(!((a[0]>=65 && a[0]<=90) || (a[0]>=97 && a[0]<=122)))
			a.erase(a.begin());

		if(dictionary.empty() ) {
			Word tmp(a,count); dictionary.push_back(tmp); continue;
		}
		int looptime=dictionary.size();
		for(int i=0;i<looptime;i++){
			
			if(a.compare(dictionary[i].getstr()) == 0){
				dictionary[i].newOrder(count); break;
			}
			else if(i==looptime-1 ){
				Word tmp(a,count); dictionary.push_back(tmp);
			}
		}
	}
	
	cout<<count<<endl;
	for(int i=0;i<dictionary.size();i++){
		cout<<dictionary[i].getstr()<<" "<<dictionary[i].AppearTimes()<<" ";
		dictionary[i].printOrder();
	}
	
	file.close();

	return 0;
}

/*
int main(){
	|| (i==dictionary.size()-1 && a.compare(dictionary[i].getstr()) != 0)
	string a("aa"), b("a");
	cout<<b.compare(a);
}
*/