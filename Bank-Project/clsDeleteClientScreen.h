#pragma once

#include "clsScreen.h";
#include "clsBankClient.h";
//#include "clsInputValidate.h";


class clsDeleteClientScreen:protected clsScreen
{
private:
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
	static void ShowDeleteClientScreen() {

        if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClients)) {
            return;
        }
        _DrawScreenHeader("\t Delete Client Screen ");
    cout << "\nPlease enter AccountNumber : ";
    string AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "Account Number is not Exist, choose another one  : ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);

    _PrintClient(Client);

    char Answer = 'n';
    cout << "Are you sure you want to ddelete this client ? y/n?";
    cin >> Answer;

    if (tolower(Answer) == 'y') {
        if (Client.Delete()) {
            cout << "\nClient Deleted Successfully\n";
            _PrintClient(Client);

        }

        else {
            cout << "\nClient is Not deleted\n";
        }
    }




}

};

