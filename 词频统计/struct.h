#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;
using std::istringstream;
using std::ifstream;
using std::ofstream;

struct Record {
	string _word;
	int _frequency;
};

class Dictionary {
public:
	void read(const string& filename);
	void write(const string& filename);

private:
	vector<Record> _dict;
};