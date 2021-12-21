#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"

using namespace std;

int Student::studentIdOffset = 0;

Student::Student(string name, string lastName) {
	this->id = studentIdOffset;
	this->name = name;
	this->lastName = lastName;
	studentIdOffset++;
}

void Student::print() {
	cout << "ID: " << this->id << " Name: " << this->name << " Last name: " << this->lastName << endl;
}