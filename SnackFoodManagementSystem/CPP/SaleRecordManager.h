#ifndef SALERECORDMANAGER_H
#define SALERECORDMANAGER_H

class SaleRecordManager
{
public:

	SaleRecord* saleRecord();
	SaleRecord* showSaleRecord();
	//SaleRecord* displaySaleRecord();

	SaleRecord* searchByProductID(int productID);
	SaleRecord* searchByProductName(string productName);
	SaleRecord* searchByHighestSold();
	SaleRecord* searchByDate(string dateSold1,string dateSold2);

	SaleRecord* searchByReceiptNo(int receiptNo);
};

#endif 
