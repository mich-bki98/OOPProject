#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

class StudentTest {
private:
	int id;
	string name;
	string subject;
	int maxScore;
	string date;
	string getTimestamp();
public:
	static int studentTestIdOffset;

	int getId();

	string getName();
	
	string getSubject();

	string getDate();

	int getMaxScore();

	StudentTest() { }

	StudentTest(string name, string subject, int maxScore);

	StudentTest(int id, string name, string subject, int maxScore, string date);

	void print();

	~StudentTest() { }

};