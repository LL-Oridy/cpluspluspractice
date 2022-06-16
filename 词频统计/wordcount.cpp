#include"struct.h"

void Dictionary::read(const string& filename) {
	ifstream ifs(filename);
	if (!ifs.good()) {
		std::cerr << "ifs is not good" << endl;
	}
	string line;
	//��ȡÿһ��
	while (getline(ifs, line)) {
		//���ж��룬������
		istringstream iss(line);
		string word;
		int i;
		//iss������cin
		while (iss >> word) {
			//ɨ�����������е�Ԫ��
			for ( i = 0; i < _dict.size(); ++i)
			{
				if (_dict[i]._word == word) {
					++_dict[i]._frequency;
					break;
				}
			}
			//���ɨ�����˻�û���ҵ��������
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
		//ofs������cout,cout�ǽ��������뵽terminal�ϣ�ofs���������ָ���ļ���ȥ
		ofs << _dict[i]._word << "--->" << _dict[i]._frequency << endl;
	}
	ofs.close();
}