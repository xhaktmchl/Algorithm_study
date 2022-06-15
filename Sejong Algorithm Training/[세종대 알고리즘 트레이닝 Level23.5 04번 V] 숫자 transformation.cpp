#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level23.5 04번 V] 숫자 transformation
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 각 숫자가 배열에 있는지 탐색
	//1)있으면 idx+=1, idx%=4;
	// 숫자 변환
	//3.출력;
시간복잡도: O()=
*/
int a[5][5] = {
	{3,5,4,1},
	{1,1,2,3},
	{6,7,1,2}
};
int input[5];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	for (int i = 0; i < 4; i++) {
		cin >> input[i];
	}
	//2.완탐: 각 숫자가 배열에 있는지 탐색
	//1)있으면 idx+=1, idx%=4;
	// 숫자 변환
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 4; c++) {
				for (int i = 0; i < 4; i++) {
					if (a[r][c] == input[i]) {
						int idx = i + 1;
						idx %= 4;
						a[r][c] = input[idx];
						break;
					}
				}
			}
		}
	
	//3.출력;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}cout << '\n';
	}
	return 0;
}
