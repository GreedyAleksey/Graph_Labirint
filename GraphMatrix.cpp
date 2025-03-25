#include "GraphMatrix.h"

#include<iostream>
#include<ctime>
#include<cstdlib>

GraphMatrix::GraphMatrix() {
	matrix = { {0} };
}

GraphMatrix::GraphMatrix(int n) {
	N = n;
	matrix.resize(N);
	for (int i = 0; i < N; i++)
		matrix[i].resize(N);
}

GraphMatrix::~GraphMatrix() {
	cout << "Worked destructor of GraphMatrix" << endl;
}


void GraphMatrix::generateRandomMatrix() {
	int i, j, x;
	srand(time(NULL));
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			x = rand() % 100;
			if (x > 50)
				matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
		}
	}

	for (i = 0; i < N; i++)
		matrix[i][i] = 0;
}

void GraphMatrix::in(istream& stream) {
	if (&stream == &cin) {
		cout << "¬ведите размер матрицы N: ";
	}

	stream >> N;

	matrix.resize(N);
	for (int i = 0; i < N; i++)
		matrix[i].resize(N);

	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			stream >> matrix[i][j];
		}
	}
}

void GraphMatrix::out(ostream& stream)const {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			stream << matrix[i][j];
			if (j != N - 1)
				stream << " ";
		}
		stream << endl;
	}
}

void GraphMatrix::addNode() {
	int i, j;

	N++;
	matrix.resize(N);
	for (int i = 0; i < N; i++)
		matrix[i].resize(N);

	cout << "¬ведите " << N - 1 << " отношение с остальными вершинами:" << endl;
	for (i = 0; i < N - 1; i++) {
		cin >> matrix[N - 1][i];
		matrix[i][N - 1] = matrix[N - 1][i];
	}
	matrix[N - 1][N - 1] = 0;

}

void GraphMatrix::deleteNode(int index) {
	GraphMatrix newMatrix(N - 1);
	int i, j;
	for (i = 0; i < N; i++) {
		if (i == index)continue;

		for (j = 0; j < N; j++) {
			if (j == index)continue;

			newMatrix.matrix[i][j] = matrix[i][j];
		}
	}

	*this = newMatrix;
	
}

GraphMatrix& GraphMatrix::operator=(const GraphMatrix& p) {
	int i, j;
	if (N != p.N) {
		N = p.N;
		matrix.resize(N);
		for (int i = 0; i < N; i++)
			matrix[i].resize(N);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			matrix[i][j] = p.matrix[i][j];
		}
	}
	return *this;

}

istream& operator>>(istream& stream, GraphMatrix& g) {
	g.in(stream);
	return stream;
}

ostream& operator<<(ostream& stream, const GraphMatrix& g) {
	g.out(stream);
	return stream;
}
