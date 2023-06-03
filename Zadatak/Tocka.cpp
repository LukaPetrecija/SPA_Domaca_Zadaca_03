#include "Tocka.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int Tocka::get_x() const
{
	return x;
}

int Tocka::get_y() const
{
	return y;
}

void Tocka::set_x(int x)
{
	this->x = x;
}

void Tocka::set_y(int y)
{
	this->y = y;
}

void Tocka::nacrtaj(const Tocka& a, const Tocka& b, const vector<Tocka>& prepreke) const {
    if (a.get_x() == b.get_x() && a.get_y() == b.get_y()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == a.get_y() && j == a.get_x()) {
                    cout << "x";
                }
                else {
                    cout << "-";
                }
            }
            cout << endl;
        }
        return;
    }

    int movex = 0;
    int movey = 0;

    if (b.get_x() != a.get_x())
        movex = (b.get_x() - a.get_x()) / abs(b.get_x() - a.get_x());
    if (b.get_y() != a.get_y())
        movey = (b.get_y() - a.get_y()) / abs(b.get_y() - a.get_y());

    int xx = a.get_x();
    int yy = a.get_y();

    while (xx != b.get_x() || yy != b.get_y()) {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == a.get_y() && j == a.get_x()) {
                    cout << "A";
                }
                else if (i == b.get_y() && j == b.get_x()) {
                    cout << "B";
                }
                else if (i == yy && j == xx) {
                    cout << "x";
                }
                else if (prepreka(j, i, prepreke)) {
                    cout << "*";
                }
                else {
                    cout << "-";
                }
            }
            cout << endl;
        }
        Sleep(100);

        
        if (xx != b.get_x() && !prepreka(xx + movex, yy, prepreke))
            xx += movex;
        if (yy != b.get_y() && !prepreka(xx, yy + movey, prepreke))
            yy += movey;

        
        system("CLS");
    }

    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            if (i == a.get_y() && j == a.get_x() && !(a.get_x() == b.get_x() && a.get_y() == b.get_y())) {
                cout << "A";
            }
            else if (i == b.get_y() && j == b.get_x() && !(a.get_x() == b.get_x() && a.get_y() == b.get_y())) {
                cout << "x";
            }
            else if (prepreka(j, i, prepreke)) {
                cout << "*";
            }
            else {
                cout << "-";
            }
        }
        cout << endl;
    }
}

bool Tocka::prepreka(int x, int y, const vector<Tocka>& prepreke) const
{
    for (int i = 0; i < prepreke.size(); i++)
    {
        if (prepreke[i].get_x() == x &&  prepreke[i].get_y() == y)
        {
            return true;
        }
    }
    return false;
}





