#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "StudentTest.h"

using namespace std;

class Student {
private:
	int id;
	string name;
	string lastName;
	vector<int> testResultsVector;
	static int studentIdOffset;
public:

	Student() { }

	Student(string name, string lastName);

	void print();

};