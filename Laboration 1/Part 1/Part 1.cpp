#include "pch.h"
#include "LinkedList.h"
#include "Student.h"
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
	string input;

	LinkedList<Student> studentRecord;

	do
	{
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Attach course to student" << endl;
		cout << "4. Detach course from student" << endl;
		cout << "0. Exit" << endl;
		cout << ">> ";

		getline(cin, input);

		switch (input[0])
		{
		case '1':	// Add student
			{
				cout << "\nStudent name: ";
				getline(cin, input);

				Node<Student> *newNode = new Node<Student>();
				Student *newStudent = new Student(input);

				newNode->setData(newStudent);
				studentRecord.insert(newNode);

				cout << "Added " << newStudent->getName() << "\n\n";
			}
			break;

		case '2':	// Remove student

			if (studentRecord.isEmpty())
			{
				cout << "\nNo registered students\n\n";
				break;
			}
			cout << endl << "--- CURRENT STUDENTS ---\n";
			studentRecord.display();
			cout << "\nSelect student: ";

			getline(cin, input);
			studentRecord.remove(input[0] - '0');
			break;

		case '3':	// Add course

			if (studentRecord.isEmpty())
			{
				cout << "\nNo registered students\n" << endl;
				break;
			}
			cout << "\n--- CURRENT STUDENTS ---\n";
			studentRecord.display();
			cout << "\nSelect student: ";

			getline(cin, input);
			{
				Node<Student> *studentNode = studentRecord.get(input[0] - '0');
				Student *student = studentNode->getData();
				Node<Course> *courseNode = new Node<Course>();
				Course *newCourse = new Course();

				cout << "\nSelected student: " << student->getName() << endl;
				cout << "\n--- CURRENT COURSES ---\n\n";
				student->getCourseList().display();

				cout << "Name of course: ";
				getline(cin, input);
				newCourse->setName(input);
				cout << "Course credits: ";
				getline(cin, input);
				newCourse->setCredits(input);
				cout << "Student grade: ";
				getline(cin, input);
				newCourse->setGrade(input);

				courseNode->setData(newCourse);
				student->attachCourse(courseNode);

				cout << "\nCourse added\n\n";
			}
			break;

		case '4':	// Remove course

			// remove student course
			//sdb.printStudents();
			getline(cin, input);
			//sdb.detachStudentCourse(input[0]);
			break;

		default:
			break;
		}
	} while (input[0] != '0');
}
