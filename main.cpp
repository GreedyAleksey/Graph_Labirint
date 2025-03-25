#include<iostream>
#include<Windows.h>
#include<fstream>
#include"GraphMatrix.h"
#include<conio.h>
#include<chrono>

#include"Graph.h"

using namespace std;
using namespace chrono;

int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char key1, key2;
	bool flag1 = true, flag2 = true;
	int start, finish, index;

	// ���������� �����������, ����� �������� �����
	steady_clock::time_point begin, end;
	microseconds duration;

	ifstream file;

	Graph grph;

	// ���������������� ���������
	cout << "\t\t\t< ����� ����������! >" << endl;
	do {
		cout << endl << "---------------------------------->| ������� ���� |<---------------------------------" << endl << endl;
		cout << "1 ����� - ��������� ���� �� ����� � ������� ������ ���������� ����;" << endl
			<< "2 ����� - ������������ ���� �� ������ ������������ � ������� ������ ���������� ����." << endl
			<< "����� ������ ������� ��� ���������� ������ ���������." << endl;
		cout << endl << "-------------------------------------------------------------------------------------" << endl;
		key1 = _getch();

		switch (key1) {
		// 1 ����� - ������ � ������ �� �����
		case '1':
			file.open("input.txt");
			file >> grph;

			cout << "����:" << endl << grph << endl;
			cout << "\t�������� ������ ���������� ����:"<< endl
				<< "\t1 - �������� ������ � �������;" << endl
				<< "\t2 - �������� ������ � ������;" << endl
				<< "\t����� ������ ������� ��� ������ � ������� ����." << endl;
			
			key2 = _getch();

			if (key2 == '1' || key2 == '2') {
				cout << "������� ��������� ������� � �������� ��������������: ";
				cin >> start >> finish;
			}

			// ���������� ���� �������� ��������
			switch (key2) {
			case '1':
				cout << endl << "���� �������� ���������� ������ � �������:" << endl;
				begin = high_resolution_clock::now();
				grph.DFS(start, finish);
				end = high_resolution_clock::now();
				duration = duration_cast<microseconds>(end - begin); // ������ ������� ���������� ����

				grph.wayOut();
				cout << "�����: " << duration.count() << " ���.";
				break;

			case '2':
				cout << endl << "���� �������� ���������� ������ � ������:" << endl;
				begin = high_resolution_clock::now();
				grph.BFS(start, finish);
				end = high_resolution_clock::now();
				duration = duration_cast<microseconds>(end - begin);

				grph.wayOut();
				cout << "�����: " << duration.count() << " ���.";
				break;

			default:
				break;
			}
			file.close();
			break;

			// 2 ����� - ������ � ���������������� ������
		case '2':
			cin >> grph;
			flag2 = true;

			do {
				cout << "\t�������� ��������:" << endl
					<< "\t1 - �������� �������;" << endl
					<< "\t2 - �������� �����;" << endl
					<< "\t3 - ������� �������;" << endl
					<< "\t4 - ������� �����;" << endl
					<< "\t5 - ����� �����." << endl << endl;

				key2 = _getch();

				// �������������� �����
				switch (key2) {
				case '1':
					grph.addVertex();
					cout << "������� ���������." << endl << endl;
					break;

				case '2':
					cout << "������� ������� ���� ������, ����� �������� �������� �����: ";
					cin >> start >> finish;
					grph.addEdge(start, finish);
					cout << "����� ���������." << endl << endl;
					break;

				case '3':
					cout << "������� ������ �������, ����� ������� ������ �������: ";
					cin >> index;
					grph.delVertex(index);
					cout << "��� ����� ������� �������." << endl << endl;
					break;

				case '4':
					cout << "������� ������� ���� ������, ����� �������� ������� �����: ";
					cin >> start >> finish;
					grph.delEdge(start, finish);
					cout << "����� �������." << endl << endl;
					break;

				case '5':
					flag2 = false;
					break;

				default:
					break;
				}

			} while (flag2);

			cout << "����:" << endl << grph << endl;
			cout << "\t�������� ������ ���������� ����:" << endl
				<< "\t1 - �������� ������ � �������;" << endl
				<< "\t2 - �������� ������ � ������;" << endl
				<< "\t����� ������ ������� ��� ������ � ������� ����." << endl << endl;

			key2 = _getch();

			if (key2 == '1' || key2 == '2') {
				cout << "������� ��������� ������� � �������� ��������������: ";
				cin >> start >> finish;
			}

			// ���������� ���� ��������� ��������
			switch (key2) {
			case '1':
				cout << endl << "���� �������� ���������� ������ � �������:" << endl;
				begin = high_resolution_clock::now();

				grph.DFS(start, finish);
				end = high_resolution_clock::now();
				duration = duration_cast<microseconds>(end - begin);

				grph.wayOut();
				cout << "�����: " << duration.count() << " ���.";
				break;

			case '2':
				cout << endl << "���� �������� ���������� ������ � ������:" << endl;
				begin = high_resolution_clock::now();
				grph.BFS(start, finish);
				end = high_resolution_clock::now();
				duration = duration_cast<microseconds>(end - begin);

				grph.wayOut();
				cout << "�����: " << duration.count() << " ���.";
				break;

			default:
				break;
			}
			break;

		default:
			flag1 = false;
			break;
		}
	} while (flag1);
}