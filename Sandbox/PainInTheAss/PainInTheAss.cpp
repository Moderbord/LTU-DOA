#include "pch.h"
#include <iostream>
#include <string>

namespace {
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
}

void values(int &i)
{
	i = i + 5;
}


int main()
{
	int base = 10;
	values(base);
}