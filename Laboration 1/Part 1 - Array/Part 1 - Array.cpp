#include "pch.h"
#include "Array.h"
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
	Array<Student> studentRecord;

	for (int j = 1; j < 11; j++)										// Loop that creates 10 students with 10 courses each
	{
		Student student(std::to_string(j));
		studentRecord.insertSkipMeasure(student);

		for (int i = 1; i < 11; i++)
		{
			Course course;
			string s = std::to_string(i);
			course.setName(s);
			course.setCredits(s);
			course.setGrade(s);

			studentRecord.get(j).getCourseList().insertSkipMeasure(course);
		}
	}

	string input;
	int n;

	do
	{
		cout << "1. Add student" << endl;								// Menu
		cout << "2. Remove student" << endl;
		cout << "3. Add course to student" << endl;
		cout << "4. Remove course from student" << endl;
		cout << "0. Exit" << endl;
		cout << ">> ";

		getline(cin, input);

		switch (input[0])
		{
		case '1':	/// Add student
		{
			cout << endl << "--- CURRENT STUDENTS ---\n";
			studentRecord.display();								// Print current students(takes long time on large sets)
			cout << "\nStudent name: ";
			getline(cin, input);									// Ask for new student name

			Student newStudent(input);
			studentRecord.insert(newStudent);

			cout << "\nAdded " << input << "\n\n";
		}
		break;

		case '2':	/// Remove student
		{
			if (studentRecord.isEmpty())										// Checks if the record is empty before fetching any data
			{
				cout << "\nNo registered students\n\n";
				break;
			}
			cout << endl << "--- CURRENT STUDENTS ---\n";
			studentRecord.display();											// Displays current students (takes long time on large sets)
			cout << "\nSelect student: ";

			cin >> n;															// Reads input
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Ignores excess '\n' (enter) characters
			studentRecord.remove(n);											// Removes corresponding *Node containing the student via index		

			cout << "\nStudent removed\n\n";
		}
		break;

		case '3':	/// Add course
		{
			if (studentRecord.isEmpty())										// Checks if the record is empty before fetching any data
			{
				cout << "\nNo registered students\n" << endl;
				break;
			}

			cout << "\n--- CURRENT STUDENTS ---\n";
			studentRecord.display();											// Displays current students (takes long time on large sets)
			cout << "\nSelect student: ";
			cin >> n;															// Reads index from printed students
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Ignores excess '\n' (enter) characters

			Student *student = &studentRecord.get(n);

			cout << "\nSelected student: " << student->getName() << endl;
			cout << "\n--- CURRENT COURSES ---\n\n";
			student->getCourseList().display();									// Displays courses attached to student (Takes long time on large sets)

			Course newCourse;

			cout << "Name of course: ";
			getline(cin, input);												// Reads and sets name of course
			newCourse.setName(input);

			cout << "Course credits: ";
			getline(cin, input);												// Reads and sets credits of course
			newCourse.setCredits(input);

			cout << "Student grade: ";
			getline(cin, input);												// Reads and sets grade of course
			newCourse.setGrade(input);

			student->getCourseList().insert(newCourse);

			cout << "\nCourse added\n\n";
		}
		break;

		case '4':	/// Remove course
		{
			if (studentRecord.isEmpty())										// Checks if the record is empty before fetching any data
			{
				cout << "\nNo registered students\n" << endl;
				break;
			}

			cout << "\n--- CURRENT STUDENTS ---\n";
			studentRecord.display();											// Displays current students (takes long time on large sets)
			cout << "\nSelect student: ";
			cin >> n;															// Reads index from printed students
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Ignores excess '\n' (enter) characters

			Student *student = &studentRecord.get(n);

			if (student->getCourseList().isEmpty())								// Checks if the students course list is empty
			{
				cout << "\nNo registered courses\n" << endl;
				break;
			}

			cout << "\nSelected student: " << student->getName() << endl;
			cout << "\n--- CURRENT COURSES ---\n\n";
			student->getCourseList().display();									// Displays current courses the student have(Takes long time on large sets)
			cout << "\nSelect course: ";

			cin >> n;															// Reads index from printed students
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		// Ignores excess '\n' (enter) characters
			student->removeCourse(n);											// Removes corresponding course node from course list with index

			cout << "\nCourse removed\n\n";
		}
		break;

		default:
			break;
		}
	} while (input[0] != '0');													// On large sets deallocation may take some time
}