#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

namespace {
	using std::cout;
	using std::endl;
	using std::string;
	using std::stack;
}

void filterStringToStack(string &str, stack<char> &stack)
{
	for (char &c : str)
	{
		if (isalpha(c))
		{
			stack.push(tolower(c));
		}
	}

	int n = stack.size();


}

// dag ott o gad

// dagottogad

int main()
{
	// 1. Ta emot str�ng
	// 3. Konvertera till lowercase
	// 2. Filtrera bort icke bokst�ver
	// 4. J�mf�r?
	// 5. Returnera bool

	string word = "eett";
	stack<char> stack;

	filterStringToStack(word, stack);

	int f = stack.size() / 2;
	int O = 0;
}