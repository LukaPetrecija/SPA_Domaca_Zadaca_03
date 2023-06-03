#include <iostream>
#include "Tocka.h"
#include <vector>
using namespace std;

int main()
{
	int x, y;
	bool wish = true;
	vector<Tocka> v;
	vector<Tocka> zid;
	Tocka t;
	for (int i = 0; i < 2; i++)
	{
		cout << "x" << i + 1 << ": ";
		cin >> x;
		x = x - 1;
		t.set_x(x);
		cout << "y" << i + 1 << ": ";
		cin >> y;
		y = y - 1;
		t.set_y(y);
		v.push_back(t);
	}

	do
	{
		cout << "Unesite x koordinatu prepreke: ";
		cin >> x;
		x = x - 1;
		t.set_x(x);
		cout << "Unesite y koordinatu prepreke: ";
		cin >> y;
		y = y - 1;
		t.set_y(y);
		zid.push_back(t);
		cout << "Zelite jos unositi? (1 = da, 0 = ne) ";
		cin >> wish;
	} while (wish);

	t.nacrtaj(v[0], v[1], zid);

	return 0;
}