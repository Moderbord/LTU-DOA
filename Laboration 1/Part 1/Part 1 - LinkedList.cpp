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
	LinkedList<Student> studentRecord;									// Main LinkedList object with student records

	//for (int i = 11; i > 0; i--)										// Creates 10 students and inserts them into the record
	//{
	//	Node<Student> *newNode = new Node<Student>();
	//	Student *newStudent = new Student("Student " + std::to_string(i));

	//	newNode->setData(newStudent);
	//	studentRecord.insertSkipMeasure(newNode);

	//	for (int j = 1; j < 11; j++)									// Adds 10 courses to each students
	//	{
	//		Node<Course> *courseNode = new Node<Course>();
	//		Course *newCourse = new Course();

	//		string s = std::to_string(j);
	//		newCourse->setName(s);
	//		newCourse->setCredits(s);
	//		newCourse->setGrade(s);

	//		courseNode->setData(newCourse);
	//		newStudent->getCourseList().insertSkipMeasure(courseNode);
	//	}
	//}

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

			Node<Student> *newNode = new Node<Student>();			// New *Node object of Student type
			Student *newStudent = new Student(input);				// New *Student with input string argument as name

			newNode->setData(newStudent);							// Sets the *T data of the node to the new student
			studentRecord.insert(newNode);							// Inserts the *Node into the LinkedList (student record)

			cout << "Added " << newStudent->getName() << "\n\n";
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

			Node<Student> *studentNode = studentRecord.get(n);					// Creates a temp *Node pointer to selected student
			Student *student = studentNode->getData();							// Creates a temp *Student pointer to student from node data
			Node<Course> *courseNode = new Node<Course>();						// new *Node object
			Course *newCourse = new Course();									// new *Course object

			cout << "\nSelected student: " << student->getName() << endl;
			cout << "\n--- CURRENT COURSES ---\n\n";
			student->getCourseList().display();									// Displays courses attached to student (Takes long time on large sets)
			cout << "Name of course: ";

			getline(cin, input);												// Reads and sets name of course
			newCourse->setName(input);
			cout << "Course credits: ";

			getline(cin, input);												// Reads and sets credits of course
			newCourse->setCredits(input);
			cout << "Student grade: ";

			getline(cin, input);												// Reads and sets grade of course
			newCourse->setGrade(input);

			courseNode->setData(newCourse);										// Inserts the new *Course in the *Node object
			student->getCourseList().insert(courseNode);						// Inserts *Node in the students courses (LinkedList)

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

			Node<Student> *studentNode = studentRecord.get(n);					// Creates a temp *Node pointer to corresponding student
			Student *student = studentNode->getData();							// Creates a temp *Student pointer to student from node data

			if (student->getCourseList().isEmpty())								// Checks if the students course list is empty
			{
				cout << "\nNo registered courses\n" << endl;
				break;
			}

			cout << "\nSelected student: " << student->getName() << endl;
			cout << "\n--- CURRENT COURSES ---\n\n";
			student->getCourseList().display();								// Displays current courses the student have(Takes long time on large sets)
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