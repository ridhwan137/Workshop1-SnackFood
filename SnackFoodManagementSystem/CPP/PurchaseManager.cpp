#include <iostream>
#include <string>
#include <iomanip>
#include<ctime>

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Purchase.h"
#include "PurchaseManager.h"

int PurchaseManager::orderItem(Purchase* purchase)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO `purchase` ( `PRODUCT_ID`, `PURCHASE_QUANTITY`, `PURCHASE_TOTALPRICE`, `RECEIPT_NO`) VALUES (?,?,?,?);");

	//ps->setInt(1, purchase->purchaseID);
	ps->setInt(1, purchase->productID);
	ps->setInt(2, purchase->purchaseQuantity);
	ps->setDouble(3, purchase->totalPrice);
	ps->setInt(4, purchase->receiptNo);

	int statusPurchase = ps->executeUpdate();

	if (statusPurchase != 0)
	{
		cout << "\n\t\t\t\tSuccessful Add Order" << endl;
	}
	else
	{
		cout << "\n\t\t\t\tUnable to Add Order" << endl;
	}

	delete ps;
	return statusPurchase;

	/*
	int status;

	try {
		return  status = ps->executeUpdate();
	}
	catch (SQLException & e) {
		cout << e.what();
	}

	delete ps;
	*/
}

/*
Purchase* PurchaseManager::displayOrderItem()
{
	Purchase* purchase = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM PURCHASE");

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	double total = 0;

	cout << "----------------------------------------------" << endl;
	//cout << "|Purchase ID| Product ID | Product Quantity | Total Price|" << endl;
	cout << "| Product ID | Product Quantity | Total Price|" << endl;
	cout << "----------------------------------------------" << endl;

	while (rs->next())
	{
		purchase = new Purchase();

		//purchase->purchaseID = rs->getInt(1);
		purchase->productID = rs->getInt(2);
		purchase->purchaseQuantity = rs->getInt(3);
		purchase->totalPrice = rs->getDouble(4);

		//cout << "|   " << purchase->purchaseID << "    |";
		//cout << "\t" << purchase->productID;

		cout << "|   "  << purchase->productID << "     |";
		cout << "\t      " << purchase->purchaseQuantity << "\t        |";
		cout <<"     " << purchase->totalPrice << "     |";
		cout << endl;

		total = total + purchase->totalPrice;
		i++;
	}
	cout << "----------------------------------------------" << endl;
	cout << "\t\t\t   " << "Total:   RM"<< total << endl;
	cout << "----------------------------------------------" << endl;

	delete rs;
	delete ps;

	return purchase;

}
*/

Purchase* PurchaseManager::showOrderItem()
{
	Purchase* purchase = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT purchase.PRODUCT_ID ,product.PRODUCT_NAME ,purchase.PURCHASE_QUANTITY,purchase.PURCHASE_TOTALPRICE FROM PRODUCT product, PURCHASE purchase WHERE purchase.PRODUCT_ID = product.PRODUCT_ID");

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	double total = 0;

	cout << "\t\t\t\t" << "-------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |            Product Name          | Quantity | Total Price|" << endl;
	cout << "\t\t\t\t" << "-------------------------------------------------------------------------" << endl;

	while (rs->next())
	{
		purchase = new Purchase();

		purchase->productID = rs->getInt(1);
		purchase->productName = rs->getString(2);
		purchase->purchaseQuantity = rs->getInt(3);
		purchase->totalPrice = rs->getDouble(4);


		cout << "\t\t\t\t" << "|   " << purchase->productID << "     |";
		cout << "   " << purchase->productName;
		cout << "\t|     " << purchase->purchaseQuantity << "\t   |";
		cout << "     " << purchase->totalPrice << "     |";
		cout << endl;

		total = total + purchase->totalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "-------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "\t\t\t\t\t\t      " << "Total:   RM" << total << endl;
	cout << "\t\t\t\t" << "-------------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return purchase;

}


int PurchaseManager::deleteOrderItem(int purchaseProductID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM PURCHASE WHERE PRODUCT_ID =?");

	ps->setInt(1, purchaseProductID);

	int statusOrderDelete = ps->executeUpdate();
	delete ps;
	return statusOrderDelete;
}

Purchase* PurchaseManager::clearOrderItem()
{
	Purchase* purchase = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM PURCHASE");

	ResultSet* rs = ps->executeQuery();

	delete rs;
	delete ps;

	return purchase;
}

Purchase* PurchaseManager::updateAllProductStock()
{
	Purchase* purchase = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE PRODUCT product1 INNER JOIN (SELECT purchase.PRODUCT_ID, SUM(product2.PRODUCT_STOCK + purchase.PURCHASE_QUANTITY) AS PRODUCT_STOCK FROM PRODUCT product2 INNER JOIN PURCHASE purchase ON product2.PRODUCT_ID = purchase.PRODUCT_ID GROUP BY product2.PRODUCT_ID) AS p ON product1.PRODUCT_ID = p.PRODUCT_ID SET product1.PRODUCT_STOCK = p.PRODUCT_STOCK");
	
	ResultSet * rs = ps->executeQuery();

	delete rs;
	delete ps;

	return purchase;
}