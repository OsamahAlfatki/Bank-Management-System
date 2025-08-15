#pragma once
#include "clsScreen.h";
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen : protected clsScreen
{
    //enum enFindMenue{eFindByCode=1,eFindByCountry=2};

    static void _PrintCurrency(clsCurrency Currency) {
        cout << "Currency Card:";
        cout << "\n_______________________\n";
        cout << "\nCountry        : " << Currency.Country();
        cout << "\nCurrency Code  : " << Currency.CurrencyCode();
        cout << "\nName           : " << Currency.CurrencyName();
        cout << "\nRate ($) =     : " << Currency.GetRate();
        cout << "\n_______________________\n";

    }

    //static short _ReadFindMenuOption() {
    //   
    //    return Choice;
    //}

    //static void _FindByCurrencyCode() {
    //   
    //    if (Currency.IsEmpty()) {
    //        cout << "\n Currency is not found :-(\n";
    //    }
    //    else {
    //        cout << "\nCurrency found :-)\n";
    //        _PrintCurrency(Currency);
    //    }
    //}
    static void _ShowResults(clsCurrency Currency) {
        if (!Currency.IsEmpty()) {
            cout << "\n Currency is not found :-(\n";
            _PrintCurrency(Currency);

        }
        else {
            cout << "\nCurrency found :-)\n\n";
        }
    }
   /* static void _FindByCountry() {


        cout << "\nPlease enter Country ? ";
        string Country = clsInputValidate::ReadString();

        clsCurrency Currency = clsCurrency::FindByCountry(Country);
       
    }

    static void _PerformFindMenuOption(enFindMenue FindMenueOption) {
        switch (FindMenueOption) {
        case enFindMenue::eFindByCode:
            _FindByCurrencyCode();
            break;
        case enFindMenue::eFindByCountry:
            _FindByCountry();
            break;
        }
    }*/

public:




    static void _ShowFindScreen() {
        _DrawScreenHeader("\t Find Currency Screen");

        short Answer= 0;
        cout << "\nFind By :[1] Code Or [2] Country ? ";
        Answer= clsInputValidate::ReadShortNumberBetween(1, 2, "Enter between 1 and 2 ?");
        if (Answer == 1) {
            cout << "\nPlease enter currency code ? ";
            string CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else {
            cout << "\nPlease enter Country ? ";
            string Country = clsInputValidate::ReadString();

            clsCurrency Currency = clsCurrency::FindByCountry(Country);
        }

    }
};

