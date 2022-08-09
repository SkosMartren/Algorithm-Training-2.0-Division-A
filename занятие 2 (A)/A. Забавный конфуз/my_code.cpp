#include<iostream>
#include<algorithm> // swap
#include<cmath> // abs

using namespace std;

int main() {

	// input and solution
	int N, K;
	cin >> N >> K;

	int64_t B_max, B_min;
	cin >> B_max >> B_min;

	if (B_max < B_min) {
		swap(B_max, B_min);
	}

	for (int i = 2; i < N; ++i) {
		int B_i;
		cin >> B_i;

		if (B_max < B_i) {
			B_max = B_i;
		}

		if (B_min > B_i) {
			B_min = B_i;
		}
	}
	
	// output
	cout << abs(B_max - B_min);
	return 0;
}
