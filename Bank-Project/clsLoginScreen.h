#pragma once
//#include "clsGlobal.h";
#include "clsScreen.h";
#include "clsMainScreen.h";
using namespace std;

class clsLoginScreen :protected clsScreen
{
	static bool _Login() {
		bool loginfaild = false;
		string Username="", Password = "";
		short LoginFailedCount = 3;

		do {

			
			if (LoginFailedCount == 0) {
				//TrialstoLogin = 3;
				cout << "\n\nYou are locked after 3 faild Trials\n";
				return false ;
			}

			if (loginfaild) {
				cout << "\nInvalid Username/password !\n";
				cout << "\nYou have " << LoginFailedCount << " Trials to login !";
				

				
			}

			cout << "\n\n\nEnter User Name ?";
			cin >> Username;
			
			cout << "\nEnter Password ?";
			cin >> Password;

			LoginFailedCount--;

			CurrentUser = clsUser::Find(Username, Password);
			loginfaild = CurrentUser.IsEmpty();
		} while (loginfaild);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;

	}

public :

	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
		
	}

};

