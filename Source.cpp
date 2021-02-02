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
		cout << "������� ���������� �����:\t";
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
		cout << "������� ���������� �����:\t";
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
		cout << "������� �������� ������:\t";
		cin >> name;
		cout << "������� ��������������� ����:\t";
		cin >> language;
		cout << "������� �������� ������:\t";
		cin >> currency;
		cout << "������� ���� ������ ������������ �������:\t";
		currency_rate = GetCurrency_Rate();

	}

	void Print()
	{
		cout << "============\n";

		cout << "������:\t" << name << endl;

		cout << "����:\t" << language << endl;

		cout << "������:\t" << currency << endl;

		cout << "���� � �������:\t" << currency_rate << endl;

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
	cout << "������� ��� ������� ���� �������:\t";
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
		cout << "������ �������� ���\n";
		RemoveElement(arr);
	}
	else
	{
		cout << "���� ������� " << counter << " �������(-��)\n";
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
	cout << "������� ���������� �����:\t";
	countries = GetCountries();
	vector <State> array(countries);

	FillArray(array);
	ShowArray(array);

	RemoveElement(array);
	ShowArray(array);

	cout << "������� ���������� �����, ������� �� ������ ��������:\t";
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