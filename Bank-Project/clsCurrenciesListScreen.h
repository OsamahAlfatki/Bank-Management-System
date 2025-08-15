#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrenciesListScreen :protected clsScreen 
{
	static void _PrintCurrencyRecordLine(clsCurrency  Currency) {
		cout << setw(8) << left << "";
		
		cout << "| "<<setw(35) << left << Currency.Country();
		cout << "| "<<setw(8) << left << Currency.CurrencyCode();
		cout << "| "<<setw(40) << left << Currency.CurrencyName();
		cout << "| "<<setw(10) << left << Currency.GetRate();
	}

public:
	static void ShowCurrenciesListScreen() {
		vector<clsCurrency>vCurrenciesData = clsCurrency::GetAllUSDRates();
		string Title = "\t Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrenciesData.size()) + ") Currency.";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "";
		cout << "___________________________________________________________________________________________________\n\n";
		cout << setw(8) << left << "";
		  cout<<"| " <<setw(35)<<left<< "Country";
		cout << "| "<< setw(8) << left << "Code";
		cout << "| " <<setw(40) << left<< "Name";
		cout << "| " <<setw(10) << left<< "Rate(1$)\n";
		cout << setw(8) << left << "";

		cout << "____________________________________________________________________________________________________\n\n";

		if (vCurrenciesData.empty()) {
			cout << "\n\n No Currencies Data Available in the system \n ";
		}
		else {
			for (clsCurrency& Currency : vCurrenciesData) {
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "";

		cout << "___________________________________________________________________________________________________\n\n";

	}

};

