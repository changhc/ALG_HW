#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
void ReadFile(vector< vector<int> >&, int attr[], char* filename);
void printTable(vector<vector<int> >&);
void ConstructGraph(int attr[], vector<int>&);
int main(int argc, char* argv[]){
	int attr[3];	//attr[0]=nrow, attr[1]=ncol, attr[2]=capacity
	vector< vector<int> >table;
	ReadFile(table, attr, argv[1]);
	printTable(table);

	return 0;
}

void ReadFile(vector< vector<int> >& table, int attr[], char* filename){
	fstream file;
	file.open(filename, ios::in);
	
	int nnet, num=0;
	string tmp;
	stringstream ss;
	file>>tmp>>tmp;
	ss<<tmp; ss>>attr[0]; ss.str(""); ss.clear();
	file>>tmp;ss<<tmp; ss>>attr[1]; ss.str(""); ss.clear();
	file>>tmp>>tmp; ss<<tmp; ss>>attr[2]; ss.str(""); ss.clear();
	file>>tmp>>tmp>>tmp; ss<<tmp; ss>>nnet; ss.str(""); ss.clear();
	for(int i=0; i<nnet; i++){
		vector<int> net;
		file>>tmp;
		for(int j=0; j<4; j++)
			{file>>tmp; ss<<tmp; ss>>num; ss.str(""); ss.clear(); net.push_back(num);}
		table.push_back(net);
	}
	file.close();
}
void printTable(vector< vector<int> >& table){
	for(unsigned int i=0; i<table.size(); i++){
		for(int j=0; j<4; j++)
			cout<<table[i][j]<<" ";
		cout<<endl;
	}

	void ConstructGraph(int attr[], vector<int>& net){

	}
}
