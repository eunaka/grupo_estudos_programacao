#include <iostream>

using namespace std;

int main(int argc, char *arg[])
{
	int div, n_div, mult, n_mult;
	int i, x, n;

	cin >> div >> n_div >> mult >> n_mult;

	x = mult / div;
	for (i = 0; i < x; i++)
	{
		n = div * i;
		if (n % n_div && n % n_mult)
			break;
	}

	cout << n << endl;

	return 0;
}