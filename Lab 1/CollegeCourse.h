#include <string>
using namespace std;
#ifndef COLLEGECOURSE_H
#define COLLEGECOURSE_H
class CollegeCourse {
private:
	string courseDepartment;
	int courseNumber;
	int courseUnits;
	string courseName;
	int courseFee;
public:
	//constructor
	CollegeCourse();
	CollegeCourse(string, int, int, string, int);
	//set
	void setCourseDepartment(string);
	void setCourseNumber(int);
	bool setCourseUnits(int);
	void setCourseName(string);
	bool setCourseFee(int);
	//get
	string getCourseDepartment() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	string getCourseName() const;
	int getCourseFee() const;
	//other member function
	void display() const;
};
#endif 