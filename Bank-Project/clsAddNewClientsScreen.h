#pragma once
#include<iostream>
#include"clsBankClient.h";
#include "clsScreen.h";
#include<iomanip>
//#include"clsInputValidate.h";
//#include "clsGlobal.h";
using namespace std;

class clsAddNewClientsScreen:protected clsScreen
{
private :
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

   static void ShowAddNewClientScreen() {

       if (!_CheckAccessRights(clsUser::enPermissions::pListClient)) {
           return;
       }
       _DrawScreenHeader("\t Add Clients Screen");
        cout << "\nPlease enter AccountNumber : ";
        string AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account Number is Alread used, choose another one  : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);
        _PrintClient(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();

        switch (SaveResult) {
        case clsBankClient::svSuccessed:
            cout << "\nClient Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::svFalidEmptyObject:
            cout << "\nError account  was not saved becuase it's  empty";
            break;
        case clsBankClient::enSaveResults::svFaildAccountExist:

            cout << "\nClient was not added becuase it was Faild AccountExist";

        }
    }

};

