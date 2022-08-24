#include<iostream>
#include<map>
#include<algorithm> // reverse

using namespace std;

int main() {
	// input
	int N;
	string S;
	cin >> N >> S;

	// solution
	map<char, int> sml_str_S_to_count_sml;

	for (const auto sml : S) {
		++sml_str_S_to_count_sml[sml];
	}

	string sml_middle_palindrome; // char sml_middle_palindrome; // error!
	string half_palindrome;

	bool flag = 1;
	for (const auto& [sml_str, count] : sml_str_S_to_count_sml) {

		if (flag && count % 2 == 1) {
			sml_middle_palindrome = sml_str;
			flag = 0;
		}

		for (int i = 0; i < count / 2; ++i) {
			half_palindrome += sml_str;
		}
	}

	string ans = half_palindrome + sml_middle_palindrome;
	reverse(half_palindrome.begin(), half_palindrome.end());
	ans += half_palindrome;

	// output
	cout << ans;
	return 0;
}
