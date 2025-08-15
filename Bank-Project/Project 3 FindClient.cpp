
#include <iostream>
#include"clsBankClient.h";
#include "clsInputValidate.h"
#include<iomanip>
#include "clsUtil.h"
//#include "clsMainScreen.h";
#include "clsLoginScreen.h";
//#include "clsCurrency.h";
using namespace std;


int main()
{
    /* clsBankClient Client = clsBankClient::Find("A101");
     Client.Print();
     clsBankClient Client2 = clsBankClient::Find("A10111");
     Client2.Print();*/
     //UpdateClient();
    // AddNewClient();

    // DeleteClient();
    // ShowClientsList();
    // ShowTotalBalances();

    // clsMainScreen::ShowMainMenue();
  //  bool IsNotThreeTrials = true;
    while (true) {

        if (!clsLoginScreen::ShowLoginScreen()) {
            break;
        }
        
    }

    
    system("pause>0");
    return 0;
}

