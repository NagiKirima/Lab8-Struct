#include <iostream>
#include <string>
#include <vector>
using namespace std;
int GetCountries()
{
	int count;
	while (!(cin >> count) || (cin.peek() != '\n') || count < 1)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число:\t";
	}
	return count;
}
float GetCurrency_Rate()
{
	float rate;
	while (!(cin >> rate) || (cin.peek() != '\n') || rate < 0)
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "¬ведите корректное число:\t";
	}
	return rate;
}
struct State
{
	string name;
	string language, currency;
	float currency_rate;

	void Fill()
	{
		cout << "¬ведите название страны:\t";
		cin >> name;
		cout << "¬ведите государственный €зык:\t";
		cin >> language;
		cout << "¬ведите название валюты:\t";
		cin >> currency;
		cout << "¬ведите курс валюты относительно доллара:\t";
		currency_rate = GetCurrency_Rate();

	}

	void Print()
	{
		cout << "============\n";

		cout << "—трана:\t" << name << endl;

		cout << "язык:\t" << language << endl;

		cout << "¬алюта:\t" << currency << endl;

		cout << " урс к доллару:\t" << currency_rate << endl;

	}
};

void FillArray(vector <State> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].Fill();
	}
}

void ShowArray(vector <State> &arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr[i].Print();
	}
}
void RemoveElement(vector <State> &arr)
{
	bool check = false;
	int counter = 0;
	string value;
	int size = arr.size();
	cout << "¬ведите им€ которое надо удалить:\t";
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].name == value)
		{
			arr.erase(arr.begin() + i);
			counter++;
			check = true;
			size = arr.size();
		}
	}
	if (check == false)
	{
		cout << "“акого элемента нет\n";
		RemoveElement(arr);
	}
	else
	{
		cout << "Ѕыло удалено " << counter << " элемент(-ов)\n";
	}
}
void AddElement(vector <State> &arr)
{
	State NewCountry;
	NewCountry.Fill();
	arr.push_back(NewCountry);
}
int main()
{
	setlocale(LC_ALL, "ru");
	int countries;
	cout << "¬ведите количество стран:\t";
	countries = GetCountries();
	vector <State> array(countries);

	FillArray(array);
	ShowArray(array);

	RemoveElement(array);
	ShowArray(array);

	cout << "¬ведите количество стран, которое вы хотите добавить:\t";
	int numbers;
	cin >> numbers;
	for (int i = 0; i < numbers; i++)
	{
		cout << "=================================\n";
		AddElement(array);
		cout << "=================================\n";
	}
	ShowArray(array);

}