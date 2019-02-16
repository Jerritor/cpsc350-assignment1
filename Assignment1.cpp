#include "Assignment1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void Assignment1::nucleotideProb(string dna,int sum, double &aProb, double &tProb, double &gProb, double &cProb) //calcualtes all nucelotide probs
{
	int a = 0;
	int t = 0;
	int g = 0;
	int c = 0;
	int aa = 0,at = 0,ag = 0,ac = 0,ta = 0,tt = 0,tg = 0,tc = 0,ca = 0,ct = 0,cg = 0,cc = 0,ga = 0,gt = 0,gg = 0,gc = 0;
	int nucleotides = 0;
	int bigramCount = 0; //# counters
	int stringLen = 1; //used to calculate bigram pair

	cout << "Calculating statistics..." << endl;

	for(int i = 0; i < dna.length()-1; i++)
	{
		int k = i+1;
		char c1 = dna[i];
		char c2 = dna[k]; //bigram pair

		//cout << c1;

		//relative probability counting
		switch (c1)
		{
			case 'A':
				a++; //inc a count
				nucleotides++; //inc nucleotide count
				stringLen++; //used to calculate bigram pairs
				break;
			case 'T':
				t++; //inc t count
				nucleotides++;
				stringLen++;
				break;
			case 'G':
				g++; //inc g count
				nucleotides++;
				stringLen++;
				break;
			case 'C':
				c++; //inc c count
				nucleotides++;
				stringLen++;
				break;
			case '.':
				stringLen = 1; //newLine[1], newLine[2]
		}


		//cout << "|" << a << ", " << t << ", " << g << ", " << c;
		//cout << "|stringLen: " << stringLen << endl;



		//bigram counting
		if ((stringLen % 2 == 0) && (stringLen != 1)) //if bigram pair
		{
			//cant place bigramcount++ here bc c2 might be .
			if (c1 == 'A')
			{
				if (c2 == 'A')
				{
					aa++;
					bigramCount++;
				}
				else if (c2 == 'T')
				{
					at++;
					bigramCount++;
				}
				else if (c2 == 'G')
				{
					ag++;
					bigramCount++;
				}
				else if (c2 == 'C')
				{
					ac++;
					bigramCount++;
				}
			}
			else if (c1 == 'T')
			{
				if (c2 == 'A')
				{
					ta++;
					bigramCount++;
				}
				else if (c2 == 'T')
				{
					tt++;
					bigramCount++;
				}
				else if (c2 == 'G')
				{
					tg++;
					bigramCount++;
				}
				else if (c2 == 'C')
				{
					tc++;
					bigramCount++;
				}
			}
			else if (c1 == 'G')
			{
				if (c2 == 'A')
				{
					ga++;
					bigramCount++;
				}
				else if (c2 == 'T')
				{
					gt++;
					bigramCount++;
				}
				else if (c2 == 'G')
				{
					gg++;
					bigramCount++;
				}
				else if (c2 == 'C')
				{
					gc++;
					bigramCount++;
				}
			}
			else if (c1 == 'C')
			{
				if (c2 == 'A')
				{
					ca++;
					bigramCount++;
				}
				else if (c2 == 'T')
				{
					ct++;
					bigramCount++;
				}
				else if (c2 == 'G')
				{
					cg++;
					bigramCount++;
				}
				else if (c2 == 'C')
				{
					cc++;
					bigramCount++;
				}
			}
			//cout << c1 << c2 << endl;

			/**
			if ((c1 == 'A') && (c2 == 'a' || 'A'))
			{
				aa++;
				bigramCount++;
			}
			else if ((c1 == 'A') && (c2 == 't' || 'T'))
			{
				at++;
				bigramCount++;
			}
			else if ((c1 == 'A') && (c2 == 'g' || 'G'))
			{
				ag++;
				bigramCount++;
			}
			else if ((c1 == 'A') && (c2 == 'c' || 'C'))
			{
				ac++;
				bigramCount++;
			}
			else if ((c1 == 'T') && (c2 == 'a' || 'A'))
			{
				ta++;
				bigramCount++;
			}
			else if ((c1 == 'T') && (c2 == 't' || 'T'))
			{
				tt++;
				bigramCount++;
			}
			else if ((c1 == 'T') && (c2 == 'g' || 'G'))
			{
				tg++;
				bigramCount++;
			}
			else if ((c1 == 'T') && (c2 == 'c' || 'C'))
			{
				tc++;
				bigramCount++;
			}
			else if ((c1 == 'G') && (c2 == 'a' || 'A'))
			{
				ga++;
				bigramCount++;
			}
			else if ((c1 == 'G') && (c2 == 't' || 'T'))
			{
				gt++;
				bigramCount++;
			}
			else if ((c1 == 'G') && (c2 == 'g' || 'G'))
			{
				gg++;
				bigramCount++;
			}
			else if ((c1 == 'G') && (c2 == 'c' || 'C'))
			{
				gc++;
				bigramCount++;
			}
			else if ((c1 == 'C') && (c2 == 'a' || 'A'))
			{
				ca++;
				bigramCount++;
			}
			else if ((c1 == 'C') && (c2 == 't' || 'T'))
			{
				ct++;
				bigramCount++;
			}
			else if ((c1 == 'C') && (c2 == 'g' || 'G'))
			{
				cg++;
				bigramCount++;
			}
			else if ((c1 == 'C') && (c2 == 'c' || 'C'))
			{
				cc++;
				bigramCount++;
			}
			**/
		}
	}

	//relativeprobs
	aProb = a/(double)nucleotides;
	tProb = t/(double)nucleotides;
	gProb = g/(double)nucleotides;
	cProb = c/(double)nucleotides;

	//bigramprobs
	double aaProb = aa/(double)bigramCount;
	double atProb = at/(double)bigramCount;
	double agProb = ag/(double)bigramCount;
	double acProb = ac/(double)bigramCount;
	double taProb = ta/(double)bigramCount;
	double ttProb = tt/(double)bigramCount;
	double tgProb = tg/(double)bigramCount;
	double tcProb = tc/(double)bigramCount;
	double gaProb = ga/(double)bigramCount;
	double gtProb = gt/(double)bigramCount;
	double ggProb = gg/(double)bigramCount;
	double gcProb = gc/(double)bigramCount;
	double caProb = ca/(double)bigramCount;
	double ctProb = ct/(double)bigramCount;
	double cgProb = cg/(double)bigramCount;
	double ccProb = cc/(double)bigramCount;

	//writing to jerrick.out
	ofstream outputfile ("jerrick.out", ios::app); //output stream
	if (outputfile.is_open())
	{
		outputfile << "-nucleotide relative probabilities-" << endl;
		outputfile << "A: " << aProb*100 << "%" << endl;
		outputfile << "T: " << tProb*100 << "%" << endl;
		outputfile << "G: " << gProb*100 << "%" << endl;
		outputfile << "C: " << cProb*100 << "%" << endl;

		outputfile << "-nucleotide bigram probabilities-" << endl;
		outputfile << "AA: " << aaProb*100 << "%" << endl;
		outputfile << "AT: " << atProb*100 << "%" << endl;
		outputfile << "AG: " << agProb*100 << "%" << endl;
		outputfile << "AC: " << acProb*100 << "%" << endl;
		outputfile << "TA: " << taProb*100 << "%" << endl;
		outputfile << "TT: " << ttProb*100 << "%" << endl;
		outputfile << "TG: " << tgProb*100 << "%" << endl;
		outputfile << "TC: " << tcProb*100 << "%" << endl;
		outputfile << "GA: " << gaProb*100 << "%" << endl;
		outputfile << "GT: " << gtProb*100 << "%" << endl;
		outputfile << "GG: " << ggProb*100 << "%" << endl;
		outputfile << "GC: " << gcProb*100 << "%" << endl;
		outputfile << "CA: " << caProb*100 << "%" << endl;
		outputfile << "CT: " << ctProb*100 << "%" << endl;
		outputfile << "CG: " << cgProb*100 << "%" << endl;
		outputfile << "CC: " << ccProb*100 << "%" << endl;


		outputfile.close();

	}

	/**
	cout << "==counts==" << endl;
	cout << "a: " << a << endl;
	cout << "t: " << t << endl;
	cout << "g: " << g << endl;
	cout << "c: " << c << endl;
	cout << "nucleotides: " << nucleotides << endl;
	cout << "aa: " << aa << endl;
	cout << "at: " << at << endl;
	cout << "ag: " << ag << endl;
	cout << "ac: " << ac << endl;
	cout << "ta: " << ta << endl;
	cout << "tt: " << tt << endl;
	cout << "tg: " << tg << endl;
	cout << "tc: " << tc << endl;
	cout << "ga: " << ga << endl;
	cout << "gt: " << gt << endl;
	cout << "gg: " << gg << endl;
	cout << "gc: " << gc << endl;
	cout << "ca: " << ca << endl;
	cout << "ct: " << ct << endl;
	cout << "cg: " << cg << endl;
	cout << "cc: " << cc << endl;
	cout << "bigramCount: " << bigramCount << endl;
	cout << "========" << endl;

	cout << "A: " << aProb*100 << "%" << endl;
	cout << "T: " << tProb*100 << "%" << endl;
	cout << "G: " << gProb*100 << "%" << endl;
	cout << "C: " << cProb*100 << "%" << endl;

	cout << "AA: " << aaProb*100 << "%" << endl;
	cout << "AT: " << atProb*100 << "%" << endl;
	cout << "AG: " << agProb*100 << "%" << endl;
	cout << "AC: " << acProb*100 << "%" << endl;
	cout << "TA: " << taProb*100 << "%" << endl;
	cout << "TT: " << ttProb*100 << "%" << endl;
	cout << "TG: " << tgProb*100 << "%" << endl;
	cout << "TC: " << tcProb*100 << "%" << endl;
	cout << "GA: " << gaProb*100 << "%" << endl;
	cout << "GT: " << gtProb*100 << "%" << endl;
	cout << "GG: " << ggProb*100 << "%" << endl;
	cout << "GC: " << gcProb*100 << "%" << endl;
	cout << "CA: " << caProb*100 << "%" << endl;
	cout << "CT: " << ctProb*100 << "%" << endl;
	cout << "CG: " << cgProb*100 << "%" << endl;
	cout << "CC: " << ccProb*100 << "%" << endl;
	**/

}

double Assignment1::varLengths(string dna, double mean, int lines) //variance
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
		if(currentline.find_first_not_of(" ") != string::npos) //if there's a space in a line doesn't equal 'no matches'
		{
			for (int i = 0; i < currentline.length(); i++)
			{
				char curr = currentline[i];

				switch(curr)
				{
					case 'a':
					case 'A':
						processed.append("A");
						//cout << 'A';
						break;
					case 't':
					case 'T':
						processed.append("T");
						//cout << 'T';
						break;
					case 'g':
					case 'G':
						processed.append("G");
						//cout << 'G';
						break;
					case 'c':
					case 'C':
						processed.append("C");
						//cout << 'C';
						break;
				}
			}

			if (processed[processed.length()-1] != '.') //if there isn't a delimeter
			{
				//cout << '.';
				processed.append("."); //delimeter
			}
		}
	}
	//cout << endl;

	inputfile.close();
	return processed;
}

void Assignment1::generateDNA(double mean, double std, double a, double t, double g, double c) //generates the 1000 normally distributed strings
{
	//1000
	ofstream outputfile ("jerrick.out", ios::app);

	cout << "Generating strings..." << endl;

	outputfile << "-1000 strings normally distributed with μ=" << mean << ", σ=" << std << " -" << endl;
	for (int i = 0; i < 1000; i++)
	{
		//2 random nums [0,1) for gaussian dist
		double num1 = rand() / (double)RAND_MAX;
		double num2 = rand() / (double)RAND_MAX;

		const double twopi = 3.1415*2;

		//gaussian
		double numLogged;
		if (log(num1) == 0) //in case num1 is 0
			numLogged = 0;
		else
			numLogged = log(num1);

		double gaussian = sqrt(-2.0 * numLogged) * cos(twopi * num2); //gaussian
		double nmlRndomD = (std*gaussian) + mean;
		double length = abs(round(nmlRndomD));

		if (outputfile.is_open())
		{
			for(int j = 0; j < length; j++)
			{
				double nucleoProb = rand() / (double)RAND_MAX;
				if (nucleoProb < a) //(0, a)
				{
					outputfile << 'A';
					//cout << 'A';
				}
				else if (nucleoProb < a+t)
				{
					outputfile << 'T';
					//cout << 'T';
				}
				else if (nucleoProb < a+t+g)
				{
					outputfile << 'G';
					//cout << 'G';
				}
				else
				{
					outputfile << 'C';
					//cout << 'C';
				}
			}
			outputfile << endl;
			//cout << endl;
		}
		//cout << nmlRndomD << endl;
	}
	outputfile.close();
}

void Assignment1::processList(string file,bool firstFile) //process a list
{
	string processedDna = readFile(file);
	cout << "============" << file << "============" << endl;
	cout << "processed dna: " << processedDna << endl;

	int lines = numLines(processedDna);
	int sum = sumLengths(processedDna);
	double mean = sum / lines;
	double variance = varLengths(processedDna,mean,lines);
	double std = sqrt(variance);

	ofstream outputfile;
	if (firstFile)
	{
		outputfile = ofstream("jerrick.out");
	}
	else
	{
		outputfile = ofstream("jerrick.out",ios::app);
	}

	if (outputfile.is_open())
	{
		if (firstFile)
			outputfile << "Jerrick Torres 2301036 CPSC350-01" << endl;
		outputfile << "============" << file << "============" << endl;
		outputfile << "sum: " << sum << endl;
		outputfile << "mean: " << mean << endl;
		outputfile << "variance: " << variance << endl;
		outputfile << "std: " << std << endl;
		outputfile.close();
	}

	/**
	cout << "lines: " << lines << endl;
	cout << "sum: " << sum << endl;
	cout << "mean: " << mean << endl;
	cout << "variance: " << variance << endl;
	cout << "std: " << std << endl;
	**/

	//cout << "==NUCLEOTIDES==" << endl;
	double aProb, tProb, gProb, cProb;
	nucleotideProb(processedDna,sum,aProb,tProb,gProb,cProb);

	//cout << "-Generating 1000 strings with μ=" << mean << ", σ=" << std << " -" << endl;
	generateDNA(mean, std, aProb, tProb, gProb, cProb);

	cout << "Outputting onto jerrick.out..." << endl;
	cout << "========" << endl;
	processNewList();
}

void Assignment1::processNewList() //command line ui
{
	cout << "Do you want to process another list? (y/n): ";
	string input;
	cin >> input;

	if (input == "y")
	{
		cout << "Please enter the filename:" << endl;
		cin >> input;

		ifstream inputfile;
		inputfile.open(input); //stream opens file

		//Check if file can be read
		if (inputfile.fail())
		{
			cout << "Error opening file. Make sure you're inputting a dna textfile" << endl;
			inputfile.close();
			processNewList();
		}
		else
		{
			inputfile.close();
			processList(input, false);
		}
	}
	else if (input == "n") {}
	else
	{
		cout << "Please enter 'y' or 'n' to select your option." << endl;
		processNewList();
	}
}

//Constructor
Assignment1::Assignment1(string l)
{
	processList(l,true);
}

//Destructor
Assignment1::~Assignment1() {}
