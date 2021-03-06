// UNiDAYS-Placement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnidaysDiscountChallenge.h"
#include <iostream>
using namespace std;



int main()
{
	UnidaysDiscountChallenge example;	//Declarations
	double totalPrice, deliveryCharge, overallPrice;
	
	example = UnidaysDiscountChallenge();	//initialise class 
	example.addToBasket('a');	//Add items to basket
	example.addToBasket('a');
	//example.addToBasket('c');
	//example.addToBasket('b');
	//example.addToBasket('a');
	//example.addToBasket('e');
	//example.addToBasket('d');
	//example.addToBasket('c');
	//example.addToBasket('b');
	//example.addToBasket('c');

	totalPrice = example.calculateTotalPrice();		//set totalPrice to the price of everything including discounts but excluding the delivery charge
	deliveryCharge = example.getDeliveryCharge();	//set deliverycharge
	overallPrice = totalPrice + deliveryCharge;		//complete and final price calculated by adding the delivery charge and total price
	cout << "Total Price: " << totalPrice;			//output a little message to display the results of the prices calculated.
	cout << "\nDelivery Charge: " << deliveryCharge;
	cout << "\nOverall Price: " << overallPrice << endl;
    system("pause");	//produce "Press any key..." message
	return 0;
}

