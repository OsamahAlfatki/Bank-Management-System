#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";
//#include "clsInputValidate.h";

class clsFindClientScreen :protected clsScreen
{

	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;


		cout << "\n___________________\n";
	}

public:




	static void ShowFindClientScreen() {
		if (!_CheckAccessRights(clsUser::enPermissions::pFindClients)) {
			return;
		}
		_DrawScreenHeader("\t Find Client Screen ");

		cout << "\nPlease enter Client AccountNumber : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccountNumber is not found ,Choose another  one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		

		if (!Client1.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		
		}
		else {
			cout << "\nClient was not found\n ";
		}
		_PrintClient(Client1);

	}



};


