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
	time_t date;
	static int studentTestIdOffset;
public:

	StudentTest() { }

	StudentTest(string name, string subject, int maxScore);

	~StudentTest() { }

};