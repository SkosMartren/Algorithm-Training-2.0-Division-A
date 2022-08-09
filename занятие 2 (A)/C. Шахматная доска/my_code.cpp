#include<iostream>
#include<vector>

using namespace std;

int main() {

	// input
	int N;
	cin >> N;

	vector<pair<int,int>> coordinates_sawn_cells;

	vector<vector<bool>> expanded_chess_field(10, vector<bool>(10, 0));

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		coordinates_sawn_cells.push_back({ x,y });
		expanded_chess_field[x][y] = 1;
	}

	// solution
	int ans = 0;
	
	for (const auto& coordinate : coordinates_sawn_cells) {

		if (expanded_chess_field[coordinate.first - 1][coordinate.second] == 0) {
			++ans;
		}

		if (expanded_chess_field[coordinate.first + 1][coordinate.second] == 0) {
			++ans;
		}

		if (expanded_chess_field[coordinate.first][coordinate.second - 1] == 0) {
			++ans;
		}

		if (expanded_chess_field[coordinate.first][coordinate.second + 1] == 0) {
			++ans;
		}
	}

	// output
	cout << ans;
	return 0;
}
