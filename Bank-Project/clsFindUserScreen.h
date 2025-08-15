#pragma once
#include <iostream>
//#include "clsUser.h";
#include "clsScreen.h";
//#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
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

public :
    static void ShowFindUserScreen() {
		_DrawScreenHeader("\t Find User Screen ");

		cout << "\nPlease enter Username : ";
		string Username = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(Username)) {
			cout << "\nUsername is not found ,Choose another  one : ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(Username);


		if (!User1.IsEmpty()) {
			cout << "\nUser Found :-)\n";

		}
		else {
			cout << "\nUser was not found\n :(- ";
		}
		_PrintUser(User1);
    }
};

