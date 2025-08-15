#pragma once
#include <iostream>
#include <iomanip>
#include<string>
#include "clsBankClient.h";
#include "clsScreen.h"
using namespace std;
class clsListScreen:protected clsScreen
{
private:

   static void _PrintClientRecordLine(clsBankClient Client) {
        cout << setw(8) << left << ""<< "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.GetPhone();
        cout << "| " << setw(22) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(10) << left << Client.AccountBalance;


    }
public:
   static void ShowAllClientsList() {
        vector<clsBankClient>vClientsData = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen ";
        string SubTitle = "\t   (" + to_string(vClientsData.size()) + ")" + " Client(s).\n";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8)<<left<<""<<"\n\t_____________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << ""<< "| " << setw(15) << left << "Account Number ";
        cout << "| " << setw(20) << left << "Client Name";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(22) << left << "Email";
        cout << "| " << setw(10) << left << "Pin Code";
        cout << "| " << setw(10) << left << "Balance\n";
        cout << setw(8) << left << ""<< "\n\t_____________________________________________________________________________________________________\n\n";

        if (vClientsData.empty()) {
            cout << "\n\t\t\tNo Clients availble in the system\n";
            // return;
        }

        else
            for (clsBankClient& Client : vClientsData) {
                _PrintClientRecordLine(Client);
                cout << endl;
            }
        cout << setw(8) << left << ""<<"_______________________________________________________________________________________________________\n";


    }

};

