#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

class StudentTest{
private:
	int id;
	string name;
	string subject;
	int maxScore;
	int result;
	time_t date;
	static int studentTestIdOffset;
public:
	StudentTest(string name, string subject, int maxScore, int result) {
		this->id = studentTestIdOffset;
		studentTestIdOffset += 1;
		this->subject = subject;
		this->name = name;
		this->result = result;
		this->date = time(0);
	}

	~StudentTest() {}


};