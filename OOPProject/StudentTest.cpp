#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>
#include <string>
#include "StudentTest.h"

using namespace std;

int StudentTest::studentTestIdOffset = 0;

string StudentTest::getTimestamp() {
	struct tm tm_local;
	time_t now = time(0);
	localtime_s(&tm_local, &now);

	string day = to_string(tm_local.tm_mday);
	string month = to_string(1 + tm_local.tm_mon);
	string year = to_string(tm_local.tm_year + 1900);

	return day + "/" + month + "/" + year;
}

string StudentTest::getName()
{
	return this->name;
}

string StudentTest::getSubject()
{
	return this->subject;
}

int StudentTest::getId() {
	return this->id;
}

int StudentTest::getMaxScore() {
	return this->maxScore;
}

string StudentTest::getDate()
{
	return this->date;
}

StudentTest::StudentTest(string name, string subject, int maxScore) {
	this->id = studentTestIdOffset;
	studentTestIdOffset += 1;
	this->subject = subject;
	this->name = name;
	this->date = getTimestamp();
	this->maxScore = maxScore;
}

StudentTest::StudentTest(int id, string name, string subject, int maxScore, string date)
{
	this->id = id;
	this->name = name;
	this->subject = subject;
	this->maxScore = maxScore;
	this->date = date;
}

void StudentTest::print() {
	cout << "Test: " << endl << "Id: " << this->id << " Subject: " << this->subject << " Test name: " << this->name << " Date: " << this->date << " Max score: " << this->maxScore << endl;
}