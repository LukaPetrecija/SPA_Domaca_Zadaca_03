#pragma once
#include <vector>
using namespace std;

class Tocka
{
private:
	int x;
	int y;
public:
	int get_x() const;
	int get_y() const;
	void set_x(int x);
	void set_y(int y);
	void nacrtaj(const Tocka& a, const Tocka& b, const vector<Tocka>& prepreke) const;
	bool prepreka(int x, int y, const vector<Tocka>& prepreke) const;
};

