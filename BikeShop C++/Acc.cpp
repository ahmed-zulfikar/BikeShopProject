#include "Acc.h"




Accessory::Accessory() = default; // default constructor for array

Accessory::Accessory(string Namex, int pricex, int amountx)
{

	Name = Namex;
	price = pricex;
	amount = amountx;
}
string Accessory::getName() {

	return Name;



}

string Accessory::getInfo() {

	return Name + "    " + std::to_string(price);



}

int Accessory::getPrice() {


	return price;

}

int Accessory::getAmount() {


	return amount;


}

void Accessory::setAmount(int amountx) {

	amount = amountx;



}
