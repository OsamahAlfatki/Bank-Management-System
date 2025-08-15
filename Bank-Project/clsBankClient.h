#pragma once
#include<iostream>
#include "clsString.h";
#include"clsPerson.h"
#include <fstream>
#include "clsDate.h";
#include "clsGlobal.h"
class clsBankClient :public clsPerson
{
private:
	string _AccountNumber = "";
	string _PinCode = ""; 
	double _AccountBalance = 0;
	bool _MarkForDelete = false;

	enum enMode { EmptyMode = 0, UpadateMode = 1,AddNewMode };

	enMode _Mode;

	static clsBankClient _ConvertClientDataToObject(string Line,string Seperator="#//#") {
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpadateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
public:
	struct stTransferLoginRecord {
		string DateTime = "";
		string SourceAccountNumber = "";
		string DestinationAccountNumber = "";;
		float Amount = 0;
		float SrcBalanceAfter = 0;
		float DestBalanceAfter = 0;
		string UserName = "";
	};

private:

	static string _ConvertClientObjectToLine(clsBankClient ClientsData, string Seperator = "#//#") {
		string DataLine = "";
		DataLine = ClientsData.FirstName + Seperator;
		DataLine += ClientsData.LastName + Seperator;
		DataLine += ClientsData.Email + Seperator;
		DataLine += ClientsData.Phone + Seperator;
		DataLine += ClientsData.AccountNumber() + Seperator;
		DataLine += ClientsData.GetPinCode() + Seperator;
		DataLine += to_string(ClientsData.AccountBalance);
		return DataLine;

	}
	static stTransferLoginRecord _ConvertTransferLineToRecord(string Line, string Seperator = "#//#") {
		stTransferLoginRecord TransferRecord;
		vector<string> vTransferLoginDataLine = clsString::Split(Line, Seperator);

		TransferRecord.DateTime = vTransferLoginDataLine[0];
		TransferRecord.SourceAccountNumber= vTransferLoginDataLine[1];
		TransferRecord.DestinationAccountNumber = vTransferLoginDataLine[2];

		TransferRecord.Amount = stoi(vTransferLoginDataLine[3]);
		TransferRecord.SrcBalanceAfter = stoi(vTransferLoginDataLine[4]);
		TransferRecord.DestBalanceAfter = stoi(vTransferLoginDataLine[5]);
		TransferRecord.UserName = vTransferLoginDataLine[6];


		return TransferRecord;

	}

	
	string _ConvertClientTransferRecordToLine(clsBankClient& ClientsData, double Amount,string UserName,string Seperator = "#//#") {

		string TransferLoginRecord = "";
		clsDate Date;
		TransferLoginRecord += 
			Date.GetSystemDateandTimeNow() + Seperator;
		TransferLoginRecord += _AccountNumber + Seperator;
		TransferLoginRecord += ClientsData._AccountNumber + Seperator;
		TransferLoginRecord += to_string(Amount) + Seperator;
		TransferLoginRecord += to_string(_AccountBalance) + Seperator;
		TransferLoginRecord += to_string(ClientsData._AccountBalance) + Seperator;
		TransferLoginRecord += UserName;
		return TransferLoginRecord;


	}

	void _RegisterTransferLogin(float Amount, clsBankClient& DestinationClientData,string UserName) {
		_AddDataLineToFile(_ConvertClientTransferRecordToLine(DestinationClientData,
			Amount,UserName),"TransferLog.txt");
	}


	
	void _AddNew() {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	 

	static void _SaveClientsDataToFile(vector<clsBankClient>& vClientsData) {
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open()) {
			string LineData = " ";
			for (clsBankClient& Client : vClientsData) {
				//This only write Records that are only not mark for delete
				if (Client._MarkForDelete == false) {
					LineData = _ConvertClientObjectToLine(Client);
					MyFile << LineData << endl;
				}

			}
			MyFile.close();
		}
	}

	static vector<clsBankClient>_LoadClientsDataFromFile(string FileName = "Clients.txt") {

		fstream MyFile;

		vector<clsBankClient> vClientsData;
		MyFile.open("Clients.txt", ios::in);
	//	MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string LineData = "";
			while (getline(MyFile, LineData)) {
				clsBankClient Client = _ConvertClientDataToObject(LineData);
				vClientsData.push_back(Client);

			}

		}
		MyFile.close();

		return vClientsData;

	}
	static clsBankClient _GetEmptyObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _AddDataLineToFile(string DataLine,string FileName="Clients.txt") {
		fstream MyFile;

		MyFile.open(FileName, ios::out|ios::app);
		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	 void _Update() {

		vector<clsBankClient>_vClientsData = _LoadClientsDataFromFile();

		for (clsBankClient& Client : _vClientsData) {
			if (Client.AccountNumber() == AccountNumber()) {
				Client = *this;
				break;
			}


		}
		_SaveClientsDataToFile(_vClientsData);


	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	bool GetMarkForDelete() {
		return _MarkForDelete;
	}
	void SetMarkForDelete(bool MarkForDelete) {
		_MarkForDelete = MarkForDelete;
	}
	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete)) bool MarkForDelete;

	float GetAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	string AccountNumber() {
		return _AccountNumber;
	}

	//No relatiy Ui inside object
	//void Print() {
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FirstName;
	//	cout << "\nLastName    : " << LastName;
	//	cout << "\nFull Name   : " << FullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << _AccountNumber;
	//	cout << "\nPassword    : " << _PinCode;
	//	cout << "\nBalance     : " << _AccountBalance;


	//	cout << "\n___________________\n";
	//}
	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber) {
		vector<clsBankClient>vClientData;
		fstream MyFile;
		string Line = "";

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertClientDataToObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;

				}

				vClientData.push_back(Client);
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	bool Delete() {
		vector<clsBankClient>vClientsData = _LoadClientsDataFromFile();
		for (clsBankClient& Client : vClientsData) {
			if (Client.AccountNumber() == AccountNumber()) {
				Client.MarkForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClientsData);
		*this = _GetEmptyObject();
		return true;
	}
	static clsBankClient Find(string AccountNumber,string PinCode) {
		vector<clsBankClient>vClientData;
		fstream MyFile;
		string Line = "";

		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {

			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertClientDataToObject(Line);
				if (Client.AccountNumber() == AccountNumber&&PinCode==Client.PinCode)
				{
					MyFile.close();
					return Client;

				}

				vClientData.push_back(Client);
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	static  bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return !(Client.IsEmpty());
	}

	enum enSaveResults{svFalidEmptyObject=0,svSuccessed=1,svFaildAccountExist=2};

	enSaveResults Save() {

		switch (_Mode) {

		case enMode::EmptyMode:
			if (IsEmpty()) {
				return enSaveResults::svFalidEmptyObject;

			}
			break;

		case enMode::UpadateMode:
			_Update();
			return enSaveResults::svSuccessed;


		case enMode::AddNewMode:
			// This will add new record to file or data base 
			if (IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountExist;
			}
			else {
				_AddNew();
				//We need to set the mode after update to add new
				_Mode = enMode::UpadateMode;
				return enSaveResults::svSuccessed;
			}

		}
	}
	 
	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	static double GetTotalBalances() {
		vector<clsBankClient>vClientsData = GetClientsList();
		double TotatlBalance = 0;
		for (clsBankClient& Client : vClientsData) {
			TotatlBalance += Client.AccountBalance;
		}
		return TotatlBalance;
	}
	static vector<clsBankClient>GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	//My Last Sol Of Transfer
	//static bool IsAmountExceedsTheBalance(float Amount, string SenderAcc) {
	//	clsBankClient Client = clsBankClient::Find(SenderAcc);
	//	return (Client.IsEmpty() || Amount > Client.AccountBalance);
	//}

	//static bool _TransferBettweenAccounts(clsBankClient &SenderClient, clsBankClient &RecieverClient,float Amount) {
	///*	clsBankClient Client1 = clsBankClient::Find(SenderAcc);
	//	clsBankClient Clien2 = clsBankClient::Find(RecieverAcc);*/
	//	SenderClient.Withdraw(Amount);
	//	RecieverClient.Deposit(Amount);
	//	return true;
	//}

	//public:
	// static bool Transfer(float Amount, clsBankClient &SenderClient, clsBankClient &RecieverClient) {
	//	if (!IsClientExist(SenderClient.AccountNumber()) ||!IsClientExist(RecieverClient.AccountNumber())||
	//		IsAmountExceedsTheBalance(Amount, SenderClient.AccountNumber())) {
	//		return false;
	//	}
	//	else {
	//		
	//		return _TransferBettweenAccounts(SenderClient, RecieverClient, Amount);
	//	}


	
	//}

	 bool Transfer(float Amount ,clsBankClient& DestanionClient,string UserName) {
		/*	clsBankClient Client1 = clsBankClient::Find(SenderAcc);
			clsBankClient Clien2 = clsBankClient::Find(RecieverAcc);*/
		 if (Amount > AccountBalance) {
			 return false;
		 }

		Withdraw(Amount);
		DestanionClient.Deposit(Amount);
		_RegisterTransferLogin(Amount, DestanionClient,UserName);
		return true;
	}
	 static vector<stTransferLoginRecord>GetTransferLoginList(string FileName = "TransferLog.txt") {
		 fstream MyFile;

		 vector < stTransferLoginRecord>vTransferLoginData;
		 stTransferLoginRecord TransferData;
		 MyFile.open(FileName, ios::in);
		 string LineData = "";
		 if (MyFile.is_open()) {
			 while (getline(MyFile, LineData)) {
				 TransferData = _ConvertTransferLineToRecord(LineData);
				 vTransferLoginData.push_back(TransferData);
			 }
			 MyFile.close();
		 }
		 return vTransferLoginData;
	 }
};

