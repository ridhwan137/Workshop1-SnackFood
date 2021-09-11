#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Product.h"
#include "ProductManager.h"

int ProductManager::insertProduct(Product* product)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO PRODUCT (PRODUCT_NAME, PRODUCT_PRICE, PRODUCT_STOCK) VALUES(?, ?, ?)");

	ps->setString(1, product->productName);
	ps->setDouble(2, product->productPrice);
	ps->setInt(3, product->productStock);


	int status = ps->executeUpdate();
	delete ps;

	return status;
}


int ProductManager::updateProduct(Product* product)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE PRODUCT SET PRODUCT_STOCK = ? where PRODUCT_ID = ?");

	ps->setInt(1, product->productStock);
	ps->setInt(2, product->productID);

	int statusUpdate = ps->executeUpdate();

	if (statusUpdate != 0)
	{
		cout << "\n\t\t\t\tSuccessful Update Stock" << endl;
	}
	else
	{
		cout << "\n\t\t\t\tUnable to Update Stock" << endl;
	}

	delete ps;
	return statusUpdate;

}

Product* ProductManager::selectProduct(int productID)
{
	Product* product = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("Select * From PRODUCT WHERE PRODUCT_ID = ?");

	ps->setInt(1, productID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		product = new Product();
		product->productID = rs->getInt(1);
		product->productName = rs->getString(2);
		product->productPrice = rs->getDouble(3);
		product->productStock = rs->getInt(4);
	}

	delete rs;
	delete ps;

	return product;
}


Product* ProductManager::displayProduct()
{
	Product* product = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement(" Select * From PRODUCT");

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	cout << "\t\t\t\t" << "-----------------------------------------------------------------"<< endl;
	cout << "\t\t\t\t" << "|" << "No" << "|" << " ID " << "|" << "\t\tName" << "\t\t\t| Price |" << " Stock |" << endl;
	cout << "\t\t\t\t" << "-----------------------------------------------------------------"<< endl;
	while (rs->next())
	{
		product = new Product();

		product->productID = rs->getInt(1);
		product->productName = rs->getString(2);
		product->productPrice = rs->getDouble(3);
		product->productStock = rs->getInt(4);

		cout << "\t\t\t\t" << "|" << i << ".";
		cout << "|" << product->productID << "|";
		cout << "\t" << product->productName;
		cout << "\t" << "|  " << product->productPrice << "\t|";
		cout << "   " << product->productStock << "\t|";
		cout << endl;
		i++;
	}

	cout << "\t\t\t\t" << "-----------------------------------------------------------------";

	delete rs;
	delete ps;

	return product;
}

int ProductManager::deleteProduct(Product* product)
{

	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM PRODUCT WHERE PRODUCT_ID = ?");

	ps->setInt(1, product->productID);

	int status = ps->executeUpdate();
	delete ps;

	return status;

}


void ProductManager::updateQuantity(int purchaseProductID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM PURCHASE WHERE PRODUCT_ID = ?");
	int purchaseQuantity = 0;
	int productID;
	ps->setInt(1, purchaseProductID);
	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		productID = rs->getInt(2);
		purchaseQuantity = rs->getInt(3);
	}

	int productQuantity = 0;
	ps = dbConn.prepareStatement("SELECT PRODUCT_STOCK FROM PRODUCT WHERE PRODUCT_ID = ?");
	ps->setInt(1, productID);

	rs = ps->executeQuery();
	if ((rs->next()))
	{
		productQuantity = rs->getInt(1);
	}

	ps = dbConn.prepareStatement("UPDATE PRODUCT SET PRODUCT_STOCK = ? WHERE PRODUCT_ID = ?");
	ps->setInt(1, purchaseQuantity + productQuantity);
	ps->setInt(2, productID);
	ps->executeUpdate();
}

Product* ProductManager::searchProductName(string productName)
{
	Product* product = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT* FROM product WHERE Product_Name LIKE ?");

	ps->setString(1, "%" + productName + "%");

	ResultSet* rs = ps->executeQuery();


	int i = 1;
	cout << "\t\t\t\t" << "-----------------------------------------------------------------" << endl;
	cout << "\t\t\t\t" << "|" << "No" << "|" << " ID " << "|" << "\t\tName" << "\t\t\t| Price |" << " Stock |" << endl;
	cout << "\t\t\t\t" << "-----------------------------------------------------------------" << endl;
	while (rs->next())
	{
		product = new Product();

		product->productID = rs->getInt(1);
		product->productName = rs->getString(2);
		product->productPrice = rs->getDouble(3);
		product->productStock = rs->getInt(4);

		cout << "\t\t\t\t" <<"|" << i << ".";
		cout << "|" << product->productID << "|";
		cout << "\t" << product->productName;
		cout << "\t" << "|  " << product->productPrice << "\t|";
		cout << "   " << product->productStock << "\t|";
		cout << endl;
		i++;
	}

	cout << "\t\t\t\t" << "-----------------------------------------------------------------";

	delete rs;
	delete ps;

	return product;
}
