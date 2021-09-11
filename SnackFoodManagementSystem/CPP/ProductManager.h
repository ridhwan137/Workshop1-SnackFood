#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

class ProductManager
{
public:
	int insertProduct(Product* product);
	int updateProduct(Product* product);
	int deleteProduct(Product* product);

	Product* displayProduct();
	Product* selectProduct(int productID);

	Product* searchProductName(string productName);

	void updateQuantity(int purchaseProductID);
};

#endif 


