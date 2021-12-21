#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"
#include "GradeBook.h"

using namespace std;

int GradeBook::gradeBookIdOffset = 0;

GradeBook::GradeBook(string schoolClassName) {
	this->id = gradeBookIdOffset;
	this->schoolClassName = schoolClassName;
	gradeBookIdOffset++;
}

void GradeBook::addStudent(Student &student) {
	this->studentVector.push_back(student);
}

void GradeBook::printStudents() {
	cout << "Class name: " << this->schoolClassName << endl;
	for (int i = 0; i < this->studentVector.size(); i++) {
		studentVector[i].print();
	}
}