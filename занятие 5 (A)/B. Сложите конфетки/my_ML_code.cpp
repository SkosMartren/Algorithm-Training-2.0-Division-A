#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main() {

	// input
	int K;
	cin >> K;

	deque <uint64_t> candies;
	for (int i = 0; i < K; ++i) {

		uint64_t A_i, N_i;
		cin >> A_i >> N_i;

		for (int j = 0; j < N_i; ++j) {
			candies.push_back(A_i);
		}

	}

	// solution
	while (2 < candies.size()) {
		auto begin_candies_itr = candies.begin();
		auto last_candies_itr = candies.end() - 1;

		int min_from_first_last_value_candies = min(*begin_candies_itr, *last_candies_itr);
		*(begin_candies_itr) -= min_from_first_last_value_candies;
		*(last_candies_itr) -= min_from_first_last_value_candies;

		*(begin_candies_itr + 1) += min_from_first_last_value_candies;
		*(last_candies_itr - 1) += min_from_first_last_value_candies;
		if (*begin_candies_itr == 0) {
			candies.pop_front();
		}

		if (*last_candies_itr == 0) {
			candies.pop_back();
		}

	}
	// output
	cout << candies.size() << '\n';
	for (const auto& value : candies) {
		cout << value << ' ';
	}
	return 0;
}
