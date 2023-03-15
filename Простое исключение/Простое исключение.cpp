#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

class bad_length : public exception {
public:
	virtual const char* what() const throw() {
		return "Вы ввели слово запретной длины! До свидания";
	}
};

int function(string str, int forbidden_length)
{
	int len = str.length();
	if (len == forbidden_length) {
		throw bad_length();
	}
	return len;
}


int main()	
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int amount;
	string word;
	bool flag = true;
	cout << "Введите запретную длину: ";
	cin >> amount;
	while (flag == true)
	{
		cout << "Введите слово: ";
		cin >> word;
		try 
		{
			int lenght = function(word, amount);
			cout << "Длина слова \"" << word << "\"" << " равна " << lenght << endl;
		}
		catch (const bad_length& ex)
		{
			cout << ex.what() << endl;
			flag = false;
		}
	}
}
