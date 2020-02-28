#ifndef _USER_H
#define _USER_H


#include <iostream>
#include <string>
using namespace std;

class User
{

public: // member functions
	User(string fullx,string lastx, string phonex, string dobx);

public:User(); //empty user with no fields
	  string getfull();
	  string getlast();
	  string getphone();
	  string getdob();
	  void setdob(string dob);
	  void setfull(string full);
	  void setphone(string phone);
	  void setlast(string last);

private:
	string full;
	string phone;
	string dob;
	string last;


};
#endif
