#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "File.h"


using namespace std;

class User
{
private: 
	string userName;
	string userId;
	string userPassword;

public:
	User() {
		userName = "empty";
		userId = "empty";
		userPassword = "empty";

	}

	User(string name, string id, string password) {

		userName = name;
		userId = id;
		userPassword = password;
	}

	string getusername() {
		return userName;

	}

	void setusername(string username) {
		userName = username;
	}

	string getuserpassword() {
		return userPassword;

	}

	void setuserpassword(string userpassword) {
		userPassword = userpassword;
	}

	string getuserid() {
		return userId;

	}

	void setuserid(string userid) {
		userId = userid;
	}


	void AddUser(vector<string> &usernamevec,vector<string> &useridvec,vector<string> &userpasswordvec, User* obj) {

		usernamevec.push_back(obj->getusername());
		useridvec.push_back(obj->getuserid());
		userpasswordvec.push_back(obj->getuserpassword());

	}


	int CompareUsername(vector<string> &usernamevec, string tmp) {

		for (int i = 0; i < usernamevec.size(); i++) {
			
			if (usernamevec[i] == tmp) {
				return 1;
			}

		}

		return 0;
	}

	int ComparePassword(vector<string> &userpasswordvec, string tmp) {

		for (int i = 0; i < userpasswordvec.size(); i++) {

			if (userpasswordvec[i] == tmp) {
				return 1;
			}

		}

		return 0;
	}


};

