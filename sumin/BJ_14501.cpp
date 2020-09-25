
/*
 table[i][j]  : i일부터 j일까지의 발생할 수 있는 최대 비용
 decision day = i + schedule[i][0] - 1 : i번째 일을 하기 전까지의 날짜 >> i일은 없는 셈 치고 decision day전 까지 talbe[i + 1][j] 값을 사용
 decision day에서는 < i번째 일을 한 것 >과 < i번째 일을 안하고 table[i+1][j]를 수행한 것> 을 비교
   1. i번째 일을 했다면 >> 값을 삽입하고 < table[i][decision day -1] + table[decision day -1][j] >와 table[i+1][j]를 비교하며 큰 값을 삽입
   2. i번째 일을 안했더라면 이전 날짜와 동일하므로 table[i+1][j]를 사용
*/


#include <iostream>
using namespace std;

int main() {
	int retire_day = 0;
	int schedule[15][2] = { 0, };  // first element : time , second element : cost
	int table[16][16] = { 0, };
	cin >> retire_day;

	for (int tmp = 0; tmp < retire_day; tmp++) {
		cin >> schedule[tmp][0];
		cin >> schedule[tmp][1];
		if (schedule[tmp][0] + tmp > retire_day) {
			schedule[tmp][0] = 0;
			schedule[tmp][1] = 0;
		}
	}
	for (int i = retire_day - 1; i >= 0; i--) {
		for (int j = i; j < i + schedule[i][0] - 1; j++) {    // 0부터 time 오기 전까지 
			table[i][j] = table[i + 1][j];
		}
		if (schedule[i][1] <= table[i + 1][i + schedule[i][0] - 1]) {     // 지금 스케쥴이 더 클때 ( 이번 일은 영향을 미치지 못한다는 뜻이므로 이전 값들 사용)
			table[i][i + schedule[i][0] - 1] = table[i + 1][i + schedule[i][0] - 1];
			for (int j = i + schedule[i][0]; j < retire_day; j++) {
				table[i][j] = table[i + 1][j];
			}
		}
		else {
			table[i][i + schedule[i][0] - 1] = schedule[i][1];  // 이번 일이 영향을 미침을 의미 
			for (int j = i + schedule[i][0]; j < retire_day; j++) {
				if (table[i][i + schedule[i][0] - 1] + table[i + schedule[i][0]][j] > table[i + 1][j])   // 이번 일을 하고 난 뒤의 값과 이전의 값을 비교..
					table[i][j] = table[i][i + schedule[i][0] - 1] + table[i + schedule[i][0]][j];
				else
					table[i][j] = table[i + 1][j];
			}
		}
	}
	cout << table[0][retire_day-1];
}
