#pragma once
#include "clsPerson.h";
#include<vector>
#include <fstream>
#include "clsString.h"
#include "clsDate.h";
#include "clsUtil.h";
class clsUser:public clsPerson
{

private:
	string _UserName = "";
	string _Password= "";
	short  _Permissions = 0;
	bool _MarkForDelete = false;

	enum enMode { EmptyMode = 0, UpadateMode = 1, AddNewMode=2 };

	enMode _Mode;
public:
	struct stLoginRegisterRecord
	{
		string DateTime = "";
		string UserName = "";
		string Password = "";
		short Permissions = 0;

	};
private:
	static stLoginRegisterRecord _ConvertRegisterRecordLineToRecord(string Line, string Seperator = "#//#") {
		stLoginRegisterRecord LoginRegestrRecord;
		vector<string> LoginRegisterDataLine = clsString::Split(Line, Seperator);

		LoginRegestrRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegestrRecord.UserName = LoginRegisterDataLine[1];
		LoginRegestrRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2],5);
		LoginRegestrRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegestrRecord;

	}

	 string _PrepareloginRecord( string Seperator = "#//#") {
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateAndTimeNow() + Seperator;
		LoginRecord += this->_UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(this->Password,5) + Seperator;
		LoginRecord += to_string(this->Permissions);
		return LoginRecord;


	}



	static clsUser _ConvertUserDataToObject(string Line, string Seperator = "#//#") {
		vector<string>vUsersData;
		//short EncryptionKey = 5;

		vUsersData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpadateMode, vUsersData[0], vUsersData[1], vUsersData[2],
			vUsersData[3], vUsersData[4], clsUtil::DecryptText(vUsersData[5], 5), stoi(vUsersData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser UserData, string Seperator = "#//#") {
		string DataLine = "";
		//short EncryptionKey = 5;
		DataLine = UserData.FirstName + Seperator;
		DataLine += UserData.LastName + Seperator;
		DataLine += UserData.Email + Seperator;
		DataLine += UserData.Phone + Seperator;
		DataLine += UserData.UserName+ Seperator;
		DataLine += clsUtil::EncryptText(UserData.GetPassword() ,5)+ Seperator;
		DataLine += to_string(UserData._Permissions);
		return DataLine;

	}
	void _AddNew() {
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}


	static void _SaveUsersDataToFile(vector<clsUser>& vUsersData) {
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open()) {
			string LineData = " ";
			for (clsUser& User : vUsersData) {
				//This only write Records that are only not mark for delete
				if (User._MarkForDelete == false) {
					LineData = _ConvertUserObjectToLine(User);
					MyFile << LineData << endl;
				}

			}
			MyFile.close();
		}
	}

	static vector<clsUser>_LoadUsersDataFromFile(string FileName = "Users.txt") {
		fstream MyFile;
		vector<clsUser> vUsersData;

		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string LineData = "";
			while (getline(MyFile, LineData)) {
				clsUser clsUser = _ConvertUserDataToObject(LineData);
				vUsersData.push_back(clsUser);
			}
			MyFile.close();
		}
		return vUsersData;
	}
	static clsUser _GetEmptyObject() {

		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _AddDataLineToFile(string DataLine) {
		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _Update() {

		vector<clsUser>_vUsers = _LoadUsersDataFromFile();

		for (clsUser& User : _vUsers) {
			if (User.UserName == UserName) {
				User = *this;
				break;
			}


		}
		_SaveUsersDataToFile(_vUsers);


	}

public:
	enum enPermissions {
		eAll=-1,pListClient=1,pAddNewClient=2,pDeleteClients=4,pUpdateClients=8,pFindClients=16,
		pTranasactions=32,pManageUsers=64,pShowRegisterLogin=128
	};
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password,
		short Permissions) :clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode;
		_UserName =UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(short Permissions) {
		_Permissions = Permissions;
	}

	short GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;


	bool GetMarkForDelete() {
		return _MarkForDelete;
	}
	

	string GetUserName() {
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetUserName(string UserName) {
		_UserName=UserName;
	}

	
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static clsUser Find(string UserName) {
	
		fstream MyFile;
		string Line = "";

		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {

			while (getline(MyFile, Line)) {
				clsUser User = _ConvertUserDataToObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;

				}

				
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	bool Delete() {
		vector<clsUser>vUsersData = _LoadUsersDataFromFile();
		for (clsUser& User : vUsersData) {
			if (User.UserName == UserName) {
				User._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsersData);
		*this = _GetEmptyObject();
		return true;
	}
	static clsUser Find(string UserName, string Password) {

		fstream MyFile;
		string Line = "";

		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {

			while (getline(MyFile, Line)) {
				clsUser User = _ConvertUserDataToObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;

				}

			
			}
		}
		MyFile.close();
		return _GetEmptyObject();
	}

	static  bool IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return !(User.IsEmpty());
	}

	enum enSaveResults { svFalidEmptyObject = 0, svSuccessed = 1, svFaildUserExist = 2 };

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
			// This will add new record to file or database 
			if (IsUserExist(_UserName)) {
				return enSaveResults::svFaildUserExist;
			}
			else {
				_AddNew();
				//We need to set the mode after update to add new
				_Mode = enMode::UpadateMode;
				return enSaveResults::svSuccessed;
			}

		}
	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser>GetUsersList() {
		return _LoadUsersDataFromFile();
	}
	 bool CheckAccessPermissions(enPermissions Permission) {
		return (this->Permissions == -1) || ((this->Permissions & Permission) == Permission);
	}


	 void RegisterLogin() {
		 fstream MyFile;

		 MyFile.open("loginRegister.txt", ios::out|ios::app);
		 if (MyFile.is_open()) {
			 string LineData = " ";
			 LineData = _PrepareloginRecord();
			 MyFile << LineData << endl;
				
			 MyFile.close();
			
		 }
	 }


	 static vector<stLoginRegisterRecord>GetRegisterLoginList(string FileName="LoginRegister.txt") {
		 fstream MyFile;
		 vector<stLoginRegisterRecord> vLoginRegisterRecord;

		 MyFile.open(FileName, ios::in);
		 if (MyFile.is_open()) {
			 string LineData = "";
			 while (getline(MyFile, LineData)) {
				 stLoginRegisterRecord Register = _ConvertRegisterRecordLineToRecord(LineData);
				 vLoginRegisterRecord.push_back(Register);
			 }
			 MyFile.close();
		 }
		 return vLoginRegisterRecord;

	 }
};

