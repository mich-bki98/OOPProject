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
public:
	static int gradeBookIdOffset;

	GradeBook() { }

	GradeBook(string schoolClassName);

	int getGradeBookIdOffset();

	int getId();

	string getName();

	void addStudent(Student &student);

	vector<Student> getStudents();

	void setStudents(vector<Student> studentsVector);

	vector<StudentTest> getStudentTests();
	
	void setStudentTests(vector<StudentTest> studentTestsVector);

	void printTestWithScores(int i);

	float getStudentMean(Student& student);

	void printStudentsMean();

	float getClassMean();

	void addTest(StudentTest& test);

	void addScoresForTest(StudentTest& test);

	void printStudents();

	void printTests();

	int getStudentTestVectorSize();

	StudentTest getTest(int i);
};