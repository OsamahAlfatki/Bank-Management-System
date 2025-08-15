#pragma once
#include <iostream>
#include "clsScreen.h";
//#include "clsInputValidate.h";
#include "clsUser.h"


class clsDeleteUserScreen :protected clsScreen
{
    static void _PrintUser(clsUser User) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;


        cout << "\n___________________\n";
    }

public:
	static void ShowDeleteUserScreen() {

        _DrawScreenHeader("\t Delete User Screen ");
        cout << "\nPlease enter Username : ";
        string AccountNumber = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(AccountNumber)) {
            cout << "User name is not found, Enter another one  : ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(AccountNumber);

        _PrintUser(User);

        char Answer = 'n';
        cout << "Are you sure you want to delete this User ? y/n?";
        cin >> Answer;

        if (tolower(Answer) == 'y') {
            if (User.Delete()) {
                cout << "\nUser Deleted Successfully\n";
                _PrintUser(User);

            }

            else {
                cout << "\nUser is Not deleted\n";
            }
        }
	}
};

