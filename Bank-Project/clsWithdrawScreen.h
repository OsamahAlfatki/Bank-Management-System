#pragma once

#include "clsBankClient.h";
#include<iomanip>
#include "clsScreen.h";
//#include"clsInputValidate.h";
class clsWithdrawScreen:protected clsScreen
{
private:
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
	static void ShowWithdrawScreen() {

		_DrawScreenHeader("\tWithdraw Screen");
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Client with [" << AccountNumber << "] dose not exist \n";
			AccountNumber = _ReadAccountNumber();
		}
		 clsBankClient Client1 =clsBankClient::Find(AccountNumber);
		 _PrintClient(Client1);

		 cout << "\nEnter Amount to withdraw ?";

		 double Amount = clsInputValidate::ReadDblNumber();

		 cout << "Are you sure you want to perform this transaction ?";
		 char Answer = 'n';
		 cin >> Answer;
		 if (tolower(Answer) == 'y') {
			 if (Client1.Withdraw(Amount)) {
				 cout << "Amount Withdrawed Successfully \n";
				 cout << "New Balance is : " << Client1.AccountBalance << endl;

			 }
			 else {
				 cout << "cannot withdraw insuffecient  Balance !\n";
				 cout << "Your Balance = " << Client1.AccountBalance << endl;
				 cout << "\nAmount  to withdraw = " << Amount << endl;
			 }
		 }
		 else {
			 cout << "\n Operation was cancelled !";
		 }

	}
};

