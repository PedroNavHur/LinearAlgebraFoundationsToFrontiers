#include <iostream>
#include <ostream>
#include <vector>
#include <map>

using namespace std;

struct pos {
	int deg;
	int min;
	pos(int x, int y) : deg(x), min(y) {}
	void move(pos mov) {
		deg += mov.deg;
		min += mov.min;

		if (min < 0 && deg > 0) {
			deg--;
			min += 60;
		}

		if (min > 0 && deg < 0) {
			deg++;
			min -= 60;
		}

		if (min >= 60) {
			deg++;
			min -= 60;
		}

		if (min <= -60) {
			deg--;
			min += 60;
		}

	}
};

struct coord {
	pos lon;
	pos lat;
	coord(pos y, pos x) : lon(y), lat(x) {};
	void move(pos lo, pos la) {
		lon.move(lo);
		lat.move(la);
	}
};

ostream& operator<<(ostream& os, const coord& place)
{
	os << place.lon.deg << " " << place.lon.min << "' "
	   << place.lat.deg << " " << place.lat.min << "' ";
	return os;
}

int main() {
	vector<coord> moves;

	int w, x, y, z;

	cout << "Enter the 8 movements " << endl;
	for (auto i = 0; i < 8; i++) {
		cin >> w >> x >> y >> z;
		moves.emplace_back(pos(w, x), pos(y, z));
	}

	cout << "Enter the starting point" << endl;
	cin >> w >> x >> y >> z;
	coord location(pos(w, x), pos(y, z));
	cout << location << endl;

	cout << "Results: " << endl;
	for (auto x : moves) {
		location.move(x.lon, x.lat);
		cout << location << endl;
	}
}