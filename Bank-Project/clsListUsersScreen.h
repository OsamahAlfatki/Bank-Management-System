#pragma once
#include "clsUser.h";
#include <iomanip>
#include"clsScreen.h";

class clsListUsersScreen :protected clsScreen
{
    static void _PrintUserRecordLine(clsUser User) {
        cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.GetPhone();
        cout << "| " << setw(22) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;


    }
public:
    static void ShowAllUsersList() {
        vector<clsUser>vUsersData = clsUser::GetUsersList();
        string Title = "\t  Users List Screen ";
        string SubTitle = "\t   (" + to_string(vUsersData.size()) + ")" + " User(s).\n";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(15) << left << "UserName ";
        cout << "| " << setw(20) << left << "Full Name";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(22) << left << "Email";
        cout << "| " << setw(10) << left << "Password";
        cout << "| " << setw(10) << left << "Permissions\n";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        if (vUsersData.empty()) {
            cout << "\n\t\t\tNo Users availble in the system\n";
            // return;
        }

        else
            for (clsUser& User : vUsersData) {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        cout << setw(8) << left << "" << "_______________________________________________________________________________________________________\n";


    }
};

