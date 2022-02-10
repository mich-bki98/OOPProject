#include<cmath>
#include<string>

using namespace std;

struct MarkOps {
	static string getMark(int score, int maxScore) {
		float percentage = (float)score / (float)maxScore * 100;
		if (percentage < 30) {
			return "1";
		}
		else if (percentage < 45) {
			return "2";
		}
		else if (percentage < 55) {
			return "2.5";
		}
		else if (percentage < 65) {
			return "3";
		}
		else if (percentage < 70) {
			return "3.5";
		}
		else if (percentage < 75) {
			return "4";
		}
		else if (percentage < 80) {
			return "4.5";
		}
		else if (percentage < 90) {
			return "5";
		}
		else if (percentage < 100) {
			return "5.5";
		}
		else {
			return "6";
		}
  	}
};