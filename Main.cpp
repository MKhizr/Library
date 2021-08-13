//Khizr
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Book.h"
//#include "File.h"
#include "User.h"


using namespace std;

int main()
{

	char option;
	int useroption = 1;

	vector<string>authornamevec;
	vector<string>booknamevec;
	vector<string>isbnvec;
	vector<int>pagenumbervec;
	vector<int>publishyearvec;
	vector<string>keywordsvec;

	vector<string> usernamevec;
	vector<string> useridvec;
	vector<string> userpasswordvec;

	File obj1;
	User userobj;
	

	obj1.filereaderUser(usernamevec, useridvec, userpasswordvec);


	do {

		User newobj;
		string username, pass,newuser,newpassword,newid;

		cout << "Enter username: " << endl;
		cin >> username;
		cout << "Enter password: " << endl;
		cin >> pass;

		int uservalue= userobj.CompareUsername(usernamevec, username);
		int passwordvalue= userobj.ComparePassword(userpasswordvec, pass);

		if ((uservalue == 1) && (passwordvalue == 1)) {
			useroption = 0;
		}

		else {
			cout << "\nNo user found. Create user" << endl;
			cout << "\nEnter username: " <<endl;
			cin >> newuser;
			newobj.setusername(newuser);
			cout << "Enter password: " << endl;
			cin >> newpassword;
			newobj.setuserpassword(newpassword);
			cout << "Enter user ID: " << endl;
			cin >> newid;
			newobj.setuserid(newid);
			userobj.AddUser(usernamevec, useridvec, userpasswordvec, &newobj);
		}

	} while (useroption != 0);

	obj1.bookcontentdeleteUser(usernamevec, useridvec, userpasswordvec);


	
	Book objbook;

	obj1.filereader(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec);
	
	do {
		cout << "\n-----------------------------------\n";
		cout << "Press A to insert a book." << endl;
		cout << "Press D to delete a book." << endl;
		cout << "Press S to sort all books(date)." << endl;
		cout << "Press X to display all books." << endl;
		cout << "Press Q to exit." << endl;
		cin >> option;

		if (option == 'A') {

			string newauthor, newbook, newisbn, newkeyword;
			int newyear, newpage;

			Book obj;
			cout << "Enter name of author: " << endl;
			cin >> newauthor;
			obj.setauthorname(newauthor);
			cout << "Enter name of book: " << endl;
			cin >> newbook;
			obj.setbookname(newbook);
			cout << "Enter ISBN: " << endl;
			cin >> newisbn;
			obj.setISBN(newisbn);
			cout << "Enter page number:" << endl;
			cin >> newpage;
			obj.setpagenumber(newpage);
			cout << "Enter year: " << endl;
			cin >> newyear;
			obj.setpublishyear(newyear);
			cout << "Enter keyword: " << endl;
			cin >> newkeyword;
			obj.setkeyword(newkeyword);


			objbook.Insert(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec, &obj);
		}
		
		if (option == 'D') {

			objbook.Delete(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec);
		}

		if (option == 'S') {

			objbook.Sort(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec);
		}


		if (option == 'X') {
			objbook.Display(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec);
		}


	} while (option != 'Q');


	
	obj1.bookcontentdelete(authornamevec, booknamevec, isbnvec, pagenumbervec, publishyearvec, keywordsvec);


	

 return 0;
}