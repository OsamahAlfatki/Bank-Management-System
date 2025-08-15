#pragma once
#include "clsScreen.h";
class clsDenioedScreen:protected clsScreen
{

public:
	static void _ShowDenioedMessageScreen() {
		_DrawScreenHeader("\t Deniod Message Screen");

		cout << "\n\nyou do'nt have authorities to access here contact  admen to give access if you want....\n  ";
	}
};

