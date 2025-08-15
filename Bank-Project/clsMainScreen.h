#pragma once
#include <iostream>
#include "clsScreen.h"
//#include "clsInputValidate.h"
#include <iomanip>
#include "clsListScreen.h"
#include"clsAddNewClientsScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransacionsScreen.h"
#include "clsManageUsersScreen.h"
#include"clsLoginRegisterListScreen.h";
#include "clsCurrencyExchangeScreen.h"
//#include "clsGlobal.h"// the  name  that i should was do is Global because it's varaible not class
//#include "clsLoginScreen.h"
//#include "clsUser.h";
//#include "clsDenioedScreen.h"; My way of sol the 27 lesson
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegisterList = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    //My Way of sol
 /*   static bool _IsAllowtoAccess(clsUser::enPermissions Permission) {
        if ( CurrentUser.Permissions ==-1) {
            return true;
        }

        if (CurrentUser.Permissions & Permission) {
            return true;
        }
        return false;
    }*/


    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
       /*  if (!_IsAllowtoAccess(clsUser::pListClient)) {
             system("cls");
             clsDenioedScreen::_ShowDenioedMessageScreen();
             return;
         }*/

        clsListScreen::ShowAllClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
       /*  if (!_IsAllowtoAccess(clsUser::pAddNewClient)) {
             system("cls");
             clsDenioedScreen::_ShowDenioedMessageScreen();
             return;
         }*/
        clsAddNewClientsScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        /*if (!_IsAllowtoAccess(clsUser::pDeleteClients)) {
            system("cls");
            clsDenioedScreen::_ShowDenioedMessageScreen();
            return;
        }*/
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        /*if (!_IsAllowtoAccess(clsUser::pUpdateClients)) {
            system("cls");
            clsDenioedScreen::_ShowDenioedMessageScreen();
            return;
        }*/
        // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        /* if (!_IsAllowtoAccess(clsUser::pFindClients)) {
             system("cls");
             clsDenioedScreen::_ShowDenioedMessageScreen();
             return;
         }*/
         //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        /*  if (!_IsAllowtoAccess(clsUser::pTranasactions)) {
              system("cls");
              clsDenioedScreen::_ShowDenioedMessageScreen();
              return;
          }*/
          // cout << "\nTransactions Menue Will be here...\n";
        clsTransacionsScreen::ShowTransactionMenue();
    }

    static void _ShowManageUsersMenue()
    {
        /*  if (!_IsAllowtoAccess(clsUser::pManageUsers)) {
              system("cls");
              clsDenioedScreen::_ShowDenioedMessageScreen();
              return;
          }*/
          //cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterListScreen() {
        clsLoginRegisterListScreen::ShowLoginRegisterScreen();
    }
    //static void _ShowEndScreen()
    //{
    //    cout << "\nEnd Screen Will be here...\n";



    //}

    static void _ShowCurrencyExchangeScreen() {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMainMenue();
    }

    static void _Logout() {
        CurrentUser = clsUser::Find("", "");
        // it will take me to main menue
       // clsLoginScreen::ShowLoginScreen();

    }
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {

        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eLoginRegisterList:
            system("cls");
            _ShowLoginRegisterListScreen();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();

            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            //Login();

            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Register login.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

