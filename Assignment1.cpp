#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;



void Assignment1::nucleotideProb(string dna,int sum)
{
	int a = 0;
	int t = 0;
	int g = 0;
	int c = 0;
	int aa,at,ag,ac,ta,tt,tg,tc,ca,ct,cg,cc,ga,gt,gg,gc = 0;
	int nucleotides = 0;
	int bigramCount = 0; //# counters
	int stringLen = 0;
	bool dontCount = false;
	char c1,c2;

	for(int i = 0; i < dna.length()-1; i++)
	{
		int k = i+1;
		c1 = dna[i];
		c2 = dna[k]; //bigram pair

		cout << c1 << ", " << c2;


		//relative probability counting
		if (c1 == 'a' || 'A')
		{
			a++;
			nucleotides++;
			c1 = 'A';
			stringLen++;
		}
		else if (c1 == 't' || 'T')
		{
			t++;
			nucleotides++;
			c1 = 'T';
			stringLen++;
		}
		else if (c1 == 'g' || 'G')
		{
			g++;
			nucleotides++;
			c1 = 'G';
			stringLen++;
		}
		else if (c1 == 'c' || 'C')
		{
			c++;
			nucleotides++;
			c1 = 'C';
			stringLen++;
		}
		else //.
		{
			dontCount = true;
			stringLen = 0;
		}

		if (c2 == '.')
			dontCount = true;

		if (dontCount)
		{
			if (stringLen % 2 == 1)
				dontCount = false;
		}

		cout << "|dontCount: " << dontCount;
		cout << "|" << a << ", " << t << ", " << g << ", " << c << endl;


		//bigram counting
		if (!dontCount) //if odd
		{
			if ((c1 == 'A') && (c2 == 'a' || 'A'))
			{
				aa++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'A') && (c2 == 't' || 'T'))
			{
				at++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'A') && (c2 == 'g' || 'G'))
			{
				ag++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'A') && (c2 == 'c' || 'C'))
			{
				ac++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'T') && (c2 == 'a' || 'A'))
			{
				ta++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'T') && (c2 == 't' || 'T'))
			{
				tt++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'T') && (c2 == 'g' || 'G'))
			{
				tg++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'T') && (c2 == 'c' || 'C'))
			{
				tc++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'G') && (c2 == 'a' || 'A'))
			{
				ga++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'G') && (c2 == 't' || 'T'))
			{
				gt++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'G') && (c2 == 'g' || 'G'))
			{
				gg++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'G') && (c2 == 'c' || 'C'))
			{
				gc++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'C') && (c2 == 'a' || 'A'))
			{
				ca++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'C') && (c2 == 't' || 'T'))
			{
				ct++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'C') && (c2 == 'g' || 'G'))
			{
				cg++;
				bigramCount++;
				dontCount = true;
			}
			else if ((c1 == 'C') && (c2 == 'c' || 'C'))
			{
				cc++;
				bigramCount++;
				dontCount = true;
			}
		}

	}

	cout << a << endl;
	cout << t << endl;
	cout << g << endl;
	cout << c << endl;
	cout << nucleotides << endl;
	cout << bigramCount << endl;

	//relativeprobs
	double aProb = a/nucleotides;
	double tProb = t/nucleotides;
	double gProb = g/nucleotides;
	double cProb = c/nucleotides;

	//bigramprobs
	double aaProb = aa/bigramCount;
	double atProb = at/bigramCount;
	double agProb = ag/bigramCount;
	double acProb = ac/bigramCount;
	double taProb = ta/bigramCount;
	double ttProb = tt/bigramCount;
	double tgProb = tg/bigramCount;
	double tcProb = tc/bigramCount;
	double gaProb = ga/bigramCount;
	double gtProb = gt/bigramCount;
	double ggProb = gg/bigramCount;
	double gcProb = gc/bigramCount;
	double caProb = ca/bigramCount;
	double ctProb = ct/bigramCount;
	double cgProb = cg/bigramCount;
	double ccProb = cc/bigramCount;

	cout << "A: " << aProb << "%" << endl;
	cout << "T: " << tProb << "%" << endl;
	cout << "G: " << gProb << "%" << endl;
	cout << "C: " << cProb << "%" << endl;

	cout << "AA: " << aaProb << "%" << endl;
	cout << "AT: " << atProb << "%" << endl;
	cout << "AG: " << agProb << "%" << endl;
	cout << "AC: " << acProb << "%" << endl;
	cout << "TA: " << taProb << "%" << endl;
	cout << "TT: " << ttProb << "%" << endl;
	cout << "TG: " << tgProb << "%" << endl;
	cout << "TC: " << tcProb << "%" << endl;
	cout << "GA: " << gaProb << "%" << endl;
	cout << "GT: " << gtProb << "%" << endl;
	cout << "GG: " << ggProb << "%" << endl;
	cout << "GC: " << gcProb << "%" << endl;
	cout << "CA: " << caProb << "%" << endl;
	cout << "CT: " << ctProb << "%" << endl;
	cout << "CG: " << cgProb << "%" << endl;
	cout << "CC: " << ccProb << "%" << endl;

}

string Assignment1::capitalize(string dna)
{
	cout << "=======" << endl;
	for(int i = 0; i < dna.length(); i++)
	{
		char curr = dna[i];

		switch (curr)
		{
			case 'a':
				cout << 'A';
				dna[i] = 'A';
				break;
			case 't':
				cout << 'T';
				dna[i] = 'T';
				break;
			case 'g':
				cout << 'G';
				dna[i] = 'G';
				break;
			case 'c':
				cout << 'C';
				dna[i] = 'C';
				break;
			case '.':
				cout << '.';
				dna[i] = '.';
				break;
			case '	':
			case ' ':
				//i--; //decrement because it will be incremented


				//cerr << "Space detected in textfile." << endl;
				//cerr << "Make sure your dna textfile only has nucleotide chars (a,t,g,c)" << endl;
				//exit(1);
				break;
			case '\n':
				if (dna[i-1] != '.')
				{
					cout << '.';
					dna[i] = '.';
				}
				break;
			default:
				//cout << dna[i];
				//cerr << endl << "Error processing file. Make sure you're inputting a dna textfile." << endl;
				break;
		}
	}
	cout << endl;
	return dna;
}

double Assignment1::varLengths(string dna, double mean, int lines)
{
	double numerator = 0;
	int lineLength = 0; //length of each line

	for(int i = 0; i < dna.length(); i++)
	{
		if (dna[i] != '.')
			lineLength++;
		else
		{
			int temp = lineLength-mean; //each lineLength - mean
			numerator += temp*temp; //(lineLength-mean)^2

			lineLength = 0; //resets lineLength
		}
	}
	return numerator / lines;
}

int Assignment1::numLines(string dna) //number of lines
{
	int lines = 0;
	for(int i = 0; i < dna.length(); i++)
	{
		if (dna[i] == '.')
			lines++;
	}
	return lines;
}

int Assignment1::sumLengths(string dna) //sum of the lengths
{
	int sum = 0;
	for(int i = 0; i < dna.length(); i++)
	{
		if (dna[i] != '.') //if char is not delimeter
			sum++;
	}
	return sum;
}

string Assignment1::readFile(string file) //processes file into a string
{
	string processed; //return string

	ifstream inputfile; //input stream
	inputfile.open(file); //stream opens file

	//Check if file can be read
	if (inputfile.fail())
	{
		cerr << "Error opening file. Make sure you're inputting a dna textfile" << endl;
		exit(1);
	}

	string currentline;
	while (getline(inputfile, currentline)) //checks if file can be read
	{
		if(currentline.find_first_not_of(" ") != string::npos)
		{
			processed.append(currentline);
			processed.append("."); //delimeter
		}

		//inputfile >> currentline;
		//cout << currentline << endl;
	}

	inputfile.close();
	return processed;
}

//Constructor
Assignment1::Assignment1(string l)
{
	string processedDna = readFile(l);
	//cout << processedDna << endl;
	//processedDna.assign(capitalize(processedDna));
	
	cout << processedDna << endl;

	/**
	cout << "======" << endl;

	int lines = numLines(processedDna);
	int sum = sumLengths(processedDna);
	double mean = sum / lines;
	double variance = varLengths(processedDna,mean,lines);
	double std = sqrt(variance);

	cout << "lines: " << lines << endl;
	cout << "sum: " << sum << endl;
	cout << "mean: " << mean << endl;
	cout << "variance: " << variance << endl;
	cout << "std: " << std << endl;

	cout << "==NUCLEOTIDES==" << endl;
	nucleotideProb(processedDna,sum);
	**/
}

//Destructor
Assignment1::~Assignment1() {}
