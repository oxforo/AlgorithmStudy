/*
	turn 함수는 매개변수로 몇 번 째 톱니바퀴 , 어느 방향 을 받는다.
	즉 해당 톱니바퀴를 주어진 방향으로 돌리는 함수이다.

	우리는 입력이 들어올 때마다, 왼쪽 / 오른쪽으로 순회해나가며
	돌려야되는 톱니바퀴와 방향을 체크해둔다.
	그 후, 한 번에 turn 함수를 이용해 돌린다.
*/
#include<iostream>
#include<string>

using namespace std;

int chain[5][8] = {}, t, a, b;
string input;

void turn(int a, int dir) {
	int temp;
	if (dir == 1) {
		temp = chain[a][7];
		for (int i = 7; i > 0; i--)
			chain[a][i] = chain[a][i - 1];
		chain[a][0] = temp;
	}
	else {
		temp = chain[a][0];
		for (int i = 0; i < 7; i++)
			chain[a][i] = chain[a][i + 1];
		chain[a][7] = temp;
	}
	return;
}

int getScore(void) {
	int ans = 0, mul = 1;
	for (int i = 1; i <= 4; i++) {
		if (chain[i][0] == 1)
			ans += mul;
		mul *= 2;
	}
	return ans;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	for (int i = 1; i <= 4; i++) {
		cin >> input;
		for (int j = 0; j < 8; j++)
			chain[i][j] = (input[j] - '0');
	}

	cin >> t;
	while (t--) {
		cin >> a >> b;
		// 1-2 2-3 3-4 톱니바퀴가 회전해야되는지 체크.
		int direction[5] = {};
		direction[a] = b;
		// 오른쪽 check.
		for (int i = a; i < 4; i++)
			if (chain[i][2] != chain[i + 1][6])
				direction[i + 1] = -direction[i];
		// 왼쪽 check.
		for (int i = a; i > 1; i--) {
			if (chain[i][6] != chain[i - 1][2])
				direction[i - 1] = -direction[i];
		}
		for (int i = 1; i < 5; i++) {
			if (direction[i])
				turn(i, direction[i]);
		}
	}
	cout << getScore() << '\n';

	return 0;
}
