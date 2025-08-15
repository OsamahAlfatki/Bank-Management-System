#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";
class clsUpdateCurrencyScreen :protected clsScreen
{

private :
    static float _ReadRate() {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;
        return NewRate = clsInputValidate::ReadfloatNumber();
    }
    static void _PrintCurrency(clsCurrency Currency) {
        cout << "Currency Card:";
        cout << "\n_______________________\n";
        cout << "\nCountry        : " << Currency.Country();
        cout << "\nCurrency Code  : " << Currency.CurrencyCode();
        cout << "\nName           : " << Currency.CurrencyName();
        cout << "\nRate ($) =     : " << Currency.GetRate();
        cout << "\n_______________________\n";

    }
    //
    //static void _ShowResults(clsCurrency Currency) {
    //    if (!Currency.IsEmpty()) {
    //        //cout << "\n Currency is not found :-(\n";
    //        _PrintCurrency(Currency);

    //    }
    //    else {
    //        cout << "\nCurrency is not found :-)\n\n";
    //    }
    //}
    static string _ReadCurrencyCode() {
        cout << "\nPlease enter currency code ? ";
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            cout << "\nCurrency is not found ,choose another one ?";
            CurrencyCode = clsInputValidate::ReadString();

        }
        return CurrencyCode;
   }
public:
    static void ShowUpdateCurrencyRateScreen() {
        _DrawScreenHeader("\t Update Currency Screen");
      
        clsCurrency Currency = clsCurrency::FindByCode(_ReadCurrencyCode());
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\nAre you sure you want to update the rate of this Currency ? y/n ?";
        cin >> Answer;

        if (tolower(Answer) == 'y') {
           cout<< "\nUpdate Currency Rate :\n";
           cout << "_______________________\n";
          
           Currency.UpdateRate(_ReadRate());
           cout << "\nCurrency Rate Updated Successfully :-)\n\n";
           _PrintCurrency(Currency);
        }

        else {
            cout << "\nOperation cancelled \n";
        }
    }
};

