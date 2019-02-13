#pragma once
#include "Array.h"
#include "Course.h"
#include <string>
#include <iostream>

class Student
{
private:
	std::string name;
	Array<Course> courses;
public:
	~Student()
	{
		
	}
	Student() {};
	Student(const std::string name)
	{
		this->name = name;
	}
	std::string getName()
	{
		return this->name;
	}
	Array<Course>& getCourseList()
	{
		return this->courses;
	}
	void removeCourse(int i)
	{
		this->courses.remove(i);
	}
	void displayCourses()
	{
		this->courses.display();
	}
	friend std::ostream& operator<< (std::ostream& stream, const Student& student)	// Overrides the std::cout when printing out class object
	{
		std::cout << "\t" << student.name;
		return stream;
	}
};
