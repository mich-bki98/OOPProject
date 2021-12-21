#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.cpp"

using namespace std;

class GradeBook {
private:
	int id;
	vector<Student> studentVector;
	static int gradeBookIdOffset;
public:
	GradeBook() {

	}
};