#ifndef _BIKE_H
#define _BIKE_H


#include <iostream>
#include <string>
using namespace std;

class Bike

{
public: // member functions
	Bike(string Namex, string Modelx, string Makex, string Typex, bool availablex, int feex, string pricex); //
	string getName();
	string getModel();
	string getMake();
	string getType();
	string getInfo();
	string getPrice();
	string getReceipt();
	int getFee();
	bool getavailable();
	void setavailable(bool x);

public:Bike();

private:
	string Name;
	string Model;
	string Make;
	string Type;
	string Prices;
	bool available = true; //
	int fee;
};
#endif