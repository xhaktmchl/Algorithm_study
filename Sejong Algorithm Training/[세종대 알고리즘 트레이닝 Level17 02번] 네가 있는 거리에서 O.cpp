#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level17 02번] 네가 있는 거리에서 O
문제:
접근:
풀이:
시간복잡도: O(n)
*/
int ar[10] = { 5,9,4,6,1,5,8,9 };
int index, target, offset = 0;;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> index >> target;
	//2.index부터 오른쪽으로 배열 완탐
	// offset 계산
	for (int i = index; i < 8; i++) {
		offset = i - index;
		if (ar[i] == target) {
			break;
		}
	}
	//3.출력
	cout << offset << '\n';
	return 0;
}
