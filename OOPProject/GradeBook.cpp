#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <map>
#include "Student.h"
#include "GradeBook.h"
#include "MarkOps.h"

using namespace std;

int GradeBook::gradeBookIdOffset = 0;

GradeBook::GradeBook(string schoolClassName) {
	this->id = gradeBookIdOffset;
	this->schoolClassName = schoolClassName;
	gradeBookIdOffset++;
}

int GradeBook::getGradeBookIdOffset()
{
	return gradeBookIdOffset;
}

void GradeBook::addScoresForTest(StudentTest& test) {
	test.print();
	int maxScore = test.getMaxScore();
	for (int i = 0; i < this->studentVector.size(); i++) {
		studentVector[i].print();
		int a;
		while (true)
		{
			cout << "Score: ";
			cin >> a;
			if (a > maxScore || a < 0)
				cout << "Wrong score, try again." << endl;
			else
				break;
		}
		studentVector[i].addScore(test.getId(), a, test.getMaxScore());
	}
}

void GradeBook::addStudent(Student &student) {
	this->studentVector.push_back(student);
}

vector<Student> GradeBook::getStudents()
{
	return this->studentVector;
}

void GradeBook::setStudents(vector<Student> studentsVector)
{
	this->studentVector = studentsVector;
}

vector<StudentTest> GradeBook::getStudentTests()
{
	return this->studentTestVector;
}

void GradeBook::setStudentTests(vector<StudentTest> studentTestsVector)
{
	this->studentTestVector = studentTestsVector;
}

void GradeBook::addTest(StudentTest& test) {
	this->studentTestVector.push_back(test);
}

void GradeBook::printTests() {
	cout << "Class name: " << this->schoolClassName << endl;
	for (int i = 0; i < this->studentTestVector.size(); i++) {
		cout << i + 1 << ". ";
		studentTestVector[i].print();
	}
}

void GradeBook::printTestWithScores(int i) {
	StudentTest test = this->getTest(i);
	test.print();
	cout << "Scores: " << endl;
	for (int i = 0; i < this->studentVector.size(); i++) {
		studentVector[i].print();
		cout << "Score: ";
		cout << studentVector[i].getScoresMap()[test.getId()] << "/" << test.getMaxScore() << " Mark: " << studentVector[i].getMarksMap()[test.getId()] << endl;
	}
}

int GradeBook::getId() {
	return this->id;
}

string GradeBook::getName()
{
	return this->schoolClassName;
}

float GradeBook::getStudentMean(Student& student) {
	return student.getMeanMark();
}

void GradeBook::printStudentsMean() {
	for (int i = 0; i < studentVector.size(); i++) {
		studentVector[i].print();
		cout << "GPA: " << getStudentMean(studentVector[i]) << endl;
	}
}

float GradeBook::getClassMean() {
	int count = 0;
	float totalMark = 0;
	for (int i = 0; i < studentVector.size(); i++) {
		for (auto const& x : studentVector[i].getMarksMap()) {
			count++;
			totalMark +=  stof(x.second);
			}
	}
	return (float)totalMark / count;
}

void GradeBook::printStudents() {
	cout << "Class name: " << this->schoolClassName << endl;
	for (int i = 0; i < this->studentVector.size(); i++) {
		studentVector[i].print();
	}
}

int GradeBook::getStudentTestVectorSize() {
	return studentTestVector.size();
}

StudentTest GradeBook::getTest(int i)
{
	return studentTestVector[i];
}