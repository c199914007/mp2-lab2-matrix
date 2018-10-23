// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include <time.h>
//---------------------------------------------------------------------------

void main()
{ int n , Key, f;
setlocale(LC_ALL, "Russian");
cout << "Тестирование программ поддержки представления треугольных матриц"
	<< endl;
L:
cout << "Введите размер матриц а и b";
cout << endl;
cin >> n;
if (n < MAX_MATRIX_SIZE)
{
	TMatrix<int > a(n);
	TMatrix<int > b(n);

	cout << "Введите 1 , если хотите набирать матрицы самостоятельно, 2, если хотите ввести произвольные числа: ";
	cout << endl;

	cin >> Key;
	switch (Key)
	{
	case 1:
		{ 
			cout << "   a:"<<endl;
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
					cin >> a[i][j];

			cout << "   b:" << endl;
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
					cin >> b[i][j];
			break;
		}
	case 2:
		{
			srand(time(NULL));
			for ( int i = 0; i < n; i++)
				for (int j = i; j< n; j++)
				{
					a[i][j] = (int) rand()%245;
					b[i][j] = (int) rand()%137;
				}
				break;
		}
	default :
		{  Key = 0;
		cout << "Что-то вы не так поняли в инструкции!";
		cout << endl;
		}
	}
	if (Key != 0)
	{
	cout << "a = " << endl;
	cout << a << endl;
	cout << "b = " << endl;
	cout << b << endl;

	cout << "Что прикажете сделать?";
	cout << endl;
	cout << "1: a + b";
	cout << endl;
	cout << "2: a - b";
	cout << endl;
	cout << "3 : b - a";
	cout << endl;
	cin >> Key;
	switch (Key)
	{
	case 1:
		{
			cout << " a + b = " << endl ;
			cout << a+b<< endl;
			break;
		}
	case 2:
		{
			cout << " a + b = " << endl ;
			cout << a-b<< endl;
			break;
		}
	case 3:
		{
			cout << " b - a = " << endl ;
			cout << b - a << endl;
			break;
		}
	default:
		{
			Key = 0;
			cout << "Следите за вводом!";
			cout << endl;
		}
	}
	}
	cout << "Нажмите 1, чтобы попробовать снова , или нажмите 2, чтобы уйти: " ;
	cin >> f;
	if (f == 1)
		goto L;
	else cout << "Пока пока!";
	cout << endl;
}
}
//---------------------------------------------------------------------------
