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
	Student(std::string name)
	{
		this->name = name;
	}
	LinkedList<Course> getCourses()
	{
		return this->courses;
	}
	friend std::ostream& operator<<(std::ostream& os, const Student& st)
	{
		os << "Student name: " << st.name << endl;
		
		return os;
	}
};
