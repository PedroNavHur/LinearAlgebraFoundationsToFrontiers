#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using vec = vector<int> &;
using cvec = const vector<int> &;

// Check for equality exercise
// We assume they have the same length.
auto checkEquality(cvec a, cvec b) {
	auto length = a.size();
	bool isEqual = true;

	for (auto i = 0; i < length && isEqual; i++) {
		if (a[i] != b[i]) {
			isEqual = false;
		}
	}

	return isEqual;
}

// Assign to a vector
auto doAssign(vec a) {
	
	int n, x;
	cout << "how many assigments?" << endl;
	cin >> n;

	while (n-- > 0) {
		cin >> x;
		a.push_back(x);
	}
}

// Copy a vector
auto doCopy(cvec a, vec b) {
	size_t length = a.size();

	for (auto i = 0; i < length; i++) {
		b[i] = a[i];
	}
}


// Show Vector
auto showVec(cvec a) {
	cout << "[ ";
	for (auto x : a) {
		cout << x << " ";
	}
	cout << "]" << endl;
}

// Add Vectors
auto addVec(cvec a, cvec b, vec c) {
	auto length = a.size();

	for (auto i = 0; i < length; i++) {
		c[i] = a[i] + b[i];
	}
}

void runTestsA() {
	vector<int> a, b, c;
	doAssign(a);
	doAssign(b);

	showVec(a);
	showVec(b);
	
	cout << checkEquality(a, b) << endl;
	
	c.resize(a.size());
	doCopy(a, c);
	showVec(c);

	addVec(a, b, c);
	showVec(c);

}

int main() {

	runTestsA();



}