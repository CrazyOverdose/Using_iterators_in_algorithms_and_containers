#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_vector(const vector<size_t>& a) {
	for (const auto& i : a) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	size_t n;
	cin >> n;

	vector <size_t> result;

	for (size_t i = n; i >= 1; --i) {
		result.push_back(i);
	}
	do {
		print_vector(result);
	} while (std::prev_permutation(result.begin(), result.end()));
}
//Ввод: 3
//Вывод: 
//3 2 1
//3 1 2
//2 3 1
//2 1 3
//1 3 2
//1 2 3
//