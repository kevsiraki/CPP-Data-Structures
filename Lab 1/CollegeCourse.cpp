#include <string>
#include <iostream>
#include "CollegeCourse.h"
using namespace std;
//constructor
CollegeCourse::CollegeCourse() {
	courseDepartment = "NULL";
	courseNumber=0;
	courseUnits=0;
	courseName="NULL";
	courseFee=0;
}
CollegeCourse::CollegeCourse(string cd, int cn, int cu, string cnm, int cf) {
	courseDepartment = cd;
	courseNumber = cn;
	courseUnits = cu;
	courseName = cnm;
	courseFee = cf;
}
//set
void CollegeCourse::setCourseDepartment(string cd) {
	courseDepartment = cd;
}
void CollegeCourse::setCourseNumber(int cn) {
	courseNumber = cn;
}
bool CollegeCourse::setCourseUnits(int cu) {
	if (cu > 0) {
		courseUnits = cu;
		return true;
	}
	else {
		courseUnits = 0;
		return false;
	}
}
void CollegeCourse::setCourseName(string cnm) {
	courseName = cnm;
}
bool CollegeCourse::setCourseFee(int cf) {
	if (cf > 0) {
		courseFee = cf;
		return true;
	}
	else {
		courseFee = 0;
		return false;
	}
}
//get
string CollegeCourse::getCourseDepartment() const {
	return courseDepartment;
}
int CollegeCourse::getCourseNumber() const {
	return courseNumber;
}
int CollegeCourse::getCourseUnits() const {
	return courseUnits;
}
string CollegeCourse::getCourseName() const {
	return courseName;
}
int CollegeCourse::getCourseFee() const {
	return courseFee;
}
//other member function
void CollegeCourse::display() const {
	cout << "Course Department: " << getCourseDepartment() << endl;
	cout << "Course Number: " << getCourseNumber() << endl;
	cout << "Course Number of Units: " << getCourseUnits() << endl;
	cout << "Course Name: " << getCourseName() << endl;
	cout << "Course Fee: " << getCourseFee() << endl;
}