#include <iostream>
#include <fstream>

using namespace std;

double PolLag(double X_values[], double Y_values[], double x, int pow, int pos) {
	double Pol;
	if (pow == 1) {
		{
			Pol = (Y_values[pos-1] * (X_values[pos] - x) - Y_values[pos] * (X_values[pos-1] - x)) / (X_values[pos] - X_values[pos-1]);
		}
	}
	else {
		Pol = (PolLag(X_values, Y_values, x, (pow - 1), (pos - 1)) *
			  (X_values[pos] - x) - 
			   PolLag(X_values, Y_values, x, (pow - 1), pos) * 
			  (X_values[pos - pow] - x) /
			  (X_values[pos] - X_values[pos - pow]));
	}
	return Pol;
}

int main(/*int argc, char* argv[]*/)
{
	const int N=11;
	double x=0.58;
	//cout << "vvedite znachenie tochki = ";
	//cin >> x;
	ifstream Xin;
	Xin.open("dataX.txt");
	ifstream Yin;
	Yin.open("dataY.txt");
	double X[11];
	double Y[11];
	cout << "X[i]\tY[i]" << endl;
	for (int i = 0; i < N; i++)
	{
		Xin >> X[i];
		Yin >> Y[i];
		//cout << X[i] << "\t" << Y[i] << endl;
	};
	for (int i = 1; i <= 10; i++) {
		double Example = PolLag(X, Y, x, 2, i);
		cout<<i<<") " << Example << endl;
	}
	system("pause");
	return 0;
}





























//#include <iostream>
//#include <cmath>
//#include <fstream>
//#include <cstdio>
//
//using namespace std;
//
//
//double InterpolateLagrangePolynomial(double x, double *x_values, double *y_values, int s)
//{
//	double lagrange_pol = 0;
//	double basics_pol;
//
//	for (int i = 0; i < s; i++)
//	{
//		basics_pol = 1;
//		for (int j = 0; j < s; j++)
//		{
//			if (j == i) continue;
//			basics_pol *= (x - x_values[j]) / (x_values[i] - x_values[j]);
//		}
//		lagrange_pol += basics_pol*y_values[i];
//	}
//	return lagrange_pol;
//}
//
//int main(int argc, char *argv[2]){
//	double x = 0.58;
//	double *X;
//	double *Y;
//
//	ifstream Xin(argv[1]);
//	ifstream Yin(argv[2]);
//	int k;
//	cin >> k;
//	cout << "X[i]\tY[i]" << endl;
//	for (int i = 0; i < k; i++)
//	{
//		Xin >> X[i];
//		Yin >> Y[i];
//		cout << X[i] << "\t" << Y[i] << endl << endl;
//	}
//
//	double L=InterpolateLagrangePolynomial(x, X, Y, k);
//	cout << "otvet = " << L << endl;
//	return 0;
//}
//
//
//
//double testF(double x)
//{
//	return  x*x*x + 3 * x*x + 3 * x + 1; // for example
//}
//
//int main1(void)
//{
//	const int size = 10;
//	double x_values[size];
//	double y_values[size];
//
//
//	for (int i = 0; i < size; i++)
//	{
//		x_values[i] = i;
//		y_values[i] = testF(i);
//	}
//
//	printf("%lf\n", InterpolateLagrangePolynomial(13.6, x_values, y_values, size));
//
//	return 0;
//}