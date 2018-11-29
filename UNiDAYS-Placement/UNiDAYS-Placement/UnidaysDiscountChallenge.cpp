#include "stdafx.h"
#include "UnidaysDiscountChallenge.h"
#include <iostream>
using namespace std;


UnidaysDiscountChallenge::UnidaysDiscountChallenge()	//Constructor
{
	
	Item[0].name = 'a';		//item name
	Item[0].price = 8.00;	//item price
	Item[0].dscreq = NULL;	//as there is no discount for this item the required amount to recieve a discount is NULL
	Item[0].dscprice = NULL;//no discount so no discount price so left as NULL


	Item[1].name = 'b';
	Item[1].price = 12.00;
	Item[1].dscreq = 2;			//to recieve a discount they must buy 2 of this product
	Item[1].dscprice = 20.00;	//and pay £20 for 2


	Item[2].name = 'c';
	Item[2].price = 4.00;
	Item[2].dscreq = 3;			//need 3
	Item[2].dscprice = 10.00;	//pay £10 for 3


	Item[3].name = 'd';
	Item[3].price = 7.00;
	Item[3].dscreq = 2;				//need 2
	Item[3].dscprice = 7.00;	//pay the price of 1 for 2


	Item[4].name = 'e';
	Item[4].price = 5.00;
	Item[4].dscreq = 3;					//need 3
	Item[4].dscprice = 10.00;	//pay the price of 2 for 3
}

void UnidaysDiscountChallenge::addToBasket(char item)
{
	switch (item)	//switch statement to increment the corresponding item quantity
	{
	case 'a':			//when item a is passed as the parameter to be added to basket
		++Basket[0];	//it increments the value currently stored in Basket[0] by 1
		break;
	case 'b':			
		++Basket[1];
		break;
	case 'c':
		++Basket[2];
		break;
	case 'd':
		++Basket[3];
		break;
	case 'e':
		++Basket[4];
		break;
	default:
		cout << "no such items exists, Please make sure item entered is lowercase" << endl;	//Error message incase invalid item is tried to be added to the basket
		break;
	}
}

double UnidaysDiscountChallenge::calculateTotalPrice()
{
	int i = 0, r = 1;	//declare and initialise values i and r it doesn't matter what i's value is initialised with but r needs to be 1
	
	for (int x = 0; x < 5; x++)		//this runs through all items
	{
		while (Basket[x] !=0)	//if an item doesn't have anything in the basket then simply do nothing and go onto the next item.
		{
			if (Item[x].dscreq != 0)	//this is to avoid division by 0, if the item has a possible discount then...
			{
				i = Basket[x] / Item[x].dscreq;		//how many times the discount can be applied with the amount in the basket
				Total += i * Item[x].dscprice;		//then times it by the discount price and add it to the current total
				r = Basket[x] % Item[x].dscreq;		//find out how many items in the basket CAN'T meet the discount requirements
				Total += r * Item[x].price;		//then times it by the normal price and add it to the current total
			}
			else	//this else statement to calculate the normal price of items that can't have a discount no matter the amount
			{
				Total += Basket[x] * Item[x].price;		//amount in the basket times by the items price added to the current total
			}
			Basket[x] = 0;	//change basket value to exit the while loop
		}
	}
	
	if ((Total < 50) and (Total > 0))	//work out the delivery charge so that the total below £50 and more than £0 is a £7 delivery charge
		DeliveryCharge = 7.00;
	
	return Total;	//return the Total excluding the delivery charge
}

double UnidaysDiscountChallenge::getDeliveryCharge()
{
	return DeliveryCharge;	//simply returns the delivery charge
}


