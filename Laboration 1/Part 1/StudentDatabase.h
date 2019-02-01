#pragma once
#include "LinkedList.h"
#include "Node.h"
#include "Student.h"
#include <iostream>

class StudentDatabase
{
private:
	LinkedList<Student> studentDB;

public:
	void addStudent(std::string name)
	{
		Student student(name);

		Node<Student> *studentNode = new Node<Student>();
		studentNode->setData(student);
		
		studentDB.insert(studentNode);
	};
	void removeStudent(int i)
	{
		studentDB.remove(i);
	};
	void attachStudentCourse(int i)
	{

	};
	void detachStudentCourse(int i)
	{

	};
	void printStudents()
	{
		studentDB.display();
	};
};

