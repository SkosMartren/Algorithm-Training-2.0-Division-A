#include<iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int sum_length_rope_on_table = 0;
	int max_length_rope = -1;
	for (int j = 0; j < N; ++j) {

		int length_rope;
		cin >> length_rope;

		sum_length_rope_on_table += length_rope;

		if (max_length_rope < length_rope) {
			max_length_rope = length_rope;
		}

	}

	// output
	if (sum_length_rope_on_table - max_length_rope < max_length_rope) { // Маша забрала не самую длинную веревку со стола
		cout << (max_length_rope - (sum_length_rope_on_table - max_length_rope));
	}
	else { 		
		cout << sum_length_rope_on_table; // Маша забрала самую длинную веревку со стола
	}

	return 0;
}
