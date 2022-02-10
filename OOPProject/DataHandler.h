#pragma once
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <fstream>
#include "GradeBook.h"

using namespace std;

struct DataHandler {
private:
	string getNextToken(string content);
	void static updateOffsets(int gradeBookOffset, int studentOffset, int studentTestOffset);
public:
	static vector<GradeBook> loadData();
	static void saveData(vector<GradeBook> gradeBooks);
};