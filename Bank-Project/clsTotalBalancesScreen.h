#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";
#include "clsUtil.h";
#include <iomanip>

class clsTotalBalancesScreen:protected clsScreen
{

private:
	//
	 static void _PrintClientRecordBalanceLine(clsBankClient Client) {
		 cout << setw(25) << left << "";
	    cout << "| " << setw(15) << left << Client.AccountNumber();
	    cout << "| " << setw(40) << left << Client.FullName();
	    cout << "| " << setw(12) << left << Client.AccountBalance;
	
	}
public:

	static void ShowTotalBalances() {
	    vector<clsBankClient>vClientsData = clsBankClient::GetClientsList();
		string Title = "\t Balance List Screen ";
		string SubTitle = "\t (" + to_string(vClientsData.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);
	    //cout <<"\n"<< clsUtil::Tabs(3) << "Balance List (" << vClientsData.size() << ") Clients\n";
	    cout <<setw(25)<<left<<""<< "\n\t\t__________________________________________________________________________\n\n";
		cout << setw(25) << left << "";
	    cout << "| " << setw(15) << left << "Account Number ";
	    cout << "| " << setw(40) << left << "Client Name";
	    cout << "| " << setw(12) << left << "Balance";
		cout << setw(25) << left << "";
	    cout << "\t\t__________________________________________________________________________\n\n";
	
	
	
	    if (vClientsData.empty()) {
	        cout << clsUtil::Tabs(3) << "No Clients Avalailbe in the system \n";
	    }
	    else {
	        for (clsBankClient& Client : vClientsData) {
	             _PrintClientRecordBalanceLine(Client);
	            cout << endl;
	        }
	
	    }
		cout << setw(25) << left << "";
	    cout << "\n\t\t__________________________________________________________________________\n\n";
	
	    double TotalBalances = clsBankClient::GetTotalBalances();
		cout << setw(8) << left << "";
	    cout << "\t\t\t\t\t\t\tTotal Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "";

	    cout <<"\t\t\t\t ("<< clsUtil::NumberToText(TotalBalances)<<")" << endl;
	
	
	}

};

