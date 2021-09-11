#ifndef PURCHASEMANAGER_H
#define PURCHASEMANAGER_H

class PurchaseManager
{
public:
	int orderItem(Purchase* purchase);
	Purchase* showOrderItem();
	//Purchase* displayOrderItem();

	int deleteOrderItem(int purchaseProductID);
	Purchase* clearOrderItem();

	Purchase* updateAllProductStock();

	//Purchase* saleRecord();
	//Purchase* displaySaleRecord();
};

#endif 
