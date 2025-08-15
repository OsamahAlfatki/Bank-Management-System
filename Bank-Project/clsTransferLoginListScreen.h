#pragma once
#include "clsScreen.h";
#include "clsBankClient.h"
#include <iomanip>
class clsTransferLoginListScreen :protected clsScreen
{
    static void _PrintTransferLoginRecordLine(clsBankClient::stTransferLoginRecord TransferLogin) {
        cout << setw(8) << left << "" << "| " << setw(30) << left << TransferLogin.DateTime;
        cout << "| " << setw(10) << left << TransferLogin.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogin.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogin.Amount;
        cout << "| " << setw(10) << left << TransferLogin.SrcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogin.DestBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogin.UserName;

    }

public:
    static void ShowTransferLoginScreen() {

       
        vector<clsBankClient::stTransferLoginRecord>vTransferLoginData = clsBankClient::GetTransferLoginList();
        string Title = "\t  Transfer Log List Screen ";
        string SubTitle = "\t   (" + to_string(vTransferLoginData.size()) + ")" + " Records(s).\n";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "";
        cout << "| " << setw(30) << left << "Date/Time";
        cout << "| " << setw(10) << left << "S.Acct";
        cout << "| " << setw(10) << left << "d.Acct";
       
        cout << "| " << setw(10) << left << "Amount";
        cout << "| " << setw(10) << left << "S.Balance";
        cout << "| " << setw(10) << left << "d.Balance";
        cout << "| " << setw(10) << left << "User\n";

          cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        if (vTransferLoginData.empty()) {
            cout << "\n\t\t\tNo  Transfers Login availble in the system\n";
            // return;
        }

        else
            for (clsBankClient::stTransferLoginRecord& Transfer : vTransferLoginData) {
                _PrintTransferLoginRecordLine(Transfer);
                cout << endl;
            }
        cout << "\n";
        cout << setw(8) << left << "" << "_______________________________________________________________________________________________________\n";


    }

};

