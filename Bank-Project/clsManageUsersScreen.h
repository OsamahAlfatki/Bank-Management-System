#pragma once
#include "clsScreen.h";
#include<iomanip>;
//#include "clsInputValidate.h";
#include "clsListUsersScreen.h"
#include "AddNewUsersScreen.h"
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h"
class clsManageUsersScreen:protected clsScreen
{
	enum enManageUsersMenueOption{eListUsers=1,eAddUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenue=6};

	static short _ReadManageUsersMenueOption() {
		short Choice = 0;
		cout << setw(37) << left << "";
		cout << "Choose What do you want to do ? [1 to 6]? ";
		Choice =clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 and 6 ?");
		return Choice;
	}


	static void _ShowListUsersScreen() {
		//cout << "\nList Users Screen will be here .\n";
		clsListUsersScreen::ShowAllUsersList();
	}

	static void _ShowAddNewUserScreen() {
		//cout << "\nAdd New User Screen will be here .\n";
		AddNewUsersScreen::ShowAddNewUsersScreen();
	}
	static void _ShowDeleteUserScreen() {
		//cout << "\nDelete Users Screen will be here .\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUserScreen() {
		//cout << "\nUpdate User Screen will be here .\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen() {
		//cout << "\nFind User Screen will be here .\n";
		clsFindUserScreen::ShowFindUserScreen();
	}
	
	static void _GoBackToManageUsersMenue() {
		cout << "\n\nPress any key to go back to manage users menue ...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(enManageUsersMenueOption ManageUsersOption) {
		switch (ManageUsersOption) {
		case enManageUsersMenueOption::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOption::eAddUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}	
		case enManageUsersMenueOption::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}	
		case enManageUsersMenueOption::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		
		case enManageUsersMenueOption::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}	
		case enManageUsersMenueOption::eMainMenue:
		{
			
		}


		}
	}
	
public:
	static void ShowManageUsersMenue() {
		system("cls");

		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		
		_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Upadate User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";

		cout << setw(37) << left << "" << "==================================================\n";
		_PerformManageUsersMenueOption((enManageUsersMenueOption)_ReadManageUsersMenueOption());
	}
};

