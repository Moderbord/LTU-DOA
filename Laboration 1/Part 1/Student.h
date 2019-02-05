#pragma once
#include "LinkedList.h"
#include "Course.h"
#include <string>
#include <iostream>

class Student
{
private:
	std::string name;
	LinkedList<Course> courses;
public:
	~Student() {}
	Student() {};
	Student(const std::string name)
	{
		this->name = name;
	}
	std::string& getName()
	{
		return this->name;
	}
	LinkedList<Course>& getCourseList()
	{
		return this->courses;
	}
	friend std::ostream& operator<< (std::ostream& stream, Student* student)
	{
		std::cout << "\t" << student->name;
		return stream;
	}
	void removeCourse(int i)
	{
		this->courses.remove(i);
	}
	void displayCourses()
	{
		this->courses.display();
	}
};
