#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int table[8][8] = {0, };
pair<int, int> virus[10];   // -1이 초기값
stack <pair<int, int>> wall_position;
int row_len;
int col_len;
int max_value = -1;


void show(int tmp_table[8][8]) {
	cout << "**********" << endl;
	for (int row = 0; row < row_len; row++) {
		for (int col = 0; col < col_len; col++) {
			cout << tmp_table[row][col] << " ";
		}
		cout << endl;
	}
}

void countregion(int tmp_table[8][8]) {
	queue <pair<int, int>> virus_position ;
	for (int tmp = 0; tmp < 10; tmp++) {
		if (virus[tmp].first != -1) {
			
			virus_position.push({ virus[tmp].first,virus[tmp].second });
		}
		else
			break;
	}
	int tmp_tmp_table[8][8];
	for (int row = 0; row < row_len; row++) {
		for (int col = 0; col < col_len; col++) {
			tmp_tmp_table[row][col] = tmp_table[row][col];
		}
	}
	
	while (!virus_position.empty()) {
		int virus_row = virus_position.front().first;
		int virus_col = virus_position.front().second;
		//cout << "virus_row" << virus_row << "virus_col" << virus_col << endl;

		if ( (virus_row + 1 < row_len) && (tmp_tmp_table[virus_row + 1][virus_col] == 0)) {
			tmp_tmp_table[virus_row + 1][virus_col] = 2;
			virus_position.push({ virus_row + 1,virus_col });
		}
		if ((virus_row > 0) && (tmp_tmp_table[virus_row -1][virus_col] == 0)) {
			tmp_tmp_table[virus_row - 1][virus_col] = 2;
			virus_position.push({ virus_row - 1,virus_col });
		}
		if ((virus_col + 1 < col_len) && (tmp_tmp_table[virus_row][virus_col + 1] == 0)) {
			tmp_tmp_table[virus_row ][virus_col + 1] = 2;
			virus_position.push({ virus_row ,virus_col + 1 });
		}
		if ((virus_col > 0) && (tmp_tmp_table[virus_row][virus_col - 1] == 0)) {
			tmp_tmp_table[virus_row][virus_col - 1] = 2;
			virus_position.push({ virus_row ,virus_col - 1 });
		}
		virus_position.pop();
	}
	
	int result = 0;
	for (int row = 0; row < row_len; row++) {
		for (int col = 0; col < col_len; col++) {
			if (tmp_tmp_table[row][col] == 0) {
				result++;
			}
		}
	}
	
	if (max_value < result)
		max_value = result;
		
}

void makefence(int tmp_table[8][8], int remainwall) {
	
	if (remainwall == 0)
		countregion(tmp_table);
	else {
		for (int row = wall_position.top().first; row < row_len; row++) {
			if (row == wall_position.top().first) {
				for (int col = wall_position.top().second; col < col_len; col++) {
					if (tmp_table[row][col] == 0) {
						wall_position.push({ row,col });
						tmp_table[row][col] = 1;
						makefence(tmp_table, remainwall - 1);
						wall_position.pop();
						tmp_table[row][col] = 0;
					}
				}
			}
			else {
				for (int col = 0; col < col_len; col++) {
					if (tmp_table[row][col] == 0) {
						wall_position.push({ row,col });
						tmp_table[row][col] = 1;
						makefence(tmp_table, remainwall - 1);
						wall_position.pop();
						tmp_table[row][col] = 0;
					}
				}
			}
		}
		
	}
}

int main() {

	
	for (int tmp = 0; tmp < 10; tmp++) {
		virus[tmp].first = -1;
	}
	
	wall_position.push({ 0,0 });


	cin >> row_len;
	cin >> col_len;

	int virus_num = 0;
	for (int row = 0; row < row_len; row++) {
		for (int col = 0; col < col_len; col++) {
			cin >> table[row][col];
			if (table[row][col] == 2) {
				virus[virus_num].first = row;
				virus[virus_num].second = col;
				virus_num++;
			}
		}
	}
	makefence(table, 3);
	
	cout << max_value;

	
}
