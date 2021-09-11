#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Administrator.h"
#include "AdministratorManager.h"

int AdministratorManager::registerAdmin(Administrator* Administrator)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO Administrator VALUES (?, ?, ?, ?)");

	ps->setString(1, Administrator->adminID);
	ps->setString(2, Administrator->adminPassword);
	ps->setString(3, Administrator->adminName);
	ps->setString(4, Administrator->adminPhone);

	int status = ps->executeUpdate();
	delete ps;

	return status;
}


bool AdministratorManager::loginAdmin(Administrator* admin)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM Administrator WHERE admin_ID = ? AND admin_Password = ?");

	ps->setString(1, admin->adminID);
	ps->setString(2, admin->adminPassword);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\t\t\tWrong ID or Password. Please try again." << endl;
		system("pause");
		system("cls");
		return false;
	}

	delete rs;
	delete ps;

	return true;
}

Administrator* AdministratorManager::adminInformation(string adminID)
{
	Administrator* administrator = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM ADMINISTRATOR WHERE ADMIN_ID = ? ");
	ps->setString(1, adminID);
	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		administrator = new Administrator();

		administrator->adminID = rs->getString(1);
		administrator->adminPassword = rs->getString(2);
		administrator->adminName = rs->getString(3);
		administrator->adminPhone = rs->getString(4);

		cout << "\t\t\t\tID: " << administrator->adminID << endl;
		cout << "\t\t\t\tPassword: " << administrator->adminPassword << endl;
		cout << "\t\t\t\tName: " << administrator->adminName << endl;
		cout << "\t\t\t\tPhone: " << administrator->adminPhone << endl;
	}

	delete rs;
	delete ps;

	return administrator;

}

int AdministratorManager::updatePhone(Administrator* admin)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ADMINISTRATOR SET ADMIN_PHONE = ? WHERE ADMIN_ID = ?");

	ps->setString(1, admin->adminPhone);
	ps->setString(2, admin->adminID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int AdministratorManager::updatePassword(Administrator* admin)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE ADMINISTRATOR SET ADMIN_PASSWORD = ? WHERE ADMIN_ID = ?");

	ps->setString(1, admin->adminPassword);
	ps->setString(2, admin->adminID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}