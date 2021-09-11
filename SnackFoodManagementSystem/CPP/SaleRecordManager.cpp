#include <iostream>
#include <string>
#include <iomanip>
#include<ctime>

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "SaleRecord.h"
#include "SaleRecordManager.h"

SaleRecord* SaleRecordManager::saleRecord()
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps;
	ps = dbConn.prepareStatement("INSERT INTO SALERECORD (PURCHASE_ID, PRODUCT_ID, PURCHASE_QUANTITY, PURCHASE_TOTALPRICE, RECEIPT_NO) SELECT PURCHASE_ID, PRODUCT_ID, PURCHASE_QUANTITY, PURCHASE_TOTALPRICE, RECEIPT_NO FROM PURCHASE");

	ResultSet* rs = ps->executeQuery();

	delete rs;
	delete ps;

	return saleRecord;
}

/*
SaleRecord* SaleRecordManager::displaySaleRecord()
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM SALERECORD");

	ResultSet* rs = ps->executeQuery();

	cout << "--------------------------------------------------------------------" << endl;
	cout << "| Product ID | Product Quantity | Total Price |     Date Sold      |" << endl;
	cout << "--------------------------------------------------------------------" << endl;

	int i = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);
		saleRecord->dateSold = rs->getString(6);
		//purchase->dateSold = rs->getInt("UNIX_TIMESTAMP(DATESOLD)");

		cout << "|   " << saleRecord->productID << "     |";
		cout << "\t      " << saleRecord->purchaseQuantity << "\t        |";
		cout << "     " << saleRecord->purchaseTotalPrice << "     |";
		cout << " " << saleRecord->dateSold << " |";
		cout << endl;

		i++;
	}
	cout << "--------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return saleRecord;
}
*/

SaleRecord* SaleRecordManager::showSaleRecord()
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT product.PRODUCT_ID, product.PRODUCT_NAME, product.PRODUCT_PRICE,salerecord.PURCHASE_QUANTITY, salerecord.PURCHASE_TOTALPRICE, salerecord.DATESOLD FROM product product, salerecord salerecord WHERE product.PRODUCT_ID = salerecord.PRODUCT_ID");

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |          Product Name            | Product Price |    Quantity      | Total Price |      Date Sold      |" << endl;
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(1);
		saleRecord->productName = rs->getString(2);
		saleRecord->productPrice = rs->getDouble(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);
		saleRecord->dateSold = rs->getString(6);
		//purchase->dateSold = rs->getInt("UNIX_TIMESTAMP(DATESOLD)");

		cout << "\t\t\t\t" << "|   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t  " << saleRecord->purchaseQuantity << "        |";
		cout << "     " << saleRecord->purchaseTotalPrice << "\t |";
		cout << " " << saleRecord->dateSold << " |";
		cout << endl;

		total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "\t\t\t\t\t\t      " << "Total Sale: RM" << total << endl;
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return saleRecord;
}

SaleRecord* SaleRecordManager::searchByProductID(int productID)
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement(" SELECT p.Product_ID, p.Product_Name, p.Product_Price, SUM(s.Purchase_Quantity) AS TotalQuantitySold, SUM(s.Purchase_Quantity * p.Product_Price) AS OverallTotalPrice FROM SaleRecord AS s INNER JOIN Product AS p ON s.Product_ID = p.Product_ID WHERE p.Product_ID = ? GROUP BY s.Product_ID");

	ps->setInt(1, productID);

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |          Product Name            | Product Price |    Total Quantity Sold      | Total Price (RM) |" << endl;
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	//double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(1);
		saleRecord->productName = rs->getString(2);
		saleRecord->productPrice = rs->getDouble(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);


		cout << "\t\t\t\t" << "|   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t\t" << saleRecord->purchaseQuantity << "\t      |";
		cout << "\t       " << saleRecord->purchaseTotalPrice << "\t |";
		cout << endl;

		//total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << "\t\t\t\t\t\t      " << "Total Sale: RM" << total << endl;
	//cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return saleRecord;
}

SaleRecord* SaleRecordManager::searchByProductName(string productName)
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT p.Product_ID, p.Product_Name, p.Product_Price, SUM(s.Purchase_Quantity) AS TotalQuantitySold, SUM(s.Purchase_Quantity * p.Product_Price) AS OverallTotalPrice FROM SaleRecord AS s INNER JOIN Product AS p ON s.Product_ID = p.Product_ID WHERE p.Product_Name LIKE ? GROUP BY s.Product_ID");

	ps->setString(1, "%" + productName + "%");

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |          Product Name            | Product Price |    Total Quantity Sold      | Total Price (RM) |" << endl;
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	//double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(1);
		saleRecord->productName = rs->getString(2);
		saleRecord->productPrice = rs->getDouble(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);


		cout << "\t\t\t\t" << "|   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t\t" << saleRecord->purchaseQuantity << "\t      |";
		cout << "\t       " << saleRecord->purchaseTotalPrice << "\t |";
		cout << endl;

		//total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << "\t\t\t\t\t\t      " << "Total Sale: RM" << total << endl;
	//cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


	if (saleRecord != 0)
	{
		cout << "\n\t\t\t\tSuccessful Search" << endl;
	}
	else
	{
		cout << "\n\t\t\t\tUnable to Search" << endl;
	}

	delete rs;
	delete ps;

	return saleRecord;
}


SaleRecord* SaleRecordManager::searchByHighestSold()
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT p.Product_ID, p.Product_Name, p.Product_Price, SUM(s.Purchase_Quantity) AS TotalQuantitySold, SUM(s.Purchase_Quantity*p.Product_Price) AS OverallTotalPrice FROM SaleRecord AS s INNER JOIN Product AS p ON s.Product_ID = p.Product_ID GROUP BY s.Product_ID ORDER BY OverallTotalPrice DESC");

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |          Product Name            | Product Price |    Total Quantity Sold      | Total Price (RM) |" << endl;
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	//double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(1);
		saleRecord->productName = rs->getString(2);
		saleRecord->productPrice = rs->getDouble(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);


		cout << "\t\t\t\t" << "|   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t\t" << saleRecord->purchaseQuantity << "\t      |";
		cout << "\t       " << saleRecord->purchaseTotalPrice << "\t |";
		cout << endl;

		//total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "------------------------------------------------------------------------------------------------------------------" << endl;
	//cout << "\t\t\t\t\t\t      " << "Total Sale: RM" << total << endl;
	//cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


	if (saleRecord != 0)
	{
		cout << "\n\t\t\t\tSuccessful Search" << endl;
	}
	else
	{
		cout << "\n\t\t\t\tUnable to Search" << endl;
	}

	delete rs;
	delete ps;

	return saleRecord;
}


SaleRecord* SaleRecordManager::searchByDate(string dateSold1,string dateSold2)
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT p.Product_ID, p.Product_Name, p.Product_Price, s.Purchase_Quantity AS TotalQuantitySold, s.Purchase_TotalPrice AS OverallTotalPrice, s.DATESOLD FROM Product p LEFT JOIN salerecord s ON s.Product_ID = p.Product_ID WHERE s.DateSold BETWEEN ? AND ? ");

	ps->setString(1, dateSold1);
	ps->setString(2, dateSold2);

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "| Product ID |          Product Name            | Product Price |    Total Quantity Sold      | Total Price (RM) |      Date Sold      |" << endl;
	cout << "\t\t\t\t" << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->productID = rs->getInt(1);
		saleRecord->productName = rs->getString(2);
		saleRecord->productPrice = rs->getDouble(3);
		saleRecord->purchaseQuantity = rs->getInt(4);
		saleRecord->purchaseTotalPrice = rs->getDouble(5);
		saleRecord->dateSold = rs->getString(6);

		cout << "\t\t\t\t" << "|   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t  "<<"      "<< saleRecord->purchaseQuantity << "     " << "        |";
		cout << "        " << saleRecord->purchaseTotalPrice << "\t |";
		cout << " " << saleRecord->dateSold << " |";
		cout << endl;

		total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "\t\t\t\t\t\t      " << "Total Sale: RM" << total << endl;
	cout << "\t\t\t\t" << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return saleRecord;
}

SaleRecord* SaleRecordManager::searchByReceiptNo(int receiptNo)
{
	SaleRecord* saleRecord = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT s.Receipt_No, p.Product_ID, p.Product_Name, p.Product_Price, s.Purchase_Quantity, s.Purchase_TotalPrice, s.DateSold FROM SaleRecord AS s INNER JOIN Product AS p ON s.Product_ID = p.Product_ID WHERE s.Receipt_No = ?");

	ps->setInt(1, receiptNo);

	ResultSet* rs = ps->executeQuery();

	cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "|  Receipt No  | Product ID |           Product Name            | Product Price |          Quantity           | Total Price (RM) |      Date Sold      |" << endl;
	cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	int i = 0;
	double total = 0;

	while (rs->next())
	{
		saleRecord = new SaleRecord();
		saleRecord->receiptNo = rs->getInt(1);
		saleRecord->productID = rs->getInt(2);
		saleRecord->productName = rs->getString(3);
		saleRecord->productPrice = rs->getDouble(4);
		saleRecord->purchaseQuantity = rs->getInt(5);
		saleRecord->purchaseTotalPrice = rs->getDouble(6);
		saleRecord->dateSold = rs->getString(7);

		cout << "\t\t\t\t" << "|     " << saleRecord->receiptNo << "    |";
		cout << "   " << saleRecord->productID << "     |";
		cout << "     " << saleRecord->productName << "";
		cout << "\t|      " << saleRecord->productPrice << "\t|";
		cout << "\t\t" << saleRecord->purchaseQuantity << "\t      |";
		cout << "\t       " << saleRecord->purchaseTotalPrice << "\t |";
		cout << " " << saleRecord->dateSold << " |";
		cout << endl;

		total = total + saleRecord->purchaseTotalPrice;
		i++;
	}
	cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "\t\t\t\t\t\t\t      " << "Total Price: RM" << total << endl;
	cout << "\t\t\t\t" << "--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	delete rs;
	delete ps;

	return saleRecord;
}