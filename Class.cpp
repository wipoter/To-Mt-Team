#include "Matrix.h"
#include <stdexcept>

//конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
Matrix::Matrix() {
	collumn = 0;
	row = 0;
	matr = new int* [row];
	for (int i = 0; i < row; i++)
		matr[i] = new int[collumn];
}

//конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
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

//метод Reset, принимающий два целочисленных параметра, которые задают
//новое количество строк и столбцов матрицы соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
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

//константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; 
//нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
const int Matrix::At(int el_row, int el_col) const{
	return matr[el_row][el_col];
}

//неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
int* Matrix::At(int el_row, int el_col) {
	return *(matr + el_row) + el_col;
}

//константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно
const int Matrix::GetNumCol() {
	return collumn;
}
const int Matrix::GetNumRow() {
	return row;
}

//оператор ввода из потока istream; формат ввода простой — сначала задаётся количество строк и столбцов 
//(именно в этом порядке), а затем все элементы матрицы: сначала элемент первой строки и первого столбца, затем элемент 
//первой строки и второго столбца и так далее
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

//оператор вывода в поток ostream; он должен выводить матрицу в том же формате, в каком её читает
//оператор ввода, — в первой строке количество строк и столбцов, во второй — элементы первой строки, в третьей — элементы второй строки и т.д.
ostream& operator<<(ostream& out, Matrix& matrToOutput) {
	out << matrToOutput.row << " " << matrToOutput.collumn << endl;
	for (int i = 0; i < matrToOutput.row; i++) {
		for (int j = 0; j < matrToOutput.collumn; j++)
			out << matrToOutput.matr[i][j] << " ";
		out << endl;
	}
	return out;
}

//оператор проверки на равенство (==): он должен возвращать true, если сравниваемые матрицы имеют одинаковый размер
// и все их соответствующие элементы равны между собой, в противном случае он должен возвращать false.
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

//оператор сложения: он должен принимать две матрицы и возвращать новую матрицу, которая является их суммой;
//если переданные матрицы имеют разные размеры этот оператор должен выбрасывать стандартное исключение invalid_argument.
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