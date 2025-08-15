#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsShowTransferScreen :protected clsScreen
{
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
	
	
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;

		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber(string Message) {
		cout << Message;
		string SenderAccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(SenderAccountNumber))
		{
			cout << "\nClient with Account Number [" << SenderAccountNumber << "] is not found ,Enter another one ?";
			SenderAccountNumber = clsInputValidate::ReadString();
		}
		return SenderAccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient){
		double Amount = 0;
		cout << "\n\nEnter Transfer Amount ?";
		Amount = clsInputValidate::ReadDblNumber();
		while (Amount>SourceClient.AccountBalance) {
			cout << "\nAmount Exceeds the  availble balance,Enter another amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;

	}

public :
	static void ShowTransferScreen() {

		_DrawScreenHeader("\t Transfer Screen");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("Please enter Account Number to Transfer from : "));
		_PrintClient(SourceClient);

		
		clsBankClient DestnationClient = clsBankClient::Find(_ReadAccountNumber("Please enter Account Number to Transfer to : "));
		_PrintClient(DestnationClient);

		double Amount = 0;
		Amount = _ReadAmount(SourceClient);
		
		char Answer = 'n';
		cout << "\nAre you sure you want to perform this Operation? y/n ?";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			if (SourceClient.Transfer(Amount,DestnationClient,CurrentUser.UserName)) {
				cout << "\nTransfer done Successfully!\n";
				


			}

			else {
				cout << "\nFailed Transfer\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestnationClient);
	}
};

