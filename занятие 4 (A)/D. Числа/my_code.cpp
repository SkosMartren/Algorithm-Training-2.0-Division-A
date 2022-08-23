#include<iostream>
#include<vector>
#include<algorithm> // min

using namespace std;

void reading_symbols(const string& s, vector<int>& symbols_A) {

	for (const auto chr : s) {
		++symbols_A[int(chr) - '0'];
	}

}

int main() {

	// input
	string A, B;
	cin >> A >> B;

	// solution
	vector<int> symbols_A(10, 0);
	vector<int> symbols_B(10, 0);
	reading_symbols(A, symbols_A);
	reading_symbols(B, symbols_B);

	for (int i = 0; i < 10; ++i) {
		symbols_A[i] = min(symbols_A[i], symbols_B[i]);
	}

	// output
	bool check = true;
	for (int i = 9; i >= 0; --i) {
		for (int j = 0; j < symbols_A[i]; ++j) {

			if (check && i == 0) {
				cout << 0;
				return 0;
			}
			else {
				cout << i;
				check = false;
			}

		}
	}
	if (check) {
		cout << -1;
	}

	return 0;
}
