#pragma once

#include<iostream>
using namespace std;

class Matrix {
	int collumn;
	int row;
	int** matr;
public:
	Matrix();
	Matrix(int, int);
	void Reset(int, int);
	const int At(int, int)const;
	int* At(int, int);
	const int GetNumRow();
	const int GetNumCol();
	friend istream& operator >>(istream&, Matrix&);
	friend ostream& operator <<(ostream&, Matrix&);
	friend bool operator==(Matrix&, Matrix&);
	friend Matrix operator+(Matrix&, Matrix&);
};
