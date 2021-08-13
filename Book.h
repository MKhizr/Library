#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "File.h"
//#include "User.h"


using namespace std;



class Book
{
private:
	string bookName;
	string authorName;
	string ISBN;
	int pageNumber;
	int publishYear;
	string keyWords;
	

public:
	Book() {
		bookName = "Empty";
		authorName = "Empty";
		ISBN = "Empty";
		pageNumber = 0;
		publishYear = 0;
		

	}

	
	Book(string bookname, string authorname, string isbn, int pagenumber, int publishyear, string keywords){
		
		bookName = bookname;
		authorName = authorname;
		ISBN = isbn;
		pageNumber = pagenumber;
		publishYear = publishyear;
		keyWords = keywords;

	}

	


	void setbookname(string bookname) {
		bookName = bookname;
	}

	string getbookname() {
		return bookName;
	}

	void setauthorname(string authorname) {
		authorName = authorname;
	}

	string getauthorname() {
		return authorName;
	}
	void setISBN(string isbn) {
		ISBN = isbn;
	}

string getISBN() {
	return ISBN;
}
void setpagenumber(int pagenumber) {
	pageNumber = pagenumber;
}

int getpagenumber() {
	return pageNumber;
}

void setpublishyear(int publishyear) {
	publishYear = publishyear;
}

int getpublishyear() {
	return publishYear;
}

string getkeyword() {
	return keyWords;
}

void setkeyword(string word) {
	keyWords = word;

}

void Insert(vector<string>& authornamevec, vector<string>& booknamevec, vector<string>& isbnvec, vector<int>& pagenumbervec, vector<int>& publishyearvec, vector<string>& keywordsvec, Book* obj) {

	booknamevec.push_back(obj->getbookname());
	authornamevec.push_back(obj->getauthorname());
	isbnvec.push_back(obj->getISBN());
	pagenumbervec.push_back(obj->getpagenumber());
	publishyearvec.push_back(obj->getpublishyear());
	keywordsvec.push_back(obj->getkeyword());

}


void Delete(vector<string>& authornamevec, vector<string>& booknamevec, vector<string>& isbnvec, vector<int>& pagenumbervec, vector<int>& publishyearvec, vector<string>& keywordsvec) {
	
	string tmp;
	cout << "Enter name of book: " << endl;
	cin >> tmp;
	int valueofindex;


	valueofindex = getIndex(booknamevec, tmp);


	authornamevec.erase(authornamevec.begin() + valueofindex);
	booknamevec.erase(booknamevec.begin() + valueofindex);
	isbnvec.erase(isbnvec.begin() + valueofindex);
	pagenumbervec.erase(pagenumbervec.begin() + valueofindex);
	publishyearvec.erase(publishyearvec.begin() + valueofindex);
	keywordsvec.erase(keywordsvec.begin() + valueofindex);


}

int getIndex(vector<string>& booknamevec, string temp){

	auto it = find(booknamevec.begin(), booknamevec.end(), temp);

	// If element was found
	if (it != booknamevec.end())
	{
		int index = it - booknamevec.begin();
		//cout << "Value of inddex is: " << index << endl;
		return index;
	}
	else {
		// If the element is not
		// present in the vector
		cout << "-1" << endl;
	}



}


void Sort(vector<string>& authornamevec, vector<string>& booknamevec, vector<string>& isbnvec, vector<int>& pagenumbervec, vector<int>& publishyearvec, vector<string>& keywordsvec) {

	for (int j = 1; j < authornamevec.size(); j++)
	{
		int key = publishyearvec[j];
		int page = pagenumbervec[j];
		string author = authornamevec[j];
		string nameofbook = booknamevec[j];
		string isbn = isbnvec[j];
		string keyword = keywordsvec[j];

		int i = j - 1;

		while (i >= 0 && publishyearvec[i] > key)
		{
			authornamevec[i + 1] = authornamevec[i];
			booknamevec[i + 1] = booknamevec[i];
			isbnvec[i + 1] = isbnvec[i];
			pagenumbervec[i + 1] = pagenumbervec[i];
			publishyearvec[i + 1] = publishyearvec[i];
			keywordsvec[i + 1] = keywordsvec[i];
			i--;
		}
		publishyearvec[i + 1] = key;
		pagenumbervec[i + 1] = page;
		authornamevec[i + 1] = author;
		booknamevec[i + 1] = nameofbook;
		isbnvec[i + 1] = isbn;
		keywordsvec[i + 1] = keyword;

	}




}

void Display(vector<string>& authornamevec, vector<string>& booknamevec, vector<string>& isbnvec, vector<int>& pagenumbervec, vector<int>& publishyearvec, vector<string>& keywordsvec) {

	cout << "\n---------------------------------------------------\n" << endl;
	for (int i = 0; i < authornamevec.size(); i++) {
		cout << "Name of author: " << authornamevec[i]<< endl;
		cout << "Name of book: " << booknamevec[i] << endl;
		cout << "ISBN: " << isbnvec[i] << endl;
		cout << "Page number: " << pagenumbervec[i] << endl;
		cout << "Year of publish: " << publishyearvec[i] << endl;
		cout << "Keyword: " << keywordsvec[i] << endl;
		cout << "\n---------------------------------------------------\n" << endl;

	}


}



};
