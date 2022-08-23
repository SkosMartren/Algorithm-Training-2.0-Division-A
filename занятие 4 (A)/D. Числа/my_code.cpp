#include<iostream>
#include<vector>
#include<algorithm> // min

using namespace std;

void reading_symbols(const string& s, vector<int>& symbols_A) {

	for (const auto chr : s) {
		++symbols_A[chr - '0'];
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
	// Вывод мне не нравится - я бы сначала создал строчку / массив цифр для вывода
//Потом уже вне цикла сравнил бы первый символ вывода с 0 - если 0, то вывел бы один ноль, иначе весь вектор
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
