#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
#include "DataHandler.h"
#include "GradeBook.h"
#include "Student.h"
#include "StudentTest.h"

using namespace std;


/*
Scheme:
	tokens are values that allow to get around *txt save file
	splitted by , delimiter.

	gradebook.size\n
	gradebook.id,gradebook.name,students.size,tests.size\n
	students,\n
	[student0.id,student0.name,student0.lastName,student0.scoresMap,student0.marksMap,
	.
	.
	.
	studentN.id,studentN.name,studentN.lastName,studentN.scoresMap,studentN.marksMap,],\n
	studentTests,\n
	[studentTest0.id,studentTest0.name,studentTest0.subject,studentTest0.maxScore,studentTest0.date,
	.
	.
	.
	studentTestN.id,studentTestN.name,studentTestN.subject,studentTestN.maxScore,studentTestN.date,],\n
	gradebook<id>,\n
	for scores and marks map:

	[,k1,v1, ... ,kN,vN],

*/


void DataHandler::updateOffsets(int gradeBookOffset, int studentOffset, int studentTestOffset)
{
	GradeBook::gradeBookIdOffset = gradeBookOffset;
	Student::studentIdOffset = studentOffset;
	StudentTest::studentTestIdOffset = studentTestOffset;
}

vector<GradeBook> DataHandler::loadData() {
	ifstream in("data.txt");
	string contents((istreambuf_iterator<char>(in)),istreambuf_iterator<char>());

	vector<GradeBook> gradeBooks;

	vector<string> linesVec;

	size_t pos = 0;

	while((pos = contents.find("\n")) != string::npos) {
		linesVec.push_back(contents.substr(0, pos));
		contents.erase(0, pos + 1);
	}
	linesVec.push_back(contents);

	vector<string> tokensVec;

	pos = 0;
	for (int i = 0; i < linesVec.size(); i++) {
		while ((pos = linesVec[i].find(',')) != string::npos) {
			tokensVec.push_back(linesVec[i].substr(0, pos));
			linesVec[i].erase(0, pos + 1);
		}
	}

	int gradeBooksCount = stoi(tokensVec[0]);
	int studentOffset = stoi(tokensVec[1]);
	int studentTestOffset = stoi(tokensVec[2]);
	tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 3);

	for (int i = 1; i <= gradeBooksCount; i++) {
		tokensVec.erase(tokensVec.begin());
		string className = tokensVec[0];
		int studentsCount = stoi(tokensVec[1]);
		int testsCount = stoi(tokensVec[2]);

		GradeBook* gradeBook = new GradeBook(className);

		tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 4);
		for (int j = 0; j < studentsCount; j++) {

			int studentId = stoi(tokensVec[0]);
			string studentName = tokensVec[1];
			string studentLastName = tokensVec[2];

			tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 3);


			//erase [
			tokensVec.erase(tokensVec.begin());

			map<int, int> scores;
			map<int, string> marks;

			for (int k = 0; k < testsCount; k++) {
				scores.insert(pair<int, int>(stoi(tokensVec[0]), stoi(tokensVec[1])));
				tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 2);
			}

			//erase ],[,
			tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 2);

			for (int k = 0; k < testsCount; k++) {
				marks.insert(pair<int, string>(stoi(tokensVec[0]), tokensVec[1]));
				tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 2);
			}

			//erase ],
			tokensVec.erase(tokensVec.begin());

			Student* student = new Student(studentId, studentName, studentLastName, scores, marks);

			gradeBook->addStudent(*student);
		}
		//erase studentsTests,
		tokensVec.erase(tokensVec.begin());
		for (int j = 0; j < testsCount; j++) {
			StudentTest* studentTest = new StudentTest(stoi(tokensVec[0]), tokensVec[1], tokensVec[2], stoi(tokensVec[3]), tokensVec[4]);
			tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 5);
			gradeBook->addTest(*studentTest);
		}
		//erase gradebook,gradebook.name
		tokensVec.erase(tokensVec.begin(), tokensVec.begin() + 2);
		gradeBooks.push_back(*gradeBook);
	}

	updateOffsets(gradeBooksCount,studentOffset, studentTestOffset);

	return gradeBooks;
}

void DataHandler::saveData(vector<GradeBook> gradeBooks) {
	ofstream file;
	file.open("data.txt", std::ofstream::out | std::ofstream::trunc);
	if (!gradeBooks.empty()) {
		file << to_string(gradeBooks[0].getGradeBookIdOffset()) + "," + to_string(Student::studentIdOffset) + "," + to_string(StudentTest::studentTestIdOffset) + ",\n";
		for (int i = 0; i < gradeBooks.size(); i++) {
			string saveBuffer = "gradebook," + gradeBooks[i].getName() + "," + to_string(gradeBooks[i].getStudents().size()) + "," + to_string(gradeBooks[i].getStudentTests().size()) + ",\n";
			saveBuffer += "students,\n";
			for (int j = 0; j < gradeBooks[i].getStudents().size(); j++) {
				Student student = gradeBooks[i].getStudents()[j];
				saveBuffer += to_string(student.getId()) + "," + student.getName() + "," + student.getLastName() + ",[,";
				for (auto const& x : student.getScoresMap()) {
					saveBuffer += to_string(x.first) + "," + to_string(x.second) + ",";
				}
				saveBuffer += "],[,";
				for (auto const& x : student.getMarksMap()) {
					saveBuffer += to_string(x.first) + "," + x.second + ",";
				}
				saveBuffer += "],\n";
			}
			saveBuffer += "studentTests,\n";
			for (int j = 0; j < gradeBooks[i].getStudentTests().size(); j++) {
				StudentTest studentTest = gradeBooks[i].getStudentTests()[j];
				saveBuffer += to_string(studentTest.getId()) + "," + studentTest.getName() + "," + studentTest.getSubject() + "," + to_string(studentTest.getMaxScore()) + "," + studentTest.getDate() + ",";
			}
			saveBuffer += "\ngradebook," + gradeBooks[i].getName() + ",\n";
			file << saveBuffer;
		}
	}

	
	file.close();
}