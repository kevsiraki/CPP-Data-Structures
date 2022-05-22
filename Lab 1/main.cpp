//main to test all get/set/constructor/display functions for both base and inherited/derived class
#include <iostream>
#include <string>
#include "CollegeCourse.h"
#include "LabCourse.h"
using namespace std;
int main() {
	CollegeCourse regularCourseOne; //using first constructor
	LabCourse labCourseOne;
	CollegeCourse regularCourseTwo("CSIS",211,4,"Data Structures",100); //using second constructor
	LabCourse labCourseTwo("PHYS", 102, 5, "Electricity and Magnetism", 150,50);
	//displaying info of the course instances that used the second constructor
	regularCourseTwo.display();
	cout << endl;
	labCourseTwo.display();
	//using set methods and get methods to display information about the course instances made with the first constructor
	//regular course
	regularCourseOne.setCourseDepartment("MATH");
	regularCourseOne.setCourseNumber(104);
	regularCourseOne.setCourseUnits(5);
	regularCourseOne.setCourseName("Calculus II");
	regularCourseOne.setCourseFee(170);
	cout << endl << "Printing Regular Course Info With Gets: " << endl;
	cout << "Course Department: " << regularCourseOne.getCourseDepartment() << endl;
	cout << "Course Number: " << regularCourseOne.getCourseNumber() << endl;
	cout << "Course Number of Units: " << regularCourseOne.getCourseUnits() << endl;
	cout << "Course Name: " << regularCourseOne.getCourseName() << endl;
	cout << "Course Fee: " << regularCourseOne.getCourseFee() << endl;
	//lab course
	labCourseOne.setCourseDepartment("GEOL");
	labCourseOne.setCourseNumber(111);
	labCourseOne.setCourseUnits(1);
	labCourseOne.setCourseName("Geology Lab");
	labCourseOne.setCourseFee(50);
	labCourseOne.setLabFee(10);
	cout << endl << "Printing Lab Course Info With Gets: " << endl;
	cout << "Course Department: " << labCourseOne.getCourseDepartment() << endl;
	cout << "Course Number: " << labCourseOne.getCourseNumber() << endl;
	cout << "Course Number of Units: " << labCourseOne.getCourseUnits() << endl;
	cout << "Course Name: " << labCourseOne.getCourseName() << endl;
	cout << "Course Fee: " << labCourseOne.getCourseFee() << endl;
	cout << "Additional Lab Fee: " << labCourseOne.getLabFee() << endl;
	cout << "Total Course Cost: " << labCourseOne.getCourseFee() + labCourseOne.getLabFee() << endl;
	return 0;
}
