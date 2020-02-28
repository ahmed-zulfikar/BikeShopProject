#ifndef _ACC_H
#define _ACC_H


#include <iostream>
#include <string>
using namespace std;

class Accessory

{
public: // member functions
	Accessory(string Namex, int pricex, int amountx);
	string getName();
	string getInfo();
	int getPrice();
	int getAmount();
	void setAmount(int amountx);

public:Accessory();

private:
	string Name;
	int price;
	int amount;
};
#endif