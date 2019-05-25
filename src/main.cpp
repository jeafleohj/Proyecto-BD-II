/*
 * file: main.cpp
 * author: Jhony Angulo
 * date: 25-05-2019
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.hpp"

using namespace std;

int main(){
	string pathfiles[] = {"files/DEMOGRAPHICS.csv", "files/VUNERABLEPOPSANDENVHEALTH.csv"};
	vector<vector<string>> data;
	data =  parserCSV(pathfiles[0]);
	for(auto &row:data){
		for(auto &word:row){
			cout << word << " ";
		}
		cout << "\n";
	}
}
