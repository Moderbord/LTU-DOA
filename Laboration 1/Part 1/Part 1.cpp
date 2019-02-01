#include "pch.h"
#include "LinkedList.h"
#include "StudentDatabase.h"
#include <iostream>
#include <string>

namespace {
	using std::cout;
	using std::cin;
	using std::endl;
	using std::getline;
	using std::string;
}

int main()
{
	//StudentDatabase sdb;

	LinkedList<Student> studentDB;
	string input;

	do
	{
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Attach course to student" << endl;
		cout << "4. Detach course from student" << endl;
		cout << "5. Exit";

		getline(cin, input);

		switch (input[0])
		{
		case 1:
			// add student
			getline(cin, input);
			//sdb.addStudent(input);
			break;
		case 2:
			// remove student;
			//sdb.printStudents();
			getline(cin, input);
			//sdb.removeStudent(input[0]);
			break;
		case 3:
			// add student course
			//sdb.printStudents();
			getline(cin, input);
			//sbd.attachStudentCourse(input[0]);
			break;
		case 4:
			// remove student course
			//sdb.printStudents();
			getline(cin, input);
			//sdb.detachStudentCourse(input[0]);
		default:
			break;
		}
	} while (input[0] != 5);
}
