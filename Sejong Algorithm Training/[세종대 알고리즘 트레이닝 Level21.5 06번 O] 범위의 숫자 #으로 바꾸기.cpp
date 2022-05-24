#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 06번 O] 범위의 숫자 #으로 바꾸기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 배열 탐색하며 a,b범위 안이면 # 출력
시간복잡도: O()=
*/
int ar[10][10] = {
	{1,5,3},
	{4,5,5},
	{3,3,5},
	{4,6,2}
};
int a, b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> a >> b;
	//2.완탐: 배열 탐색하며 a,b범위 안이면 # 출력
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (ar[i][j] >= a && ar[i][j] <= b) {
				cout << "# ";
			}
			else { cout << ar[i][j] << " "; }
		}cout << '\n';
	}
	return 0;
}
