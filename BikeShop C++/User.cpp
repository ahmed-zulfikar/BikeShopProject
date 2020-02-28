#include "User.h"
#include <iostream>
#include <string>

User::User() = default;

User::User(string phonex, string lastx,string fullx, string dobx)
{

	
	setphone(phonex);
	setdob(dobx);
	setfull(fullx);
	setlast(lastx);


}



string User::getfull() {


	return full;

}

void User::setfull(string full)
{
	this->full = full;
	
}

string User::getlast() {

	return last;

}

void User::setlast(string last) {

	this->last = last;

}

string User::getphone() {


	return phone;

}

void User::setphone(string phone)
{
	this->phone = phone; //this local variable is set to that phone

}
string User::getdob() {
	
	return dob;

}


void User::setdob(string dob) {

	this->dob = dob;


}