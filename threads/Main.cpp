#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;


void mainThread(LPVOID* length)
{
	int *arr = new int[(int)length];
	arr[0] = (int)length;

	srand(time(0));

	arr[1] = rand() % 50; //2?

	cout << "Ёлементы массива";
	for (int i = 2; i < (int)length; i++)			//1
	{
		arr[i] = rand();
		cout << arr[i] << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	int length;
	cout << "¬ведите размерность массива";
	cin >> length;

	HANDLE main;
	DWORD	IDThread;

	main = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)mainThread, (void*)length, 0, &IDThread);
	if (main == NULL)
		return GetLastError();

	WaitForSingleObject(main, INFINITE);

	CloseHandle(main);

	return 1;
	system("pause");
}