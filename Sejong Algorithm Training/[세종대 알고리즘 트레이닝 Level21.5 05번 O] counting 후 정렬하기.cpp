#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 05번 O] counting 후 정렬하기
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.완탐: 숫자 갯수 카운팅
	// bucket[숫자]에 카운트
	//3.출력: bucket[idx] 에 갯수 만큰 idx출력
시간복잡도: O()=
*/
int vect[10], bucket[15];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	for (int i = 0; i < 8; i++) {
		cin >> vect[i];
	}
	//2.완탐: 숫자 갯수 카운팅
	// bucket[숫자]에 카운트
	for (int i = 0; i < 8; i++) {
		bucket[vect[i]]++;
	}
	//3.출력: bucket[idx] 에 갯수 만큰 idx출력
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < bucket[i]; j++) {
			cout << i << " ";
		}
	}
	return 0;
}
