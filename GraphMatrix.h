#pragma once

#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;

// граф представляется ввиде матрицы смежности со стороной N
class GraphMatrix {
	int N;
	vector<vector<int>> matrix;

public:

	GraphMatrix();
	GraphMatrix(int n);
	~GraphMatrix();

	void generateRandomMatrix();
	void in(istream& stream);
	void out(ostream& stream)const;

	void addNode();
	void deleteNode(int index);
	GraphMatrix& operator=(const GraphMatrix& p);
};

istream& operator>>(istream& stream, GraphMatrix& g);
ostream& operator<<(ostream& stream, const GraphMatrix& g);