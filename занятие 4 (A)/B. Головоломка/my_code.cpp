#include<iostream>
#include<unordered_map>

using namespace std;

void change_count_sml_plus(unordered_map <char, int>& table_sml_to_count_sml, const int counter) {

	for (int i = 0; i < counter; ++i) {
		string word;
		cin >> word;
		for (const auto sml : word) {
			++table_sml_to_count_sml[sml];
		}

	}

}

void change_count_sml_minus(unordered_map <char, int>& table_sml_to_count_sml, const int counter) {

	for (int i = 0; i < counter; ++i) {
		string word;
		cin >> word;
		for (const auto sml : word) {
			--table_sml_to_count_sml[sml];
		}

	}

}

int main() {

	// input and solution
	int N, M;
	cin >> N >> M;

	unordered_map <char, int> table_sml_to_count_sml;
	change_count_sml_plus(table_sml_to_count_sml, N);
	change_count_sml_minus(table_sml_to_count_sml, M);

	// output
	for (const auto [sml, count] : table_sml_to_count_sml) {
		for (int i = 0; i < count; ++i) {
			cout << sml;
		}
	}
	return 0;
}
