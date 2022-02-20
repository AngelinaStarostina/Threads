#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

void workerThread(LPVOID* arr)
{
	
}


 DWORD WINAPI mainThread(LPVOID* length)
{
	int *arr = new int[(int)length];
	arr[0] = (int)length;

	srand(time(0));

	arr[1] = rand() % 50; //2?

	cout << "Элементы массива";
	for (int i = 2; i < (int)length; i++)			//1
	{
		arr[i] = rand();
		cout << arr[i] << endl;
	}


	HANDLE worker;
	DWORD IDThreadWorker;
	worker = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)workerThread, (void*)arr, 0, &IDThreadWorker);		//3 //передать несколько параметров???
	if (worker == 0)
		return GetLastError();

	WaitForSingleObject(worker, INFINITE); //6

	CloseHandle(worker); //7
}

int main()
{
	setlocale(LC_ALL, "rus");

	int length;
	cout << "Введите размерность массива";
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