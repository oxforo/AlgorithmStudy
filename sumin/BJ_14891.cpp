/*
   각 기어의 12시 방향을 기준으로 탐색하는 방법 사용
   각 기어는 이전 상태(old_tewlve_position)을 기준으로 움직이고 새로운 상태 (new_tewlve_position)을 업데이트함
*/

#include <iostream>
using namespace std;
int main() {
	int gear[4][8] = { 0, };
	char str[9] = { 0, };
	int old_tewlve_position[4] = { 0, };
	int new_tewlve_position[4] = { 0, };
	int action_cnt;
	int act_gear;
	int act_direct;
	int reverse_act_direct;

	for (int gear_num = 0; gear_num< 4; gear_num++) {
		cin >> str;
		for (int element_num = 0; element_num < 8; element_num++) {
			gear[gear_num][element_num] = (str[element_num] & 1)%2;
		}
	}
	cin >> action_cnt;

	for (int tmp = 0; tmp < action_cnt; tmp++) {
		cin >> act_gear;
		cin >> act_direct;
		act_gear = act_gear - 1; // index로 변환
		act_direct = (act_direct + 8) % 8;   // act_direct = -1 or 1 = 7 or 1

		if (act_direct == 1) {
			reverse_act_direct = 7;
		}
		else {
			reverse_act_direct = 1;
		}
		//기어의 왼쪽 움직임

		for (int tmp_gear = act_gear; tmp_gear > 0; tmp_gear--) {
			if (gear[tmp_gear - 1][(old_tewlve_position[tmp_gear - 1] + 2) % 8] != gear[tmp_gear][(old_tewlve_position[tmp_gear] + 6) % 8] ) {
				if (((act_gear-tmp_gear) % 2) == 0)
					new_tewlve_position[tmp_gear - 1] = (old_tewlve_position[tmp_gear - 1] + act_direct) % 8;
				else {
					new_tewlve_position[tmp_gear - 1] = (old_tewlve_position[tmp_gear - 1] + reverse_act_direct) % 8;
				}
			}
			else
				break;
			
		}
		//기어의 오른쪽 움직임
		for (int tmp_gear = act_gear; tmp_gear < 3; tmp_gear++) {
			if (gear[tmp_gear][(old_tewlve_position[tmp_gear] + 2) % 8] != gear[tmp_gear + 1][(old_tewlve_position[tmp_gear + 1] + 6) % 8]) {
				if (((tmp_gear - act_gear) % 2) == 0) {
					new_tewlve_position[tmp_gear + 1] = (old_tewlve_position[tmp_gear + 1] + act_direct) % 8;				
				}

				else {
					new_tewlve_position[tmp_gear + 1] = (old_tewlve_position[tmp_gear + 1] + reverse_act_direct) % 8;
				}	
			}
			else
				break;
		}
		new_tewlve_position[act_gear] = (old_tewlve_position[act_gear] + reverse_act_direct) % 8;

		for (int element = 0; element < 4; element++) {
			old_tewlve_position[element] = new_tewlve_position[element];
		}
	}
	cout << gear[0][new_tewlve_position[0]%8] + 2*gear[1][new_tewlve_position[1] % 8] + 4*gear[2][new_tewlve_position[2] % 8] + 8* gear[3][new_tewlve_position[3] % 8];
}
