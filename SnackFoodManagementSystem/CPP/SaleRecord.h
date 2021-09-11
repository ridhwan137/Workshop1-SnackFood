#include <string>
#include<ctime>
using namespace std;

#ifndef SALERECORD_H
#define SALERECORD_H

class SaleRecord
{
public:
	string productName;
	int productStock, productID;
	double productPrice;

	int purchaseID, purchaseQuantity;
	double purchaseTotalPrice;

	string dateSold,dateSold1,dateSold2;

	int receiptNo;
};

#endif