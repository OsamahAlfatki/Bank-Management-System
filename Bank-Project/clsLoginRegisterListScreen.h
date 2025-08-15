#pragma once
#include "clsScreen.h";
#include<iomanip>
class clsLoginRegisterListScreen:protected clsScreen
{
	
    static void _PrintLoginRgisterRecordLine(clsUser::stLoginRegisterRecord Register) {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Register.DateTime;
        cout << "| " << setw(20) << left << Register.UserName;
        cout << "| " << setw(20) << left << Register.Password;
        cout << "| " << setw(15) << left << Register.Permissions;


    }
public:
    static void ShowLoginRegisterScreen() {

        if (!_CheckAccessRights(clsUser::enPermissions::pShowRegisterLogin)) {
            return;
        }
        vector<clsUser::stLoginRegisterRecord>vRegisterLoginData = clsUser::GetRegisterLoginList();
        string Title = "\t  Login Register List Screen ";
        string SubTitle = "\t   (" + to_string(vRegisterLoginData.size()) + ")" + " Records(s).\n";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";
        cout << setw(8) << left << "";
         cout << "| " << setw(30) << left << "Date/Time";
        cout << "| " << setw(20) << left << "UserName";
        cout << "| " << setw(20) << left << "Password";
        cout << "| " << setw(115) << left << "Permissions\n";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        if (vRegisterLoginData.empty()) {
            cout << "\n\t\t\tNo  Logins availble in the system\n";
            // return;
        }

        else
            for (clsUser::stLoginRegisterRecord &Register : vRegisterLoginData) {
                _PrintLoginRgisterRecordLine(Register);
                cout << endl;
            }
        cout << "\n";
        cout << setw(8) << left << "" << "_______________________________________________________________________________________________________\n";


    }
};

