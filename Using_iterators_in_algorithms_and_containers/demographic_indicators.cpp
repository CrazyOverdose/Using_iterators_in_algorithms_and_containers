#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum class Gender {
	FEMALE,
	MALE
};

struct Person {
	int age;  // возраст
	Gender gender;  // пол
	bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
	if (range_begin == range_end) {
		return 0;
	}
	vector<typename InputIt::value_type> range_copy(range_begin, range_end);
	auto middle = begin(range_copy) + range_copy.size() / 2;
	nth_element(
		begin(range_copy), middle, end(range_copy),
		[](const Person& lhs, const Person& rhs) {
		return lhs.age < rhs.age;
	}
	);
	return middle->age;
}

vector <Person>::iterator sort(vector < Person> my_vector, vector <Person>::iterator b, vector <Person>::iterator c) {
	sort(b, c, [](Person a, Person b) {
		if (a.is_employed == true && b.is_employed == false)
			return true;
		return false;
	});

	auto iter = find_if(b, c, [](Person a) {
		return a.is_employed == false;
	});

	return iter;
}

void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;

	sort(persons.begin(), persons.end(), [](Person a, Person b) {
		if (a.gender == Gender::FEMALE && b.gender == Gender::MALE)
			return true;
		return false;
	});

	auto iter1 = find_if(persons.begin(), persons.end(), [](Person a) {
		return a.gender == Gender::MALE;
	});

	cout << "Median age for females = " << ComputeMedianAge(persons.begin(), iter1) << endl;
	cout << "Median age for males = " << ComputeMedianAge(iter1, persons.end()) << endl;

	vector <Person>::iterator iter2 = sort(persons, persons.begin(), iter1);

	cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), iter2) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(iter2, iter1) << endl;

	vector <Person>::iterator iter3 = sort(persons, iter1, persons.end());

	cout << "Median age for employed males = " << ComputeMedianAge(iter1, iter3) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(iter3, persons.end()) << endl;
}

int main() {
	vector<Person> persons = {
		{31, Gender::MALE, false},
		{40, Gender::FEMALE, true},
		{24, Gender::MALE, true},
		{20, Gender::FEMALE, true},
		{80, Gender::FEMALE, false},
		{78, Gender::MALE, false},
		{10, Gender::FEMALE, false},
		{55, Gender::MALE, true},
	};
	PrintStats(persons);
	return 0;
}

//Вывод:
//Median age = 40
//Median age for females = 40
//Median age for males = 55
//Median age for employed females = 40
//Median age for unemployed females = 80
//Median age for employed males = 55
//Median age for unemployed males = 78