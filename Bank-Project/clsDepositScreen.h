#pragma once
#include "clsScreen.h";
#include <iomanip>;
//#include "clsInputValidate.h";
#include "clsBankClient.h";
class clsDepositScreen:protected clsScreen
{
private :
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "\nPlease enter account number ?";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

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
	static void ShowDepositScreen() {
		_DrawScreenHeader("\tDeposit Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient with [" << AccountNumber << "does not exist?";
			AccountNumber = _ReadAccountNumber();
		}

		 clsBankClient Client = clsBankClient::Find(AccountNumber);

		 _PrintClient(Client);
		 cout << "\nPlease enter Amount to deposit ? ";
		 double Amount = clsInputValidate::ReadDblNumber();
		 char Answer = 'n';
		 cout << "Are you sure you want to perform this Transaction ? ";
		 cin >> Answer;

		 if (tolower(Answer) == 'y') {
			 Client.Deposit(Amount);
			 cout << "\nAmount Deposited Successfully :-)";
			 cout << "\nNew Balance is : " << Client.AccountBalance << endl;

		 }
		 else {
			 cout << "\nOperation was canceled \n";
		 }
	}
};

