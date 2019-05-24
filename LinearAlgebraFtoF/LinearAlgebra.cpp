#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// Check for equality exercise
// We assume they have the same length.
auto checkEquality(vector<int> a, vector<int> b) {
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
auto doAssign(vector<int>& a) {
	
	int n, x;
	cout << "how many assigments?" << endl;
	cin >> n;

	while (n-- > 0) {
		cin >> x;
		a.push_back(x);
	}
}

// Copy a vector
auto doCopy(vector<int> a, vector<int>& b) {
	size_t length = a.size();

	for (auto i = 0; i < length; i++) {
		b[i] = a[i];
	}
}


void runTestsA() {

}

int main() {

	runTestsA();



}