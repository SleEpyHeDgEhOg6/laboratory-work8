#include <iostream>
#include <cstring>
using namespace std;

struct Matrix {
	// двумерный массив с данными.
	int** data_ = nullptr;
	// количество столбцов
	size_t n_ = 0u;
	// количество строк
	size_t m_ = 0u;
};

void Construct(Matrix& out, size_t n, size_t m) {// Создает заполненную нулями матрицу n x m
	out.n_ = n;//out-значение параметра не имеет значения
	out.m_ = m;
	out.data_ = new int* [n];//место для строк 
	for (int i = 0; i < n; ++i) {
		out.data_[i] = new int[m]();//место для столбцов
	}
}

int main1() {
	Matrix m1;
	Construct(m1, 4, 5);
	return 0;
}


void Destruct(Matrix& in) {// Освобождает выделенную память
	for (int p = 0; p < in.n_; ++p) {
		delete[] in.data_[p];
	}
	delete[] in.data_;
}

int main2() {
	Matrix m2;
	Construct(m2, 7, 9);
	Destruct(m2);
	return 0;

}

Matrix Copy(const Matrix& matrix) {// Создает копию матрицы |matrix|
	Matrix m3;
	Construct(m3, matrix.n_, matrix.m_);
	for (int u = 0; u < matrix.n_; ++u) {
		for (int y = 0; y < matrix.m_; ++y) {
			m3.data_[u][y] = matrix.data_[u][y];
		}
	}
	return m3;
}


Matrix Add(const Matrix& a, const Matrix& b) {// Возвращает сумму двух матриц.Если операция невозможна - вернуть пустую матрицу
	Matrix summa;
	if (a.n_ != b.n_ || a.m_ != b.m_) {
		return summa;
	}
	Construct(summa, b.n_, b.m_);
	for (int q = 0; q < b.n_; ++q) {
		for (int w = 0; w < b.m_;++w) {
			summa.data_[q][w] = b.data_[q][w] + a.data_[q][w];
		}
	}
	return summa;
}

int main3() {
	Matrix m4;
	Construct(m4, 2, 3);
	m4.data_[0][0] = 3;
	m4.data_[0][1] = 8;
	m4.data_[0][2] = 1;
	m4.data_[1][0] = 2;
	m4.data_[1][1] = 5;
	m4.data_[1][2] = 7;
	Matrix m5;
	Construct(m5, 2, 3);
	m5.data_[0][0] = 2;
	m5.data_[0][1] = 1;
	m5.data_[0][2] = 10;
	m5.data_[1][0] = 2;
	m5.data_[1][1] = 8;
	m5.data_[1][2] = 5;
	Matrix su = Add(m4, m5);
	return 0; 
}


Matrix Sub(const Matrix& a, const Matrix& b) {// Возвращает разницу двух матриц.Если операция невозможна - вернуть пустую матрицу
	Matrix pas;
	if (a.n_ != b.n_ || a.m_ != b.m_) {
		return pas;
	}
	Construct(pas, b.n_, b.m_);
	for (int q = 0; q < b.n_; ++q) {
		for (int w = 0; w < b.m_; ++w) {
			pas.data_[q][w] = b.data_[q][w] - a.data_[q][w];
		}
	}
	return pas;
}

int main4() {
	Matrix m6;
	Construct(m6, 2, 3);
	m6.data_[0][0] = 3;
	m6.data_[0][1] = 8;
	m6.data_[0][2] = 1;
	m6.data_[1][0] = 2;
	m6.data_[1][1] = 5;
	m6.data_[1][2] = 7;
	Matrix m7;
	Construct(m7, 2, 3);
	m7.data_[0][0] = 2;
	m7.data_[0][1] = 1;
	m7.data_[0][2] = 10;
	m7.data_[1][0] = 2;
	m7.data_[1][1] = 8;
	m7.data_[1][2] = 5;
	Matrix su = Add(m6, m7);
	return 0;
}

Matrix Mult(const Matrix& a, const Matrix& b) {// Возвращает произведение двух матриц.Если операция невозможна - вернуть пустую матрицу
	//можно перемножать только такие матрицы у которых число столбцов в первой матрице равно числу строк во второй матрице
	Matrix ot;
	Construct(ot, a.n_, b.m_);
	if (a.m_ != b.n_) {
		return ot;
	}
	for (int e = 0; e < a.n_; ++e) {
		for (int r = 0; r < b.m_; ++r) {
			ot.data_[e][r] = 0;
			for (int o = 0; o < a.m_; ++o) {
				ot.data_[e][r] += a.data_[e][o] * b.data_[o][r];
			}
		}
	}
	return ot;
}

int main5() {
	Matrix m8;
	Construct(m8, 2, 3);
	m8.data_[0][0] = 3;
	m8.data_[0][1] = 8;
	m8.data_[0][2] = 1;
	m8.data_[1][0] = 2;
	m8.data_[1][1] = 5;
	m8.data_[1][2] = 7;
	Matrix m9;
	Construct(m9, 2, 3);
	m9.data_[0][0] = 2;
	m9.data_[0][1] = 1;
	m9.data_[0][2] = 10;
	m9.data_[1][0] = 2;
	m9.data_[1][1] = 8;
	m9.data_[1][2] = 5;
	Matrix yn=Mult(m8, m9);
	return 0;
}

void Transposition(Matrix& matrix) {// Транспонирование матрицы
	Matrix t;
	Construct(t, matrix.m_, matrix.n_);
	for (int g = 0; g < matrix.n_; ++g) {
		for (int f = 0; f < matrix.m_; ++f) {
			t.data_[f][g] = matrix.data_[g][f];
		}
	}
	Destruct(matrix);
	matrix = t;
}

bool operator==(const Matrix& a, const Matrix& b) {// Сравнение двух матриц
	for (int j = 0; j < a.n_; ++j) {
		for (int n = 0; n < a.m_; ++n) {
			if (a.data_[j][n] == b.data_[j][n]) {
				return true;
			}
		}
	}
	return false;
}
