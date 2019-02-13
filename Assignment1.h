#include <iostream>

using namespace std;

class Assignment1
{
	public:
		Assignment1(string list);
		~Assignment1();

	private:
		string capitalize(string dna);
		void nucleotideProb(string dna,int sum);
		double varLengths(string dna, double mean, int lines);
		int numLines(string dna);
		int sumLengths(string dna);
		string readFile(string file);

};
