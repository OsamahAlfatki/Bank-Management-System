#pragma once
#include "clsScreen.h";
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyScreen.h";
#include "clsExchangeCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen :protected clsScreen
{

	static short _ReadCurrencyExchangeMainMenueOption() {
		short Choice = 0;
		cout << setw(37) << left << ""  ;
		cout << "Choose what do you want to do? [1 to 5} ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 and 5 ?");
		return Choice;
	}

	enum enCurrencyExhangeMainMenueOption{eListCurrencies=1,eFindCurrency=2,eUpdateCurrencyRate=3,eCurrencyExchange=4,eMainMenue=5};
	static void _ShowListCurrenciesScreen() {
		//cout << "\nList Currencies Screen will be here ....\n";

		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _GoBackToMainMenu() {
		cout << "\nPress any key to go back to Exchange Screen Main Menu...\n";
		system("pause>0");
		ShowCurrencyExchangeMainMenue();
	}
	static void _ShowFindCurrenciesScreen() {
		//cout << "\nFind Currencies Screen Will be here...\n";
		
		clsFindCurrencyScreen::_ShowFindScreen();
	}
	static void _ShowUpdateRatesScreen() {
		//cout << "\nUpdate Rates Screen will be here ...\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen() {
		//cout << "\nCurrency Calculator Screen will be here ...\n";
		clsExchangeCurrencyCalculatorScreen::ShowExchangeCurrencyScreen();
	}
	static void _PerformCurrencyExchangeMenueOption(enCurrencyExhangeMainMenueOption CurrencyExchangeMenueOption) {
		switch (CurrencyExchangeMenueOption) {
		case enCurrencyExhangeMainMenueOption::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToMainMenu();
			break;

		case enCurrencyExhangeMainMenueOption::eFindCurrency:
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToMainMenu();
			break;

		case enCurrencyExhangeMainMenueOption::eUpdateCurrencyRate:
			system("cls");
			_ShowUpdateRatesScreen();
			_GoBackToMainMenu();
			break;
		case enCurrencyExhangeMainMenueOption::eCurrencyExchange:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToMainMenu();
			break;
		case enCurrencyExhangeMainMenueOption::eMainMenue:
		{
			//break;
		}

		}
	
	}
public :

	static void ShowCurrencyExchangeMainMenue() {
		system("cls");
		_DrawScreenHeader(" Currency Exchange Main Screen");
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Main Menu\n";
		cout << setw(37) << left << "" << "==================================================\n";

		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";

		cout << setw(37) << left << "" << "==================================================\n";
		_PerformCurrencyExchangeMenueOption((enCurrencyExhangeMainMenueOption)_ReadCurrencyExchangeMainMenueOption());
	}
};

