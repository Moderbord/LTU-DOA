#include "pch.h"
#include "Student.h"
#include <iostream>
#include <string>

namespace {
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
}

//void values(int &i)
//{
//	i = i + 5;
//}


int main()
{
	CustomArray<Student> record;


	for (int j = 1; j < 11; j++)
	{
		Student student(std::to_string(j));
		record.insert(student);
		
		for (int i = 1; i < 11; i++)
		{
			Course course;
			string s = std::to_string(i);
			course.setName(s);
			course.setCredits(s);
			course.setGrade(s);

			record.get(j).getCourseList().insert(course);
		}
	}



	record.display();
	record.get(3).displayCourses();
	int k = 0;
}