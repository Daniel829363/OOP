
// arrover1. срр
// демонстраци€ создани€ безопасного массива, провер€ющего
// свои индексы при использовании
// используютс€ отдельные функции дл€ установки и получени€ значени€ 
#include <process.h>
#include <iostream>
using namespace std; 
const int LIMIT = 100;
///////////////
class safearray
{
private:
	int arr[LIMIT];
public:
	// дл€ функции exit
	// размер массива
	// установка значени€ элемента массива 
	void putel(int n, int elvalue)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nошибочный индекс!"; exit(1);
		} arr[n] = elvalue;
	}

	// получение значени€ элемента массива
	int getel(int n) const {
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nowибочный индекс!"; exit(1);
		} return arr[n];
	}
};
int main()
{
	safearray sal;
	// задаем значени€ элементов
	for (int j = 0; j < LIMIT; j++) sal.putel(j, j * 10);
	// показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp =sal.getel(j);
		cout << "злемент "<<j<<"равен" << temp << endl;
	}
	return 0;
}
