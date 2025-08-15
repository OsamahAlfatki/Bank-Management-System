#pragma once
#include "clsString.h";
#include <iostream>
#include <string>
#include <fstream>
class clsCurrency
{
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyName;
	string _CurrencyCode;
	float _Rate;

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator="#//#") {

		string CurrencyLineData = "";
		CurrencyLineData += Currency._Country + Seperator;
		CurrencyLineData += Currency._CurrencyCode + Seperator;
		CurrencyLineData += Currency._CurrencyName+ Seperator;
		CurrencyLineData += to_string(Currency._Rate);
		return CurrencyLineData;

	}


	static clsCurrency _ConvertCurrencyLineToObject(string Line, string Seperator = "#//#") {
		vector<string>_vCurrenciesData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, _vCurrenciesData[0], _vCurrenciesData[1], _vCurrenciesData[2], stof(_vCurrenciesData[3]));
	}

	static vector<clsCurrency>_LoadCurrenciesDataFromFile(string FileName="Currencies.txt") {
		fstream MyFile;
		vector<clsCurrency>_vCurrenciesData;
		MyFile.open(FileName, ios::in);
		if(MyFile.is_open())
		{
			string LineData;
			while (getline(MyFile, LineData)) {
				clsCurrency Currency = _ConvertCurrencyLineToObject(LineData);
				_vCurrenciesData.push_back(Currency);
			}
			MyFile.close();
		}
		return _vCurrenciesData;
	}

	static void _SaveCurrenciesDatatoFile(vector<clsCurrency>_vCurrenciesData) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open())
		{
			string LineData;

			for (clsCurrency& Currency : _vCurrenciesData) {
				LineData = _ConvertCurrencyObjectToLine(Currency);
				MyFile << LineData << endl;

			}
			MyFile.close();

		}

	}


	 void _Update() {

		vector<clsCurrency>_vCurrenciesData;
		_vCurrenciesData = _LoadCurrenciesDataFromFile();

		for (clsCurrency& Currency : _vCurrenciesData) {
			if (Currency._Country == _Country) {
				Currency = *this;
				break;
			}
		}

		_SaveCurrenciesDatatoFile(_vCurrenciesData);

	}

	 static clsCurrency _GetEmptyCurrencyObject() {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	 }

public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	void UpdateRate(float UpdateRate) {
		_Rate = UpdateRate;
		_Update();
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}
	float GetRate() {
		return _Rate;
	}

	string Country() {
		return _Country;
	}
	string CurrencyName() {
		return _CurrencyName;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	static vector<clsCurrency>GetAllUSDRates() {
		return _LoadCurrenciesDataFromFile();
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		 CurrencyCode=clsString::UpperAllString(CurrencyCode);
		 fstream MyFile;
		 MyFile.open("Currencies.txt", ios::in);
		 if (MyFile.is_open())
		 {
			 string LineData;
			 while (getline(MyFile, LineData)) {
				 clsCurrency Currency = _ConvertCurrencyLineToObject(LineData);
				 if (Currency.CurrencyCode() == CurrencyCode) {
					 MyFile.close();
					 return Currency;
				 }
			 }
		 }
		 MyFile.close();

		 return _GetEmptyCurrencyObject();
		 
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string LineData;
			while (getline(MyFile, LineData)) {
				clsCurrency Currency = _ConvertCurrencyLineToObject(LineData);
				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}
			}
		}
		MyFile.close();

		return _GetEmptyCurrencyObject();
	}

	float ConvertToUSD(float Amount) {
		return float(Amount / _Rate);
	}

	float ConvertToAnotherCurrency(float Amount,clsCurrency Currency2) {
		if (_CurrencyCode == Currency2.CurrencyCode()) {
			return Amount;
		}
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD") {
			return AmountInUSD;
		}
		if (_CurrencyCode == "USD") {
			return Amount * Currency2._Rate;
		}

		 return float(Currency2.GetRate()*AmountInUSD);
	}
};

