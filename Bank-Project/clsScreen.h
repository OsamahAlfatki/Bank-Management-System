#pragma once


#include <iostream>
//#include "clsUser.h";
#include "clsGlobal.h"
#include "clsDate.h";
//#include <string>
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        //clsDate Date;
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t" << "\t\tUser: " << CurrentUser.UserName << "\n";
        cout <<"\t\t\t" << "\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";
       


    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission) {
        if (!CurrentUser.CheckAccessPermissions(Permission)) {

            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << "Access Deniod ! Contact your Admin\n";
           
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        return true;
    }


};
