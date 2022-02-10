#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "Student.h"
#include "MarkOps.h"

using namespace std;

int Student::studentIdOffset = 0;

Student::Student(string name, string lastName) {
	this->id = studentIdOffset;
	this->name = name;
	this->lastName = lastName;
	studentIdOffset++;
}

Student::Student(int id, string name, string lastName, map<int, int> scoresMap, map<int, string> marksMap)
{
	this->id = id;
	this->name = name;
	this->lastName = lastName;
	this->testResultsMap = scoresMap;
	this->testMarksMap = marksMap;
}

void Student::addScore(int testId, int score, int maxScore) {
	this->testResultsMap.insert(pair<int,int>(testId, score));
	this->testMarksMap.insert(pair<int, string>(testId, MarkOps::getMark(score, maxScore)));
}

map<int, string> Student::getMarksMap() {
	return this->testMarksMap;
}

int Student::getId()
{
	return this->id;
}

void Student::setId(int id)
{
	this->id = id;
}

string Student::getName()
{
	return this->name;
}

string Student::getLastName()
{
	return this->lastName;
}

void Student::setTestResultsMap(map<int, int> testResultsMap)
{
	this->testResultsMap = testResultsMap;
}

void Student::setTestMarksMap(map<int, string> testMarksMap)
{
	this->testMarksMap = testMarksMap;
}

map<int,int> Student::getScoresMap() {
	return this->testResultsMap;
}

float Student::getMeanMark() {
	float totalMarks = 0;
	int count = 0;
	for (auto const& x : this->testMarksMap) {
		totalMarks += stof(x.second);
		count++;
	}
	return totalMarks / count;
}

void Student::print() {
	cout << "ID: " << this->id << " Name: " << this->name << " Last name: " << this->lastName << endl;
}