#include <iostream>

using namespace std;

class Assignment1
{
	public:
		Assignment1(string list);
		~Assignment1();

	private:
		void generateDNA(double mean, double std, double a, double t, double g, double c);
		void nucleotideProb(string dna, int sum, double &aProb, double &tProb, double &gProb, double &cProb);
		double varLengths(string dna, double mean, int lines);
		int numLines(string dna);
		int sumLengths(string dna);
		string readFile(string file);
		void processList(string file, bool firstFile);
		void processNewList();
};
