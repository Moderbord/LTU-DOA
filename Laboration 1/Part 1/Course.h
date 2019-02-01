#pragma once
#include <iostream>
#include <string>

class Course
{
private:
	std::string name;
	std::string grade;
public:
	Course(std::string name)
	{
		this->name = name;
	}
	void setGrade(std::string grade)
	{
		this->grade = grade;
	}
	std::string getGrade()
	{
		return this->grade;
	}
	friend std::ostream& operator<<(std::ostream& os, Course& cs)
	{
		os << "Course name: " << cs.name << endl;
		os << "Course grade: " << cs.grade << endl;
	}
};