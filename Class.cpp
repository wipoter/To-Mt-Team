#include "Matrix.h"
#include <stdexcept>

//����������� �� ���������, ������� ������ ������� � ���� ����� � ���� ��������
Matrix::Matrix() {
	collumn = 0;
	row = 0;
	matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[collumn];
}

//����������� �� ���� ������������� ����������: num_rows � num_cols, � ������� ������ ���������� ����� � �������� ������� ��������������
Matrix::Matrix(int num_rows, int num_cols) {
	if (num_rows < 0 || num_cols < 0) {
		throw out_of_range("There is minus number!");
	}
	else {
		collumn = num_cols;
		row = num_rows;
		matr = new int* [row];
		for (int i = 0; i < row; i++)
			matr[i] = new int[collumn];
	}
}

//����� Reset, ����������� ��� ������������� ���������, ������� ������
//����� ���������� ����� � �������� ������� ��������������; ����� Reset ������ ������� ������� �� �������� � �������� ��� � ��������
void Matrix::Reset(int num_rows, int num_cols) {
	if (num_rows < 0 || num_cols < 0) {
		throw out_of_range("There is minus number!");
	}
	else {
		collumn = num_cols;
		row = num_rows;
		matr = new int* [row];
		for (int i = 0; i < row; i++)
			matr[i] = new int[collumn];
	}
}

//����������� ����� At, ������� ��������� ����� ������ � ����� ������� (������ � ���� �������; 
//��������� ����� � �������� ���������� � ����) � ���������� �������� � �������������� ������ �������
const int Matrix::At(int el_row, int el_col) const{
	return matr[el_row][el_col];
}

//������������� ����� At � ������ �� �����������, �� ������������ ������ �� �������� � �������������� ������ �������
int* Matrix::At(int el_row, int el_col) {
	return *(matr + el_row) + el_col;
}

//����������� ������ GetNumRows � GetNumColumns, ������� ���������� ���������� ����� � �������� ������� ��������������
const int Matrix::GetNumCol() {
	return collumn;
}
const int Matrix::GetNumRow() {
	return row;
}

//�������� ����� �� ������ istream; ������ ����� ������� � ������� ������� ���������� ����� � �������� 
//(������ � ���� �������), � ����� ��� �������� �������: ������� ������� ������ ������ � ������� �������, ����� ������� 
//������ ������ � ������� ������� � ��� �����
istream& operator>>(istream& in, Matrix& matrToInput) {
	int cols, rows;
	in >> rows >> cols;
	matrToInput.Reset(rows, cols);
	matrToInput.collumn = cols;
	matrToInput.row = rows;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			in >> matrToInput.matr[i][j];
	return in;
}

//�������� ������ � ����� ostream; �� ������ �������� ������� � ��� �� �������, � ����� � ������
//�������� �����, � � ������ ������ ���������� ����� � ��������, �� ������ � �������� ������ ������, � ������� � �������� ������ ������ � �.�.
ostream& operator<<(ostream& out, Matrix& matrToOutput) {
	out << matrToOutput.row << " " << matrToOutput.collumn << endl;
	for (int i = 0; i < matrToOutput.row; i++) {
		for (int j = 0; j < matrToOutput.collumn; j++)
			out << matrToOutput.matr[i][j] << " ";
		out << endl;
	}
	return out;
}

//�������� �������� �� ��������� (==): �� ������ ���������� true, ���� ������������ ������� ����� ���������� ������
// � ��� �� ��������������� �������� ����� ����� �����, � ��������� ������ �� ������ ���������� false.
bool operator==(Matrix& first, Matrix& second) {
	if (first.collumn == second.collumn && first.row == second.row)
		for (int i = 0; i < first.row; i++)
			for (int j = 0; j < first.collumn; j++)
				if (first.matr[i][j] != second.matr[i][j])
					return false;
	else
		return false;
	return true;
}

//�������� ��������: �� ������ ��������� ��� ������� � ���������� ����� �������, ������� �������� �� ������;
//���� ���������� ������� ����� ������ ������� ���� �������� ������ ����������� ����������� ���������� invalid_argument.
Matrix operator+(Matrix& first, Matrix& second) {
	if (first.collumn == second.collumn && first.row == second.row) {
		Matrix tmp(first.row, first.collumn);
		for (int i = 0; i < tmp.row; i++)
			for (int j = 0; j < tmp.collumn; j++)
				tmp.matr[i][j] = first.matr[i][j] + second.matr[i][j];
		return tmp;
	}
	else {
		throw invalid_argument("Matrix are diferent in size!");
	}
}