#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <map>
#include "StudentTest.h"

using namespace std;

class Student {
private:
	int id;
	string name;
	string lastName;
	map<int,int> testResultsMap;
	map<int, string> testMarksMap;
public:
	static int studentIdOffset;

	Student() { }

	int getId();

	void setId(int id);

	string getName();

	string getLastName();

	void setTestResultsMap(map<int, int> testResultsMap);

	void setTestMarksMap(map<int, string> testMarksMap);

	map<int, int> getScoresMap();

	map<int, string> getMarksMap();

	float getMeanMark();

	void addScore(int testId, int testScore,int maxScore);

	Student(string name, string lastName);

	Student(int id, string name, string lastName, map<int, int> scoresMap, map<int, string> marksMap);

	void print();

};