#pragma once

#include <iomanip>
#include <iostream>
//#include "clsUser.h";
#include "clsScreen.h";
//#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen
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

    static short _ReadPermissionstoSet() {
        char Answer = 'n';
        short Permissions = 0;
        cout << "\nDo you want to give full Access ?y/n?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            return -1;
        }

        cout << "\n Do you want to give access to :\n";

        cout << "\nShow Clients List ?y/n?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pListClient;
        }
        cout << "\nAdd New Client ? y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }
        cout << "\nDelete Client  ? y/n ?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pDeleteClients;
        }
        cout << "\nUpdate Client ? y/n ?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }
        cout << "\nFind Client ? y/n ? ";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pFindClients;
        }
        cout << "\nTransactions Menue  ?y/n ?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pTranasactions;
        }
        cout << "\nManage Users Menue? y/n ?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nShow Register login Screen? y/n ?";
        cin >> Answer;
        if (tolower(Answer) == 'y') {
            Permissions += clsUser::enPermissions::pShowRegisterLogin;
        }
        return Permissions;
    }

    static  void _ReadUserInfo(clsUser& User) {
        cout << "\nEnter FirstName : ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email : ";
        User.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone : ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nEnter Password : ";
        User.Password = clsInputValidate::ReadString();
        cout << "\nEnter Permissions : ";

        User.Permissions = _ReadPermissionstoSet();
    }


public:
    static void ShowUpdateUserScreen() {
        _DrawScreenHeader("\t Update User Screen");

        cout << "\nPlease enter User Username ?";
        string UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "User with [" << UserName << "] is not found enter another one ?";
            UserName = clsInputValidate::ReadString();

        }

        char Answer = 'n';
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre you sure you want to update this User?y/n? ";
        cin >> Answer;

        
        clsUser::enSaveResults SaveResult;


        if (tolower(Answer) == 'y') {
            cout << "\n\nUpdate User info :\n";
            cout << "______________________\n";
            _ReadUserInfo(User);


            SaveResult = User.Save();
        }
        switch (SaveResult) {
        case clsUser::svSuccessed:
            cout << "\n User Updated succuessfully!\n";
            _PrintUser(User);
            break;
        case clsUser::svFalidEmptyObject:
            cout << "\n Error User was not updated because it's Empty\n";
            break;
        }
    }
};

