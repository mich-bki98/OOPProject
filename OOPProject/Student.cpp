#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "SchoolClass.cpp"
#include "StudentTest.cpp"

using namespace std;

class Student {
private:
	int id;
	string name;
	string lastName;
	SchoolClass schoolClass;
	vector<StudentTest> studentTestsVector;
	static int studentIdOffset;
public:

	Student(string name, string lastName, SchoolClass schoolClass) {
		this->id = studentIdOffset;
		this->name = name;
		this->lastName = lastName;
		this->schoolClass = schoolClass;
	}

	

};