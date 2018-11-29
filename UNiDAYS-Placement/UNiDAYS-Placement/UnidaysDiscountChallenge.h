#pragma once
class UnidaysDiscountChallenge
{
private:
	int Basket[5] = {0,0,0,0,0};
	double Total = 0;
	double DeliveryCharge = 0;
	struct Items {
		char name;	//it's name (a,b,c...)
		double price;	//it's price
		int dscreq;	//the amount that needs to be in the basket to apply a discount.
		double dscprice;	//the price of once one set of the discount requirements has been met.
	};
	Items Item[5]; //= { 'a','b','c','d','e',8,12,4,7,5,NULL,2,3,1,3,NULL,20,10,7,10 }; //Create an array of Struct Items for each item

public:
	UnidaysDiscountChallenge();		// This can be deleted and replaced by the commented code above (Items Item[5]) however this looks more understandable so it is a matter of preference.
	void addToBasket(char item);
	double calculateTotalPrice();
	double getDeliveryCharge();
};