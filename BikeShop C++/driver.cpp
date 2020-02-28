//-----------------------------------------------------------------------------------
//Inlucdes
#include "Bike.h"
#include <iostream>
#include <string>
#include "User.h"
#include "Acc.h"
#include<ctime>
#include <fstream>
using namespace std;
//-----------------------------------------------------------------------------------
//Global variables - will not change
const int LATEFEE = 10;
const int DEPOSIT = 10;
//-----------------------------------------------------------------------------------
// Main body of code
int main() {
	User u = User();
	string choice;
	int indexaccessory = 0;
	//-----------------------------------------------------------------------------------
	//Acessory Arrays
	Accessory Accessoryarray[5];
	Accessory Accessorychoices[100];
	Accessory a1("Helmet    ", 20, 0);
	Accessory a2("Gloves    ", 15, 0);
	Accessory a3("Kneepads  ", 20, 0);
	Accessory a4("Sunglasses", 5, 0);
	Accessory a5("Decals    ", 5, 0);
	Accessoryarray[0] = a1;
	Accessoryarray[1] = a2;
	Accessoryarray[2] = a3;
	Accessoryarray[3] = a4;
	Accessoryarray[4] = a5;
	//-----------------------------------------------------------------------------------
	//Bike Arrays
	Bike Bikearray[10];
	Bike b1("Mountain Bike", "121", "Yeti      ", "Male  ", true, 30, "30");
	Bike b2("Mountain Bike", "122", "Marin     ", "Female", true, 30, "30");
	Bike b3("BMX Bike    ", "123", "Yeti      ", "Male  ", true, 20, "20");
	Bike b4("BMX Bike    ", "124", "GTBikes   ", "Female", true, 20, "20");
	Bike b5("Racer Bike  ", "125", "Trek      ", "Male  ", true, 25, "25");
	Bike b6("Racer Bike  ", "126", "Cannondale", "Female", true, 25, "25");
	Bike b7("Tandem Bike ", "127", "Marin     ", "Male  ", true, 50, "50");
	Bike b8("Tandem Bike ", "128", "Trek      ", "Female", true, 50, "50");
	Bike b9("Crusier Bike", "129", "GTBikes   ", "Male  ", true, 27, "27");
	Bike b10("Crusier Bike", "130", "Cannondale", "Female", true, 27, "27");
	Bikearray[0] = b1;
	Bikearray[1] = b2;
	Bikearray[2] = b3;
	Bikearray[3] = b4;
	Bikearray[4] = b5;
	Bikearray[5] = b6;
	Bikearray[6] = b7;
	Bikearray[7] = b8;
	Bikearray[8] = b9;
	Bikearray[9] = b10;
	//-----------------------------------------------------------------------------------
	//Variables - Before loop
	int bikeselect = -1;            // Array starts at 0 so this will at start at -1,
	int duration = 0;               // Duration of rental
	int fee = 0;                    // Fee
	int option = 0;                 // Option
	bool customer = true;           // Keeps loop going later on in the code
	ofstream receipt;               // Creates file
	receipt.open("receipt.txt");    // Creates file and file name
//-----------------------------------------------------------------------------------
//User Rules
	cout << "TJK Bike Shop Rules:" << endl;
	cout << "1. Only one bike can be rented per customer." << endl;
	cout << "2. The maximum amount of time a bike can be rented is 7 days. If the bike is returned over 7 days, a late fee will be charged!" << endl;
	cout << endl;
	//-----------------------------------------------------------------------------------
	//User Information
	do {
		cout << "Is there a customer? (enter y for yes and n for no): ";
		cin >> choice;

		if (choice != "y")
			customer = false;                                   //will set customer to false

		if (choice.compare("n") == 0)                           //will run if input is "n"
		{
			break;                                              //will break out of the loop
		}
		else if (choice.compare("y") == 0)                      //will run if input is "y"
		{
			indexaccessory = 0;
			bikeselect = -1;
			string full, phone, dob, last;
			cout << "========================" << endl;
			cout << "| Customer Information |" << endl;
			cout << "========================" << endl;
			cout << "First name: ";
			cin >> full;
			cout << "Last name: ";
			cin >> last;
			cout << "Phone Number: ";
			cin >> phone;
			cout << "Date of Birth (Enter in this format MM/DD/YYYY): ";
			cin >> dob;
			u = User(phone, last, full, dob);
		}
		else
		{
			cout << "Input must be y/n" << endl;
		}

		//-----------------------------------------------------------------------------------
		//User Interface
		do {
			cout << endl;
			cout << "===========================================" << endl;
			cout << "| Welcome to the TJK Bike Shop Interface! |" << endl;
			cout << "===========================================" << endl;
			cout << "Option 1: Rent a bike " << endl;
			cout << "Option 2: Purchase Accesories " << endl;
			cout << "Option 3: Checkout " << endl;
			cin >> option;
			cout << endl;
			//-----------------------------------------------------------------------------------
			//Bike Menu
			if (option == 1)
			{
				cout << "==================" << endl;
				cout << "| Bike Inventory |" << endl;
				cout << "==================" << endl;
				cout << "Name:            Model:      Make:       Type:      Price:" << endl;

				//loop to print out all bike arrays
				for (int i = 0; i < 10; i++)
				{
					string available = "";
					if (Bikearray[i].getavailable() == false)                                // will check if the bike is available
					{
						available = "N/A";                                                   // will set bike as N/A if not available
					}

					cout << i << "|" << Bikearray[i].getInfo() << "  " << available << endl; // if available prints out avaiable if not otherwise
				}

				int bikenum;
				cin >> bikenum;

				if (Bikearray[bikenum].getavailable())                                       // if bike is available this will get the bike array
				{
					Bikearray[bikenum].setavailable(false);
					bikeselect = bikenum;                                                    // sets bike num as bike select
					fee = Bikearray[bikeselect].getFee();                                    // retrieves bike cost
				}

				else
				{
					cout << "This bike is not available" << endl;
				}
			}
			//-----------------------------------------------------------------------------------
			// Accesory Menu
			else if (option == 2)
			{
				cout << "===============" << endl;
				cout << "| Accessories |" << endl;
				cout << "===============" << endl;
				cout << "Name:          Price:" << endl;

				//goes thru all arrays to print
				for (int i = 0; i < 5; i++)
				{
					cout << i << "|" << Accessoryarray[i].getInfo() << endl;
				}

				cout << "Pick your accessory: " << endl;
				int accessorynum;
				cin >> accessorynum;

				cout << "Pick your amount: " << endl;
				int accessoryamount;
				cin >> accessoryamount;

				//sets the amount of accessories bought
				Accessoryarray[accessorynum].setAmount(accessoryamount);
				Accessorychoices[indexaccessory] = Accessoryarray[accessorynum];
				indexaccessory++;
			}
			//-----------------------------------------------------------------------------------
			//Receipt
			else if (option == 3)
			{
				receipt << "===========================" << endl;
				receipt << "|      TJK Bike Shop      |" << endl;
				receipt << "===========================" << endl;
				receipt << "    201 Mullica Hill Rd.   " << endl;
				receipt << "    Glassboro, NJ 08028    " << endl;
				receipt << "      (856)-256-4000       " << endl;
				receipt << endl;
				receipt << "--------------------" << endl;
				receipt << "Customer's Name: " << u.getfull() << " " << u.getlast() << endl;    //prints customers first and last name into txt file
				receipt << "Phone Number: " << u.getphone() << endl;                        //customers phone number
				receipt << "Customer's DoB: " << u.getdob() << endl;                        //customers date of birth
				receipt << "--------------------" << endl;
				receipt << endl;

				receipt << "Customer's Purchases" << endl;
				receipt << "--------------------" << endl;

				int acctotal = 0;
				for (int i = 0; i < indexaccessory; i++)
				{
					//prints customer total accesories to txt file: price, info, amount, total price
					acctotal += Accessorychoices[i].getAmount() * Accessorychoices[i].getPrice();
					receipt << "Accessories: " << Accessorychoices[i].getInfo() << "  Amount: " << Accessorychoices[i].getAmount() << endl;
					receipt << "Accessory total: $" << Accessorychoices[i].getAmount() * Accessorychoices[i].getPrice() << endl;
				}


				if (bikeselect != -1)
				{
					cout << "Amount of days actually rented: " << endl;
					cin >> duration;
					cout << endl;

					if (duration > 7) //if bike is returned late
					{
						//prints customer bike cost to txt file: bike fee, deposit and late fee
						receipt << "Bike selected: " << Bikearray[bikeselect].getReceipt() << endl;
						receipt << "Days rented: " << duration << endl;
						receipt << "Bike Total: $" << (DEPOSIT + (duration * fee) + LATEFEE) << endl;
						receipt << "Total: $" << (DEPOSIT + (duration * fee) + LATEFEE) + (acctotal) << endl;
						receipt << endl;
					}
					else if (duration <= 7 && duration >= 1)//if bike is returned on time or early
					{
						//prints customer bike cost to txt file without late fee
						receipt << "Bike selected: " << Bikearray[bikeselect].getReceipt() << endl;
						receipt << "Days rented: " << duration << endl;
						receipt << "Bike Total: $" << (DEPOSIT + (duration * fee)) << endl;
						receipt << "Total: $" << (DEPOSIT + (duration * fee)) + (acctotal) << endl;
						receipt << endl;
					}
					else
					{
						cout << "Invalid value";
					}
				}
				else
				{
					receipt << "Total: $" << acctotal << endl; // calculates total final cost
					receipt << endl;
				}
			}
		} while (option != 3);
	} while (customer);
	cout << endl;
	cout << "Have a nice day!" << endl;
}
//-----------------------------------------------------------------------------------


