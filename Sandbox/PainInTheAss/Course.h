#pragma once
#include <iostream>
#include <string>

class Course
{
private:
	std::string name;
	std::string credits;
	std::string grade;
public:
	~Course() {}
	Course() {};
	std::string getName()
	{
		return this->name;
	}
	void setName(std::string name)
	{
		this->name = name;
	}
	std::string getCredits()
	{
		return this->credits;
	}
	void setCredits(std::string credits)
	{
		this->credits = credits;
	}
	std::string getGrade()
	{
		return this->grade;
	}
	void setGrade(std::string grade)
	{
		this->grade = grade;
	}
	friend std::ostream& operator<< (std::ostream& stream, const Course& course)	// Overrides the std::cout when printing out class object
	{
		std::cout << "\tCourse name: " << course.name << std::endl;
		std::cout << "\tCourse credits: " << course.credits << std::endl;
		std::cout << "\tStudent grade: " << course.grade << std::endl;
		return stream;
	}
};