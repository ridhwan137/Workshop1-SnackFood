#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <mysql.h>

using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "Administrator.h"
#include "AdministratorManager.h"
#include "Product.h"
#include "ProductManager.h"
#include "Purchase.h"
#include "PurchaseManager.h"
#include "SaleRecord.h"
#include "SaleRecordManager.h"

#pragma warning(disable : 4996)


void AuthenticationMenu();
void Register();
void Login();

void AdminMenu(string adminID);
void AdminInformation(string adminID);
void AdminUpdatePassword(string adminID);
void AdminUpdatePhone(string adminID);

void ManageStockMenu();
void ViewStock();
void AddStock();
void DeleteStock();
void UpdateStock();

void CustomerMenu();
void CustomerOrder();
void CustomerSearchReceiptNo();

void SaleReportMenu();
void ViewSaleRecord();
void ViewSaleRecordByProductID();
void ViewSaleRecordByProductName();
void ViewSaleRecordByHighestSold();
void ViewSaleRecordByDate();

string adminID;


int main()
{
    system("cls");
    cout << "\n\n";
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t*                                         *" << endl;
    cout << "\t\t\t\t* Welcome To Snack Food Management System *" << endl;
    cout << "\t\t\t\t*                                         *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\n\n";

    system("pause");

    AuthenticationMenu();

    return 0;
}

void AuthenticationMenu()
{
    int chooseOneFromMenu = 0;
    char exitConfirmation;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t* Welcome To Snack Food Management System *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t1. Register" << endl;
    cout << "\t\t\t\t2. Login" << endl;
    cout << "\t\t\t\t3. Exit " << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        Register();
        break;
    case 2:
        Login();
        break;
    case 3:
    ExitProgram:
        cout << "\t\t\t\tProgram terminating. Are you sure? (y/N): ";
        cin >> exitConfirmation;
        if (exitConfirmation == 'y' || exitConfirmation == 'Y') {

        }
        else if (exitConfirmation == 'n' || exitConfirmation == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "\t\t\t\tWrong Input" << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "\t\t\t\tPlease choose between 1 - 3. Press Enter To Continue...";

        system("cls");
        main();
        break;
    }
    
}

void Register()
{

    Administrator* administrator = new Administrator();
    AdministratorManager administratorManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****           Register Admin          ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\n\n\t\t\t\tPlease enter the Admin ID details" << endl;

    cout << "\t\t\t\tID: ";
    cin >> administrator->adminID;

    cout << "\t\t\t\tPassword: ";
    cin.ignore(1, '\n');
    getline(cin, administrator->adminPassword);

    cout << "\t\t\t\tName: ";
    getline(cin, administrator->adminName);

    cout << "\t\t\t\tPhone: ";
    getline(cin, administrator->adminPhone);


    int status = administratorManager.registerAdmin(administrator);

    if (status != 0)
        cout << "\t\t\t\tSuccessfully register." << endl;
    else
        cout << "\t\t\t\tUnable to register." << endl;


    cout << "\n\t\t\t\tPress '1' to Authentication Menu";
    cout << "\n\t\t\t\tpress any other key to Exit:";

    cin >> choose;
    if (choose == 1)
    {
        AuthenticationMenu();
    }
    else
    {
        exit(0);
    }

}


void Login()
{
    Administrator* administrator = new Administrator();
    AdministratorManager administratorManager;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****            Login Admin            ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\n\t\t\t\tPlease enter Admin ID and Password" << endl;

    cout << "\t\t\t\tUser ID: ";
    cin.ignore(1, '\n');
    getline(cin, administrator->adminID);

    cout << "\t\t\t\tUser PW: ";
    getline(cin, administrator->adminPassword);


    if (administratorManager.loginAdmin(administrator))
    {
        cout << "\n\t\t\t\tSuccessful Login" << endl;

        system("pause");

    }
    else
    {
        AuthenticationMenu();
    }
    AdminMenu(administrator->adminID);

}

void AdminMenu(string adminID)
{
    int chooseOneFromMenu = 0;
    char exitConfirmation;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t* Welcome To Snack Food Management System *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t1. Administrator Information" << endl;
    cout << "\t\t\t\t2. Manage Stock" << endl;
    cout << "\t\t\t\t3. Customer Order" << endl;
    cout << "\t\t\t\t4. Sale Report" << endl;
    cout << "\t\t\t\t5. Exit " << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        AdminInformation(adminID);
        break;
    case 2:
        ManageStockMenu();
        break;
    case 3:
        CustomerMenu();
        break;
    case 4:
        SaleReportMenu();
        break;
    case 5:
    ExitProgram:
        cout << "\t\t\t\tProgram terminating. Are you sure? (y/N): ";
        cin >> exitConfirmation;
        if (exitConfirmation == 'y' || exitConfirmation == 'Y') {
        }
        else if (exitConfirmation == 'n' || exitConfirmation == 'N') {
            system("cls");
            main();
        }
        else {
            cout << "\t\t\t\tWrong Input" << endl;
            goto ExitProgram;
        }
        break;
    default:
        cout << "Please choose between 1 - 5. Press Enter To Continue...";
        system("cls");
        main();
        break;
    }

}


void AdminInformation(string adminID)
{
    Administrator* administrator = new Administrator();
    AdministratorManager administratorManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t*        Administrator Information        *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    administratorManager.adminInformation(adminID);

    cout << "\n\n\t\t\t\tUpdate Information?" << endl;
    cout << "\t\t\t\t1) Password" << endl;
    cout << "\t\t\t\t2) Phone" << endl;
    cout << "\t\t\t\t3) Main Menu" << endl;
    cout << "\t\t\t\tChoose One: ";
    cin >> choose;
    if (choose == 1)
    {
        AdminUpdatePassword(adminID);
    }
    else if (choose == 2)
    {
        AdminUpdatePhone(adminID);
    }
    else if (choose == 3)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 1 || choose == 2 || choose == 3))
    {
        cout << "\t\t\t\tInvalid Input";
        AdminInformation(adminID);
    }
}

void AdminUpdatePassword(string adminID)
{
    Administrator* updateAdminInfo = new Administrator();
    AdministratorManager administratorManager;

    int choose;


    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t*             Update Password             *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tEnter New Password: ";
    updateAdminInfo->adminID = adminID;
    cin.ignore(1, '\n');
    getline(cin, updateAdminInfo->adminPassword);

    int status = administratorManager.updatePassword(updateAdminInfo);

    if (status != 0)
        cout << "\t\t\t\tSuccessfully Update Password." << endl;
    else
        cout << "\t\t\t\tUnable Update Password." << endl;


    GO6:
    cout << "\n\n\n\t\t\t\tPress '1' to Admin Information Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        AdminInformation(adminID);
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto GO6;
    }
}

void AdminUpdatePhone(string adminID)
{
    int choose;
    Administrator* updateAdminInfo = new Administrator();
    AdministratorManager administratorManager;


    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t*              Update Phone               *" << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tEnter New Phone: ";
    updateAdminInfo->adminID = adminID;
    cin.ignore(1, '\n');
    getline(cin, updateAdminInfo->adminPhone);

    int status = administratorManager.updatePhone(updateAdminInfo);

    if (status != 0)
        cout << "\t\t\t\tSuccessfully Update Phone." << endl;
    else
        cout << "\t\t\t\tUnable Update Phone." << endl;


    GO7:
    cout << "\n\n\n\t\t\t\tPress '1' to Admin Information Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        AdminInformation(adminID);
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto GO7;
    }
}


void ManageStockMenu()
{
    int chooseOneFromMenu = 0;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****          Manage Product           ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t1. View Stock" << endl;
    cout << "\t\t\t\t2. Add Product" << endl;
    cout << "\t\t\t\t3. Delete Product" << endl;
    cout << "\t\t\t\t4. Update Stock" << endl;
    cout << "\t\t\t\t5. Main Menu " << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        ViewStock();
        break;
    case 2:
        AddStock();
        break;
    case 3:
        DeleteStock();
        break;
    case 4:
        UpdateStock();
        break;
    case 5:
        AdminMenu(adminID);
        break;
    default:
        cout << "\t\t\t\tPlease choose between 1 - 5. Press Enter To Continue...";
        system("cls");
        ManageStockMenu();
        break;
    }
}

void ViewStock()
{
    Product* product = new Product();
    ProductManager productManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t*****************************************************************" << endl;
    cout << "\t\t\t\t****                       View Stock                        ****" << endl;
    cout << "\t\t\t\t*****************************************************************" << endl;

    productManager.displayProduct();

    cout << endl;

    invalidInputViewStock:
    cout << "\n\n\n\t\t\t\tPress '1' to Manage Stock Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        ManageStockMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input"<< endl;
        system("pause");
        goto invalidInputViewStock;
    }

}

void AddStock()
{
    Product* product = new Product();
    ProductManager productManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****            Add Product            ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\tPlease enter the Stock details" << endl;

    cout << "\t\t\t\tProduct Name: ";
    cin.ignore(1, '\n');
    getline(cin, product->productName);

    cout << "\t\t\t\tProduct Price: ";
    cin >> product->productPrice;

    cout << "\t\t\t\tProduct Stock: ";
    cin >> product->productStock;

    int status = productManager.insertProduct(product);

    if (status != 0)
        cout << "\t\t\t\tSuccessfully added a new product." << endl;
    else
        cout << "\t\t\t\tUnable to add a new product." << endl;

    invalidInputAddStock:
    cout << "\n\t\t\t\tPress '1' to Manage Stock Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        ManageStockMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
    system("cls");
    cout << "\t\t\t\tInvalid Input" << endl;
    system("pause");
    goto invalidInputAddStock;
    }
}

void DeleteStock()
{
    Product* product = new Product();
    ProductManager productManager;

    int choose;
    system("cls");
    cout << "\t\t\t\t*****************************************************************" << endl;
    cout << "\t\t\t\t****                     Remove Product                      ****" << endl;
    cout << "\t\t\t\t*****************************************************************" << endl;

    productManager.displayProduct();

    cout << "\n\n\t\t\t\tPlease Enter Product ID to be remove: ";
    cin >> product->productID;

    int status = productManager.deleteProduct(product);

    if (status != 0)
        cout << "\t\t\t\tSuccessfully remove product." << endl;
    else
        cout << "\t\t\t\tUnable to remove product." << endl;

    invalidInputDeleteStock:
    cout << "\n\t\t\t\tPress '1' to Manage Stock Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        ManageStockMenu();
    }
    else if (choose == 2 )
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
    system("cls");
    cout << "\t\t\t\tInvalid Input" << endl;
    system("pause");
    goto invalidInputDeleteStock;
    }
}


int UpdateAddStock(int quantity, Product* product)
{
    return product->productStock = product->productStock + quantity;
}

void UpdateStock()
{
    Product* product = new Product();
    ProductManager productManager;

    int choose, quantity;

    system("cls");
    cout << "\t\t\t\t*****************************************************************" << endl;
    cout << "\t\t\t\t****                      Update Stock                       ****" << endl;
    cout << "\t\t\t\t*****************************************************************" << endl;
    productManager.displayProduct();

    cout << "\n\n\t\t\t\tPlease enter Stock details" << endl;

    cout << "\t\t\t\tProduct ID: ";
    cin >> product->productID;

    product = productManager.selectProduct(product->productID);

    cout << "\t\t\t\tProduct Stock: ";
    cin >> quantity;

    product->productStock = UpdateAddStock(quantity, product);


    int statusUpdate = productManager.updateProduct(product);
    
    invalidInputUpdateStock:
    cout << "\n\t\t\t\tPress '1' to Manage Stock Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        ManageStockMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
    system("cls");
    cout << "\t\t\t\tInvalid Input" << endl;
    system("pause");
    goto invalidInputUpdateStock;
    }

}


void CustomerMenu()
{
    int chooseOneFromMenu = 0;
  
    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****            Customer Menu          ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t1. Order Menu" << endl;
    cout << "\t\t\t\t2. Search Receipt No" << endl;
    cout << "\t\t\t\t3. Main Menu " << endl;
    cout << "\t\t\t\t*******************************************" << endl;

    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        CustomerOrder();
        break;
    case 2:
        CustomerSearchReceiptNo();
        break;
    case 3:
        AdminMenu(adminID);
        break;
    default:
        cout << "\t\t\t\tPlease choose between 1 - 3. Press Enter To Continue...";
        system("cls");
        CustomerMenu();
        break;
    }
}


int UpdateDeductStock(int quantity, Product* product)
{
    return product->productStock = product->productStock - quantity;
}


double calculateTotalPrice(double price, int quantity)
{
    double totalPrice;
    totalPrice = price * quantity;
    return totalPrice;
}

void CustomerOrder()
{
    Product* product = new Product();
    Product* productName = new Product();
    ProductManager productManager;

    Purchase* purchase = new Purchase();
    PurchaseManager purchaseManager;

    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;


    int choose,purchaseProductID,option;
    char chooseDecision;
    string answer;

    time_t rawtime;
    srand(time(&rawtime));
    int receiptOrder = rand();

    system("cls");
    cout << "\t\t\t\t*****************************************************************" << endl;
    cout << "\t\t\t\t****                       Order Menu                        ****" << endl;
    cout << "\t\t\t\t*****************************************************************" << endl;
    

    do{

    invalidInput3:
    system("cls");
    productManager.displayProduct();

    cout << "\n\n\t\t\t\tWould you like to search by Product Name?" << endl;
    cout << "\t\t\t\t1) Yes" << endl;
    cout << "\t\t\t\t2) No" << endl;
    cout << "\t\t\t\tInput: ";
    cin >> option;


    if (option == 1) {
        system("cls");
        productManager.displayProduct();
        cout << "\n\t\t\t\tInput Product Name: ";
        cin >> productName->productName;
        system("cls");
        productManager.searchProductName(productName->productName);
        cout << endl;
        goto goToProductID;
    }
    else if (option == 2) {
        goto goToProductID;
    }
    else if (!(option == 1 || option == 2)) {
        cout << "\n\n\t\t\t\tInvalid input" << endl;
        system("pause");
        goto invalidInput3;
    }


    goToProductID:
    cout << "\n\n\t\t\t\tPlease enter ID of the Product: ";
    cin >> purchase->productID;

    product = productManager.selectProduct(purchase->productID);

    cout << "\t\t\t\tQuantity: ";
    cin >> purchase->purchaseQuantity;

    cout << "\n\t\t\t\tReceipt Order: " << receiptOrder << endl;
    cout << "\n\t\t\t\tProduct ID: " << purchase->productID << endl;
    cout << "\t\t\t\tProduct Name: " << product->productName << endl;
    cout << "\t\t\t\tProduct Price: " << product->productPrice << endl;
    cout << "\t\t\t\tPurchase Quantity: " << purchase->purchaseQuantity << endl;

    cout << "\t\t\t\tTotal Price: RM ";
    purchase->totalPrice = calculateTotalPrice(product->productPrice, purchase->purchaseQuantity);
    cout << purchase->totalPrice << endl;

    purchase->receiptNo = receiptOrder;

    purchaseManager.orderItem(purchase);

    product->productStock = UpdateDeductStock(purchase->purchaseQuantity, product);

    productManager.updateProduct(product);


    invalidInput:
    cout << "\n\t\t\t\tOrder another item?";
    cout << "\n\t\t\t\tY) = Yes";
    cout << "\n\t\t\t\tN) = No";
    cout << "\n\t\t\t\tEnter Input: ";
    cin >> chooseDecision;

    if (chooseDecision == 'N' || chooseDecision == 'n')
    {
    GO1:
        system("cls");
        cout << "\n\n";
        purchaseManager.showOrderItem();

        int choice1;

        cout << "\t\t\t\tWould you like to proceed payment?" << endl;
        cout << "\t\t\t\t1) Proceed Payment" << endl;
        cout << "\t\t\t\t2) Delete Order Item" << endl;
        cout << "\t\t\t\t3) Cancel Order" << endl;
        cout << "\n\t\t\t\tEnter Input: ";
        cin >> choice1;

        if (choice1 == 1)
        {
          
            time_t now = time(0);
            char* date_time = ctime(&now);

            system("cls");
            cout << "\n\t\t\t\t\t************************";
            cout << "\n\t\t\t\t\t*  Payment Succesfull  *";
            cout << "\n\t\t\t\t\t************************";

            cout << endl;
            system("pause");

            system("cls");
            cout << "\n\t\t\t\t-------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t Receipt Order: "<< purchase->receiptNo << "\t\t\t\t" << date_time;
            purchaseManager.showOrderItem();

            saleRecordManager.saleRecord();

            purchaseManager.clearOrderItem();

            GO3:
            cout << "\n\n\t\t\t\tPress '1' to  Customer Order";
            cout << "\n\t\t\t\tPress '2' to Customer Menu: ";

            cin >> choose;
            if (choose == 1)
            {
                CustomerOrder();
            }
            else if (choose == 2)
            {
                CustomerMenu();
            }
            else if (!(choose == 2 || choose == 1))
            {
            system("cls");
            cout << "\t\t\t\tInvalid Input" << endl;
            system("pause");
            goto GO3;
            }
        }
        else if (choice1 == 2)
        {
            cout << "\t\t\t\tEnter Product ID: ";
            cin >> purchaseProductID;
            
            productManager.updateQuantity(purchaseProductID);

            int statusOrderDelete = purchaseManager.deleteOrderItem(purchaseProductID);

            if (statusOrderDelete != 0)
            {
                cout << "\t\t\t\tSuccessfully remove product." << endl;
                system("pause");
                goto GO1;
            }
            else 
            {
                cout << "\t\t\t\tUnable to remove product." << endl;
            }
        }
        else if (choice1 == 3)
        {
            system("pause");
            system("cls");

            cout << "\n\t\t\t\t\t******************************";
            cout << "\n\t\t\t\t\t*        Order Cancel        *";
            cout << "\n\t\t\t\t\t******************************";

            purchaseManager.updateAllProductStock();
            purchaseManager.clearOrderItem();

            GO4:
            cout << "\n\n\t\t\t\tPress '1' to  Customer Order";
            cout << "\n\t\t\t\tPress '2' to Customer Menu: ";

            cin >> choose;
            if (choose == 1)
            {
                CustomerOrder();
            }
            else if (choose == 2)
            {
                CustomerMenu();
            }
            else if (!(choose == 2 || choose == 1))
            {
            system("cls");
            cout << "\t\t\t\tInvalid Input" << endl;
            system("pause");
            goto GO4;
            }
        }
        else if (!(choice1 == 1 || choice1 == 2 || choice1 == 3))
        {
            system("cls");
            cout << "\t\t\t\tInvalid Input" << endl;
            system("pause");
            goto GO1;
        }

    }

    else if (!(chooseDecision == 'N' || chooseDecision == 'n' || chooseDecision == 'Y' || chooseDecision == 'y'))
    {
        cout << "\n\t\t\t\tInvalid Input !!!" << endl;
        goto invalidInput;
    }

    } while (chooseDecision == 'Y' || chooseDecision == 'y');

}


void CustomerSearchReceiptNo() 
{
    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t********************************************************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                               Customer Receipt Order                                                           ****" << endl;
    cout << "\t\t\t\t********************************************************************************************************************************************************" << endl;

    cout << "\t\t\t\tPlease input Receipt No: ";
    cin >> saleRecord->receiptNo;

    saleRecordManager.searchByReceiptNo(saleRecord->receiptNo);

    invalidInputCustomerReceipt:
    cout << "\n\n\t\t\t\tPress '1' to  Customer Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        CustomerMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputCustomerReceipt;
    }
}


void SaleReportMenu()
{
    int chooseOneFromMenu;

    system("cls");
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t****            Sale Report            ****" << endl;
    cout << "\t\t\t\t*******************************************" << endl;
    cout << "\t\t\t\t1. View Sale Record" << endl;
    cout << "\t\t\t\t2. View Sale Record By Product ID" << endl;
    cout << "\t\t\t\t3. View Sale Record By Product Name" << endl;
    cout << "\t\t\t\t4. View Sale Record By Highest Product Sold" << endl;
    cout << "\t\t\t\t5. View Sale Record By Date" << endl;
    cout << "\t\t\t\t6. Main Menu " << endl;
    cout << "\t\t\t\t*******************************************" << endl;


    cout << "\t\t\t\tChoose One: ";
    cin >> chooseOneFromMenu;

    switch (chooseOneFromMenu)
    {
    case 1:
        ViewSaleRecord();
        break;
    case 2:
        ViewSaleRecordByProductID();
        break;
    case 3:
        ViewSaleRecordByProductName();
        break;
    case 4:
        ViewSaleRecordByHighestSold();
        break;
    case 5:
        ViewSaleRecordByDate();
        break;
    case 6:
        AdminMenu(adminID);
        break;
    default:
        cout << "\t\t\t\tPlease choose between 1 - 6. Press Enter To Continue...";
        system("cls");
        SaleReportMenu();
        break;
    }


}


void ViewSaleRecord()
{
    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                  Sale Record                                                  ****" << endl;
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;


    saleRecordManager.showSaleRecord();

    invalidInputViewStock:
    cout << "\n\n\t\t\t\tPress '1' to  Sale Report Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        SaleReportMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputViewStock;
    }
}


void ViewSaleRecordByProductID()
{
    Product* product = new Product();
    ProductManager productManager;

    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                  Sale Record                                                  ****" << endl;
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;

    productManager.displayProduct();

    cout << "\n\t\t\t\tEnter Product ID: ";
    cin >> saleRecord->productID;

    saleRecordManager.searchByProductID(saleRecord->productID);


    invalidInputViewByProductID:
    cout << "\n\n\t\t\t\tPress '1' to  Sale Report Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        SaleReportMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputViewByProductID;
    }
}

void ViewSaleRecordByProductName()
{
    Product* product = new Product();
    ProductManager productManager;

    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                  Sale Record                                                  ****" << endl;
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;

    productManager.displayProduct();

    cout << "\n\t\t\t\tEnter Product Name: ";
    cin >> saleRecord->productName;

    saleRecordManager.searchByProductName(saleRecord->productName);

    invalidInputViewByProductName:
    cout << "\n\n\t\t\t\tPress '1' to  Sale Report Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        SaleReportMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputViewByProductName;
    }
}


void ViewSaleRecordByHighestSold()
{
    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;

    system("cls");
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                  Sale Record                                                  ****" << endl;
    cout << "\t\t\t\t***********************************************************************************************************************" << endl;

    saleRecordManager.searchByHighestSold();

    invalidInputViewByHighestSold:
    cout << "\n\n\t\t\t\tPress '1' to  Sale Report Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        SaleReportMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputViewByHighestSold;
    }
}

void ViewSaleRecordByDate()
{
    SaleRecord* saleRecord = new SaleRecord();
    SaleRecordManager saleRecordManager;

    int choose;
    //string dateSold1, dateSold2;


    system("cls");
    cout << "\t\t\t\t****************************************************************************************************************************************" << endl;
    cout << "\t\t\t\t****                                                           Sale Record                                                          ****" << endl;
    cout << "\t\t\t\t****************************************************************************************************************************************" << endl;

    cout << "\n\t\t\t\tEnter Date Range Ex: 2021-06-01 ~ 2021-06-31" << endl;
    cout << "\n\t\t\t\tNote!!!: Second Date must +1 from the current date desire." << endl;
    cout << "\n\t\t\t\tExample to get Date in range (2021-06-01 to 2021-06-07)" << endl;
    cout << "\t\t\t\tDate 1: 2021-06-01" << endl;
    cout << "\t\t\t\tDate 2: 2021-06-08" << endl;

    cout << "\n\n\t\t\t\tEnter Date 1 (Ex:2021-06-01): ";
    cin >> saleRecord->dateSold1;

    cout << "\t\t\t\tEnter Date 2 (Ex:2021-06-31): ";
    cin >> saleRecord->dateSold2;

    saleRecordManager.searchByDate(saleRecord->dateSold1, saleRecord->dateSold2);


    invalidInputViewByDate:
    cout << "\n\n\t\t\t\tPress '1' to  Sale Report Menu";
    cout << "\n\t\t\t\tPress '2' to Main Menu: ";

    cin >> choose;
    if (choose == 1)
    {
        SaleReportMenu();
    }
    else if (choose == 2)
    {
        AdminMenu(adminID);
    }
    else if (!(choose == 2 || choose == 1))
    {
        system("cls");
        cout << "\t\t\t\tInvalid Input" << endl;
        system("pause");
        goto invalidInputViewByDate;
    }
}
