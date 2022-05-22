#include <string>
#include <iostream>
#include "CollegeCourse.h"
#include "LabCourse.h"
using namespace std;
//constructor
LabCourse::LabCourse(string cd, int cn, int cu, string cnm, int cf, int lf) :CollegeCourse(cd, cn, cu, cnm, cf) {
	labFee = lf;
}
//get
int LabCourse::getLabFee() const {
	return labFee;
}
//set
bool LabCourse::setLabFee(int lf) {
	if (lf > 0) {
		labFee = lf;
		return true;
	}
	else {
		labFee = 0;
		return false;
	}
}
//redefined function
void LabCourse::display() const {
	cout << "Course Department: " << getCourseDepartment()<<endl;
	cout << "Course Number: " << getCourseNumber() << endl;
	cout << "Course Number of Units: " << getCourseUnits() << endl;
	cout << "Course Name: " << getCourseName() << endl;
	cout << "Course Fee: " << getCourseFee() << endl;
	cout << "Additional Lab Fee: " << getLabFee() << endl;
	cout << "Total Course Cost: " << getCourseFee() + getLabFee() << endl;
}
