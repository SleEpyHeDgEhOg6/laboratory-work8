#include <iostream>
#include <cstring>
using namespace std;

char* CopyString(const char* str) {
	int len = 0;
	while (str[len] != '\0') {//'\0'-нулевой символ в строке(самый последний)
		++len;
	}
	char* wr = new char[len+1];//+1 для нулевого символа 
	memcpy(wr, str, len);
	wr[len] = '\0';//добавление нулевого символа
	return wr;
}


int main() {
	const char* o = "Original";
	char* cop = CopyString(o);
	std::cout << "--" << cop << "--" << std::endl;
	delete[] cop;
	return 0;
}

char* ConcatinateStrings(const char* a, const char* b) {
	int len_a = 0;
	int len_b = 0;
	while (a[len_a] != '\0') {
		++len_a;
	}
	while (b[len_b] != '\0') {
		++len_b;
	}
	char* wt = new char[len_a + len_b + 1];//+1 для нулевого символа 
	memcpy(wt, a, len_a);
	memcpy(wt + len_a, b, len_b);
	wt[len_a + len_b] = '\0';
	return wt;
}

int main1() {
	const char* o = "original";
	const char* k = "end";
	char* ot = ConcatinateStrings(o, k);
	std::cout << "--" << ot << "--" << std::endl;
	delete[] ot;
	return 0;
}
