#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void hamsapxep(int danhsach[])
{

	int i, j;
	int temp;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (danhsach[j] > danhsach[j + 1])
			{
				temp = danhsach[j];
				danhsach[j] = danhsach[j + 1];
				danhsach[j + 1] = temp;
			}

	for (i = 0; i < 10; i++)
		cout << danhsach[i] << "\n";
}

void hamsapxep(float danhsach[])
{

	int i, j;
	float temp;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (danhsach[j] > danhsach[j + 1])
			{
				temp = danhsach[j];
				danhsach[j] = danhsach[j + 1];
				danhsach[j + 1] = temp;
			}

	for (i = 0; i < 10; i++)
		cout << danhsach[i] << "\n";
}
void hamsapxep(double danhsach[])
{

	int i, j;
	double temp;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (danhsach[j] > danhsach[j + 1])
			{
				temp = danhsach[j];
				danhsach[j] = danhsach[j + 1];
				danhsach[j + 1] = temp;
			}

	for (i = 0; i < 10; i++)
		cout << danhsach[i] << "\n";
}

int main(int argc, char *argv[])
{
	int danhsach[] = {11, 2, 15, 14, 6, 22, 26, 32, 9, 20};
	hamsapxep(danhsach);

	return 0;
}