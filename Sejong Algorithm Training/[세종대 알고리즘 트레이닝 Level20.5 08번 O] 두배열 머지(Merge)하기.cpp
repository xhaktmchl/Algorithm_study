#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 08번 O] 두배열 머지(Merge)하기
문제:
접근: 완탐
풀이:
	//1.입력:두 배열
	//2.완탐: 반복 2n 두 배열 0인덱스에서 각자 출발
	// 1)인덱스 4이상이면 중단
	// 첫 배열이 더 크면 그 원소 정답배열에 추가, 인덱스 ++
	// 둘째 배열이 더 크면 그 원소 정답배열에 추가, 인덱스 ++
	//3.두 배열 중 남은 것 모두 배열에 추가
	//4.출력: 정렬 머지 배열
시간복잡도: O(r*c)=
*/
int a[10], b[10];
int idx1 = 0, idx2 = 0;
vector<int> result;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력:두 배열
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
	}
	//2.완탐: 반복 2n 두 배열 0인덱스에서 각자 출발
	// 1)인덱스 4이상이면 중단 
	// 첫 배열이 더 크면 그 원소 정답배열에 추가, 인덱스 ++
	// 둘째 배열이 더 크면 그 원소 정답배열에 추가, 인덱스 ++
	while (1) {
		if (idx1 >= 4 || idx2 >= 4) { break; }
		if (a[idx1] <= b[idx2]) {
			result.push_back(a[idx1++]);
		}
		else if (a[idx1] > b[idx2]) {
			result.push_back(b[idx2++]);
		}
	}
	//3.두 배열 중 남은 것 모두 배열에 추가
	if (idx1 < 4) {
		for (int i = idx1; i < 4; i++) {
			result.push_back(a[i]);
		}
	}
	if (idx2 < 4) {
		for (int i = idx2; i < 4; i++) {
			result.push_back(b[i]);
		}
	}
	//4.출력: 정렬 머지 배열
	for (int i = 0; i < 8; i++) {
		cout << result[i] << " ";
	}
	return 0;
}
