#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";
//#include "clsInputValidate.h";

class clsUpdateClientScreen:protected clsScreen
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
	static  void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter AccountBalance : ";
		Client.AccountBalance = clsInputValidate::ReadfloatNumber();
	}

public:




	static void ShowUpdateClientScreen() {

		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
			return;
		}
		_DrawScreenHeader("\t Update Client Screen ");

	    cout << "\nPlease enter Client AccountNumber : ";
	    string AccountNumber = clsInputValidate::ReadString();
	    while (!clsBankClient::IsClientExist(AccountNumber)) {
	        cout << "\nAccountNumber is not found ,Choose another  one : ";
	         AccountNumber = clsInputValidate::ReadString();
	    }
	
	   clsBankClient Client1= clsBankClient::Find(AccountNumber);
	   _PrintClient(Client1);

	
	   cout << "\nUpdate Client Info:\n";
	   cout << "_______________________\n";
	   _ReadClientInfo(Client1);
	
	   clsBankClient::enSaveResults SaveResult;
	
	   SaveResult = Client1.Save();
	
	   switch (SaveResult) {
	   case clsBankClient::enSaveResults::svSuccessed:
	       cout << "\nAccount Updated Successfully :-)\n";
		   _PrintClient(Client1);
	       break;
	   case clsBankClient::enSaveResults::svFalidEmptyObject:
	       cout << "\nError account was not saved because it's Empty ";
	
	       break;
	
	   }
	}
	
	

};

