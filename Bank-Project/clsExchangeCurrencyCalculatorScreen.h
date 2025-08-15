#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";
class clsExchangeCurrencyCalculatorScreen :protected clsScreen
{
    static void _PrintCurrencyCard(clsCurrency Currency,string Title) {
        cout << "\n" << Title << endl;
        cout << "\n_______________________\n";
        cout << "\nCountry        : " << Currency.Country();
        cout << "\nCurrency Code  : " << Currency.CurrencyCode();
        cout << "\nName           : " << Currency.CurrencyName();
        cout << "\nRate ($) =     : " << Currency.GetRate();
        cout << "\n_______________________\n\n";

    }
    static float _ReadAmount() {
        cout << "\nEnter Amount to exchange: ";
        float Amount = clsInputValidate::ReadfloatNumber();
        return Amount;
    }
    static clsCurrency _GetCurrency(string Message) {
        cout << Message;
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            cout << "\nCurrency is not found ,choose another one ?";
            CurrencyCode = clsInputValidate::ReadString();

        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        return Currency;
    }

   // static string GetAmountAfterExchange(clsCu)

private :

    static void _PrintCurrencyExchangeResult(float Amount,clsCurrency Currency1,clsCurrency Currency2) {

      
        _PrintCurrencyCard(Currency1,"Convert From:\n");


        float AmountInUSD = Currency1.ConvertToUSD(Amount);
        if (Currency1.CurrencyCode() == "USD") {
            cout << Amount << " " << Currency1.CurrencyCode() << " = " <<
                " " << Currency1.ConvertToAnotherCurrency(Amount,Currency2)
                << " " << Currency2.CurrencyCode() << "\n\n";
            return;
        }

        
        cout << Amount << " " << Currency1.CurrencyCode() << " = " << " " <<
            AmountInUSD
        << " " << "USD" << "\n\n";

        if (Currency2.CurrencyCode() == "USD") {
            return;
        }
                cout << Amount << " " << Currency1.CurrencyCode() << " = " << " " <<
                    AmountInUSD
                    << " " << "USD" << "\n\n";


                cout << "\n\nConverting from USD to:\n";
               
                _PrintCurrencyCard(Currency2,"To:");

                cout << Amount << " " << Currency1.CurrencyCode() << " = " << " " << 
                    Currency2.ConvertToAnotherCurrency(AmountInUSD,Currency1)
                    << " " << Currency2.CurrencyCode() << "\n\n";
       

    }
public:

    static void ShowExchangeCurrencyScreen() {
        char Answer = 'n';
        do {
            system("cls");
            _DrawScreenHeader("\tExchange Currency Screen");
            
            clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter currency 1 code ? ");
            clsCurrency Currencyto = _GetCurrency("\nPlease enter currency 2 code ? ");
            float Amount = _ReadAmount();
            _PrintCurrencyExchangeResult(Amount, CurrencyFrom, Currencyto);
            cout << "\nDo you want to perform another Calculation ? y/n ?";
            cin >> Answer;
        } while (tolower(Answer)=='y');
    }
};

