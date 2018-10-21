// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TMatrix<int> a(7), b(7), c(7), d(7);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "������������ �������� ��������� ������������� ����������� ������"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  1;
      b[i][j] = 6;
    }
  c = a + b;
  d = a - b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  cout << "Matrix d = a - b " << endl << a << endl;

  TVector<int> av(1,3), bv(3,1), res(4);

  av[3]=1;
  bv[1]=bv[2] = bv[3]= 1;

  res = av-bv;

  cout << "Vector av = " << endl << av << endl;
  cout << "Vector bv = " << endl << bv << endl;
  cout << "Vector res= av - bv" << endl << res << endl;



}
//---------------------------------------------------------------------------
