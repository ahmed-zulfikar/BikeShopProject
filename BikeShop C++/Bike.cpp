#include "Bike.h"




Bike::Bike() = default; // default constructor for array

Bike::Bike(string Namex, string Modelx, string Makex, string Typex, bool availablex, int feex, string pricex)
{
	Name = Namex;
	Model = Modelx;
	Make = Makex;
	Type = Typex;
	fee = feex;
	available = availablex;
	Prices = pricex;
}



bool Bike::getavailable()
{
	return available;
}


void Bike::setavailable(bool x)
{
	available = x;
}


string Bike::getName()
{
	return Name;
}


string Bike::getModel()
{
	return Model;
}


string Bike::getMake()
{
	return Make;
}


string Bike::getType()
{
	return Type;
}


int Bike::getFee()
{
	return fee;
}

string Bike::getPrice()
{
	return Prices;
}

string Bike::getInfo()
{
	return Name + "    " + Model + "        " + Make + "  " + Type + "       " + Prices;
}

string Bike::getReceipt()
{
	return Name + "      " + "Model number: " + Model + "    Price: $" + Prices;
}