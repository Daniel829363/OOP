
// arrover1. ���
// ������������ �������� ����������� �������, ������������
// ���� ������� ��� �������������
// ������������ ��������� ������� ��� ��������� � ��������� �������� 
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
	// ��� ������� exit
	// ������ �������
	// ��������� �������� �������� ������� 
	void putel(int n, int elvalue)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(1);
		} arr[n] = elvalue;
	}

	// ��������� �������� �������� �������
	int getel(int n) const {
		if (n < 0 || n >= LIMIT)
		{
			cout << "\now������� ������!"; exit(1);
		} return arr[n];
	}
};
int main()
{
	safearray sal;
	// ������ �������� ���������
	for (int j = 0; j < LIMIT; j++) sal.putel(j, j * 10);
	// ���������� ��������
	for (int j = 0; j < LIMIT; j++)
	{
		int temp =sal.getel(j);
		cout << "������� "<<j<<"�����" << temp << endl;
	}
	return 0;
}
