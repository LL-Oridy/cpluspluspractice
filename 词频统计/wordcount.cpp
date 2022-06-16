#include"struct.h"

void Dictionary::read(const string& filename) {
	ifstream ifs(filename);
	if (!ifs.good()) {
		std::cerr << "ifs is not good" << endl;
	}
	string line;
	//获取每一行
	while (getline(ifs, line)) {
		//按行读入，缓冲流
		istringstream iss(line);
		string word;
		int i;
		//iss类似于cin
		while (iss >> word) {
			//扫描容器中所有的元素
			for ( i = 0; i < _dict.size(); ++i)
			{
				if (_dict[i]._word == word) {
					++_dict[i]._frequency;
					break;
				}
			}
			//如果扫描完了还没有找到这个单词
			if (i == _dict.size()) {
				Record record;
				record._word = word;
				record._frequency = 1;
				_dict.push_back(record);
			}
		}
	}
	ifs.close();
}

void Dictionary::write(const string& filename) {
	ofstream ofs(filename);
	if (!ofs.good()) {
		std::cerr << "ofs is not good" << endl;
	}
	for (int i = 0; i < _dict.size(); i++)
	{
		//ofs类似于cout,cout是将内容输入到terminal上，ofs则是输出到指定文件中去
		ofs << _dict[i]._word << "--->" << _dict[i]._frequency << endl;
	}
	ofs.close();
}