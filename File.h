#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Book.h"
#include "User.h"


using namespace std;



class File
{


public:
	


	void filereader(vector<string>&authornamevec, vector<string>&booknamevec, vector<string>&isbnvec, vector<int>&pagenumbervec, vector<int>&publishyearvec, vector<string>&keywordsvec) {

		string A,B,C,F; 
		int D, E;
		int i = 0;

		//string file;
		//cout << "Enter the filename: ";
		//cin >> file;
		//ifstream coeff(file); //opening the file.

		ifstream coeff("bookdata.txt");

		if (coeff.is_open()) //if the file is open
		{
			
			string line;
			string stringforyear;
			string stringforpagenumber;
			


			while (getline(coeff, line)) //while the end of file is NOT reached
			{
				stringstream ss(line);
				
				getline(ss, A, ',');
				booknamevec.push_back(A);
				getline(ss, B, ',');
				authornamevec.push_back(B);
				getline(ss, C, ',');
				isbnvec.push_back(C);
				getline(ss, stringforpagenumber, ','); 
				D = stoi(stringforpagenumber);
				pagenumbervec.push_back(D);
				getline(ss, stringforyear, ',');
				E = stoi(stringforyear);
				publishyearvec.push_back(E);
				getline(ss, F, '\n');
				keywordsvec.push_back(F);

				i += 1; //increment number of lines
			}
			coeff.close(); //closing the file
			
		}
		else cout << "Unable to open file"; //if the file is not open output

		



	}


	void filereaderUser(vector<string> &usernamevec, vector<string> &useridvec, vector<string>& userpasswordvec) {

		string A, B, C;
		int i = 0;
		
		
		/*string file;
		cout << "Enter the filename: ";
		cin >> file;*/
		//ifstream coeff(file); //opening the file.

		ifstream coeff("userdata.txt");

		if (coeff.is_open()) //if the file is open
		{

			string line;

			while (getline(coeff, line)) //while the end of file is NOT reached
			{
				stringstream ss(line);

				getline(ss, A, ',');
				usernamevec.push_back(A);
				getline(ss, B, ',');
				useridvec.push_back(B);
				getline(ss, C, '\n');
				userpasswordvec.push_back(C);
				

				i += 1; //increment number of lines
			}
			coeff.close(); //closing the file

		}
		else cout << "Unable to open file"; //if the file is not open output


	}


	void bookcontentdelete(vector<string>& authornamevec, vector<string>& booknamevec, vector<string>& isbnvec, vector<int>& pagenumbervec, vector<int>& publishyearvec, vector<string>& keywordsvec) {
		
		//clearing file contents part
		std::ofstream ofs;
		ofs.open("bookdata.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		//writing all the contents again part
		ofstream file;
		file.open("bookdata.txt");
		for (int i = 0; i < authornamevec.size(); ++i) {
			file << authornamevec[i] << ',';
			file << booknamevec[i]<< ',';
			file << isbnvec[i] << ',';
			file << pagenumbervec[i] << ',';
			file << publishyearvec[i] << ',';
			file << keywordsvec[i] << endl;

			
		}
		file.close();
	}



	void bookcontentdeleteUser(vector<string>& usernamevec, vector<string> &useridvec, vector<string> &userpasswordvec) {
		
		//clearing file contents part
		std::ofstream ofs;
		ofs.open("userdata.txt", std::ofstream::out | std::ofstream::trunc);
		ofs.close();

		//writing all the contents again part
		ofstream file;
		file.open("userdata.txt");
		for (int i = 0; i < usernamevec.size(); ++i) {
			file << usernamevec[i] << ',';
			file << useridvec[i]<< ',';
			file << userpasswordvec[i] << endl;
			

			
		}
		file.close();
	}
};

