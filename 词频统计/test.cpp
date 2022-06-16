#include"struct.h"

void test() {
	Dictionary dic;
	dic.read("The_Holy_Bible.txt");
	dic.write("wordcount.txt");
}

int main() {
	test();
	return 0;
}