#include <string>
#include "CollegeCourse.h"
using namespace std;
#ifndef LABCOURSE_H
#define LABCOURSE_H
class LabCourse:public CollegeCourse {
private:
	int labFee;
public:
	//constructor
	LabCourse(string = "NULL", int = 0, int = 0, string = "NULL", int = 0, int = 0);
	//get
	int getLabFee() const;
	//set
	bool setLabFee(int);
	//redefined function
	void display() const;
};
#endif