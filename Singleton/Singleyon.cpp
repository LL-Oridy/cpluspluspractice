#include<iostream>

using std::cout;
using std::endl;

//单例模式，一个类只能创建一个对象
class Singleton {
public:
	static Singleton *getInstance() {
		if (nullptr == _pInstance) {
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destory() {
		if (_pInstance) {
			delete _pInstance;
			_pInstance = nullptr;
		}
	}
private:
	Singleton() {
		cout << "Singleton()" << endl;
	}
	~Singleton() {
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton* _pInstance;
};

Singleton* Singleton::_pInstance = nullptr;

int main() {
	Singleton* ps1 = Singleton::getInstance();
	Singleton* ps2 = Singleton::getInstance();

	cout << "ps1 = " << ps1 << endl;
	cout << "ps2 = " << ps2 << endl;

	Singleton::destory();
	return 0;
}