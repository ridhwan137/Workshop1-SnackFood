#ifndef ADMINISTRATORMANAGER_H
#define ADMINISTRATORMANAGER_H

class AdministratorManager
{
public:
	int registerAdmin(Administrator* admin);
	bool loginAdmin(Administrator* admin);

	Administrator* adminInformation(string adminID);

	int updatePassword(Administrator* admin);
	int updatePhone(Administrator* admin);
};

#endif 

