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
	Course() {};
	Course(std::string name)
	{
		this->name = name;
	}
	Course(std::string name, std::string grade)
	{
		this->name = name;
		this->grade = grade;
	}
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
	friend std::ostream& operator<< (std::ostream& stream, const Course& course)
	{
		std::cout << "Course name: " << course.name << endl;
		std::cout << "Course credits: " << course.credits << endl;
		std::cout << "Student grade: " << course.grade;
		return stream;
	}
};