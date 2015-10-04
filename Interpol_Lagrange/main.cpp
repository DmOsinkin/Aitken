#include <iostream>
#include <fstream>

using namespace std;

class Aitken {
private:
	int n;
	double *X_values;
	double *Y_values;
	double step(int n, int m, double x) {
		if (m == n) return Y_values[n];
		return 
			((x - X_values[n]) *
			step(n + 1, m, x) - 
			(x - X_values[m]) *
			step(n, m - 1, x)) /
			(X_values[m] - X_values[n]);
	};
public:
	Aitken(int n, double *X_values, double *Y_values) {
		this->n = n;
		this->X_values = new double[n];
		this->Y_values = new double[n];
		for (int i = 0; i<n; i++) 
		{
			this->X_values[i] = X_values[i];
			this->Y_values[i] = Y_values[i];
		}
	}
	double operator()(double x) {
		return step(0, n - 1, x);
	}
};

int main() {
	int n; //���-�� ��������������� ����� � ��������� ������
	setlocale(0, "Russian"); 
	cout << "���������� ����� ������������ . . .  ";
	cin >> n; 
	cout << "\n\n======================================" << endl;
	double *X_values = new double[n];
	double *Y_values = new double[n];
	//������� ������ ������ �������� � � Y �� ������
	ifstream Xin;
	Xin.open("dataX.txt");
	ifstream Yin;
	Yin.open("dataY.txt");
	//��������� ������ � � ������ Y, ������� �� �����
	cout << "X[n]\tY[n]" << endl;
	for (int i = 0; i < n; i++)
	{
		Xin >> X_values[i];
		Yin >> Y_values[i];
		cout << X_values[i] << "\t" << Y_values[i] << endl;
	};
	cout << "======================================\n\n" << endl;
	//������ �����
	double x;
	cout << "����a x . . .  ";
	cin >> x;
	//������� �������� �� ����� �������
	Aitken example(n, X_values, Y_values);
	cout << "����� . . . " << example(x) << endl;
	system("pause");
	return 0;
}