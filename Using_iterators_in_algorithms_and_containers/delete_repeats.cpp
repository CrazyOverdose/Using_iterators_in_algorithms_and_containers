#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
	sort(elements.begin(), elements.end());
	auto iter = unique(elements.begin(), elements.end());
	elements.erase(iter, elements.end());
}

int main() {
	vector<int> v1 = { 6, 4, 7, 6, 4, 4, 0, 1 };
	RemoveDuplicates(v1);
	for (int x : v1) {
		cout << x << " ";
	}
	cout << endl;

	vector<string> v2 = { "C", "C++", "C++", "C", "C++" };
	RemoveDuplicates(v2);
	for (const string& s : v2) {
		cout << s << " ";
	}
	cout << endl;
	return 0;
}
//Вывод (Порядок элементов может быть другим):
//6 4 7 0 1
//C++ C