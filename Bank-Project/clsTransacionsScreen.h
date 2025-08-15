#pragma once
//#include "clsInputValidate.h";
#include "clsScreen.h";
#include <iomanip>
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h";
#include "clsShowTransferScreen.h"
#include "clsTransferLoginListScreen.h"
class clsTransacionsScreen:protected clsScreen
{
private:
	enum enTransactionsMenueOption {
		eDeposite=1,eWithdraw=2,eShowTotalBalances=3,eShowTransferScreen=4,eTransferLog=5,eShowMainMenue=6
	};

	static short _ReadTransactionsMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Chooce Number from 1 to 6 ?");

		return Choice;
	}

	void static _ShowDepositeScreen() {
		//cout << "\nDeposite Screen will be here...\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		//cout << "\nWithdraw Screen will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		//cout << "\nTotal Balance Screen will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen() {
		clsShowTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLoginListScreen() {
		clsTransferLoginListScreen::ShowTransferLoginScreen();
	}
	static void _GoBackToTransactionMenue() {
		cout << "\n\nPress any Key to go back to transaction menue....\n";
		system("pause>0");
		ShowTransactionMenue();
	}
	static void _PerformTransactionMenueOption(enTransactionsMenueOption TransactionsMenueOption) {

		switch (TransactionsMenueOption) {
		case enTransactionsMenueOption::eDeposite:
		{
			system("cls");
			_ShowDepositeScreen();
			_GoBackToTransactionMenue();
			break;

		}

		case enTransactionsMenueOption::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;

		}

		case enTransactionsMenueOption::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOption::eShowTransferScreen:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLoginListScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOption::eShowMainMenue:
		{
			//MainMenueWill Handle it 
		}
		}
	
	}
public:
	static void ShowTransactionMenue() {
		system("cls");
		if (!_CheckAccessRights(clsUser::enPermissions::pTranasactions)) {
			return;
		}
		_DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "==================================================\n";

		    cout << setw(37) << left << "" << "\t[1] Deposite.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";

			cout << setw(37) << left << "" << "\t[6] Main Menue.\n";

		cout << setw(37) << left << "" << "==================================================\n";

		_PerformTransactionMenueOption((enTransactionsMenueOption)_ReadTransactionsMenueOption());
	}
};

