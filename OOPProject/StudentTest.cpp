#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>
#include "StudentTest.h"

using namespace std;

int StudentTest::studentTestIdOffset = 0;

StudentTest::StudentTest(string name, string subject, int maxScore) {
	this->id = studentTestIdOffset;
	studentTestIdOffset += 1;
	this->subject = subject;
	this->name = name;
	this->date = time(0);
}