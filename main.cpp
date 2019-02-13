#include "Assignment1.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	//arg1 = ./a.out
	//arg2 = textfile to be read
	if (argc == 2)
	{
		cout << "=Assignment1 Initialized=" << endl;

		string textfile = argv[1];
		Assignment1 assignment1(textfile);
	}
	else
	{
		//if more than one argument
		cout << "Args: " << argc << endl;

		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << endl;
		}
	}

	cout << "Program exited sucesfully." << endl;

	return 0;
}
