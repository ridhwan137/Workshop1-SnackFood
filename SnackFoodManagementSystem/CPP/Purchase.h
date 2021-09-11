#include <string>
#include<ctime>
using namespace std;

#ifndef PURCHASE_H
#define PURCHASE_H

class Purchase
{
public:
	string productName;
	int productStock,productID,purchaseID,purchaseQuantity,receiptNo;
	double productPrice,totalPrice;

	string dateSold;
};

#endif
