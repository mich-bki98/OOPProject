#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"

using namespace std;

class GradeBook {
private:
	int id;
	vector<Student> studentVector;
	vector<StudentTest> studentTestVector;
	string schoolClassName;
	static int gradeBookIdOffset;
public:

	GradeBook() { }

	GradeBook(string schoolClassName);

	void addStudent(Student &student);

	void printStudents();
};