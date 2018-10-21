// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TMATRIX_H__
#define __TMATRIX_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Шаблон вектора
template <class ValType>
class TVector
{
protected:
	ValType *pVector;
	int Size;       // размер вектора без нулей
	int StartIndex; // индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v);                // конструктор копирования
	~TVector();
	int GetSize()      { return Size;       } // размер вектора
	int GetStartIndex(){ return StartIndex; } // индекс первого элемента
	ValType& operator[](int pos);             // доступ
	bool operator==(const TVector &v) const;  // сравнение
	bool operator!=(const TVector &v) const;  // сравнение
	TVector& operator=(const TVector &v);     // присваивание

	// скалярные операции
	TVector  operator+(const ValType &val);   // прибавить скаляр
	TVector  operator-(const ValType &val);   // вычесть скаляр
	TVector  operator*(const ValType &val);   // умножить на скаляр

	// векторные операции
	TVector  operator+(const TVector &v);     // сложение
	TVector  operator-(const TVector &v);     // вычитание
	ValType  operator*(const TVector &v);     // скалярное произведение

	// ввод-вывод
	friend istream& operator>>(istream &in, TVector &v)
	{
		for ( int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, const TVector &v)
	{
		for (int i = 0; i < v.StartIndex; i++)
			out << 0 << ' ';
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
 {

	if ( (s >= 0) && ( s < MAX_VECTOR_SIZE) && (si >= 0))
	{	
		Size = s;
		StartIndex  = si;
		pVector = new ValType[s];
		for (int i = 0; i < Size; i++ )
			pVector[i] = 0;
	}
	else 
	{
		throw("Error len");
	}

} 
template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType> &v)
{ 
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	//for (int i = 0; i < StartIndex; i++)
	//	pVector[i] = 0;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];

} 


template <class ValType>
TVector<ValType>::~TVector()
{
	delete []pVector;
}


template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
	if ( (pos >= StartIndex) && ( pos - StartIndex < Size ))
	{
		return pVector[pos - StartIndex];
	}
	/*else if ( (pos>=0) && ( pos < StartIndex))
	{ 
		return 0;
	}*/
	else
	{
		throw ("Incorrect Index");
	}
} 
template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector &v) const
{
	if ( (StartIndex+Size) !=  (v.StartIndex+v.Size) )
		return false;
	else if ( Size != v.Size )
		return false;
	else 
	{
		for (int i = 0 ; i < Size; i++)
			if ( pVector[i] != v.pVector[i])
				return false;
	}
	return true;

} 

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector &v) const
{
	if ( (Size+StartIndex) !=  (v.Size + v.StartIndex) )
		return true;
	else if ( Size != v.Size )
		return true;
	else 
	{
		for (int i = 0 ; i < Size; i++)
			if ( pVector[i] != v.pVector[i])
				return true;
	}
	return false;
}

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector &v)
{
	if ( this != &v)
	{
		delete []pVector;
		Size = v.Size;
		StartIndex = v.StartIndex;
		pVector = new ValType [Size];
		for ( int i = 0; i < Size; i++)
			pVector[i] = v.pVector[i];

	}
	return *this;
} 


template <class ValType> // прибавить скаляр
TVector<ValType> TVector<ValType>::operator+(const ValType &val)
{
	TVector a (Size+StartIndex);
	for (int i = 0; i < a.StartIndex; i++)
		a.pVector[i]+=val;
	for (int i = a.StartIndex; i < a.Size ; i++)
		a.pVector[i] = val + pVector[i];
	return a;
} 


template <class ValType> // вычесть скаляр
TVector<ValType> TVector<ValType>::operator-(const ValType &val)
{
	TVector a (Size+StartIndex);
	for (int i = 0; i < a.StartIndex; i++)
		a.pVector[i]+=val;
	for (int i = a.StartIndex; i < a.Size ; i++)
		a.pVector[i] = val + pVector[i];
	return a;
}
template <class ValType> // умножить на скаляр
TVector<ValType> TVector<ValType>::operator*(const ValType &val)
{
	TVector a (*this);
	for (int i = 0; i < a.Size; i++)
		a.pVector[i]*=val;
	return a;
} 
template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType> &v)
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("add with not equal size");
	}

	int Si ;
	if (StartIndex < v.StartIndex)
	{   
		Si = v.Size;
		TVector <ValType> a(*this);
		TVector <ValType> b(v);
		int k = 1;
		for(int i = Si-1; i >=0; i--)
		{
			a.pVector[a.Size - k] = a.pVector[a.Size - k] + b.pVector[i];
			k++;
		}
		return a;
	}
	else 
	{
		Si = Size;
		TVector <ValType> a(v);
		TVector <ValType> b(*this);
		int k = 1;
		for(int i = Si-1; i >=0; i--)
		{
			a.pVector[a.Size - k] = a.pVector[a.Size - k] +  b.pVector[i];
			k++;
		}
		return a;
	}

} 
template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType> &v)
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("Subtract with not equal size");
	}

	if (v.Size > Size)
	{
		TVector<ValType> res (v.Size, v.StartIndex);
		for ( int i = 0; i < v.Size - Size; i++)
			res.pVector[i] = res.pVector[i] - v.pVector[i];
		for ( int i = (v.Size-Size), k = 0 ; i < v.Size ; i++,k++ )
		{
			res.pVector[i] = pVector[k] - v.pVector[i];
		}
		return res;
	}
	else 
	{
		TVector<ValType> res (*this);
		for ( int i = (v.StartIndex - StartIndex); i < Size; i++ )
		{
			res.pVector[i] = pVector[i] - v.pVector[i];
		}
		
		return res;
	}
} /*-------------------------------------------------------------------------*/

template <class ValType> // скалярное произведение
	ValType TVector<ValType>::operator*(const TVector<ValType> &v)
{
	if((Size + StartIndex) != (v.Size + v.StartIndex))
	{
		throw("add with not equal size");
	}

	int a = 0;
	if (Size < v.Size)
	{
		for (int i = 0; i < Size; i++)
			a+=pVector[i]*v.pVector[ v.Size - Size + i];
	}
	 else 
	 {
		for (int i = 0; i < v.Size; i++)
			a+=v.pVector[i]*pVector[ Size - v.Size + i];
	}

	return a;
} /*-------------------------------------------------------------------------*/


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);                           
	TMatrix(const TMatrix &mt);                    // копирование
	TMatrix(const TVector<TVector<ValType> > &mt); // преобразование типа
	bool operator==(const TMatrix &mt) const;      // сравнение
	bool operator!=(const TMatrix &mt) const;      // сравнение
	TMatrix& operator= (const TMatrix &mt);        // присваивание
	TMatrix  operator+ (const TMatrix &mt);        // сложение
	TMatrix  operator- (const TMatrix &mt);        // вычитание

	// ввод / вывод
	friend istream& operator>>(istream &in, TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream & operator<<( ostream &out, const TMatrix &mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s): TVector<TVector<ValType> >(s)
{
	if ( (s <= 0 ) || (s > MAX_MATRIX_SIZE))
		throw ("wrong matrix size specified");

	Size = s;
	StartIndex = 0;
	for (int i = 0, j = s; i < s; i++, j--)
	{
		TVector<ValType> v(j,i);
		pVector[i] = v;
	}

} /*-------------------------------------------------------------------------*/

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt):TVector<TVector<ValType> >(mt) 
{
	TVector<TVector<ValType>> a (mt);
	Size = a.GetSize();
	StartIndex = 0;
}

template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> > &mt):
TVector<TVector<ValType> >(mt) 
{
    TVector<TVector<ValType>> a (mt);
    Size = a.GetSize();
	StartIndex = 0;
}

template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>> :: operator== (mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
{
	return TVector<TVector<ValType>> :: operator!= (mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
{
	TVector<TVector<ValType>> :: operator= (mt);
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>> :: operator+ (mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
{
	return TVector<TVector<ValType>> :: operator- (mt);
} /*-------------------------------------------------------------------------*/

// TVector О3 Л2 П4 С6
// TMatrix О2 Л2 П3 С3
#endif
