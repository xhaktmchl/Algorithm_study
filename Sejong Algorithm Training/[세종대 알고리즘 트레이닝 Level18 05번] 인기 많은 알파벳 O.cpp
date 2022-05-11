#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 05번] 인기 많은 알파벳 O
문제:
접근: 완탐,
풀이:
시간복잡도: O(n)=8
*/
string a;
int cnt[100];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.완탐: 문자열 탐색, 
	// 대문자 몇번째 인지 숫자
	// 해당 인덱스에 카운트 배열 
	int len = a.size();
	for (int i = 0; i < len; i++) {
		int idx = a[i] - 'A';
		cnt[idx]++;
	}
	//3.출력: 가장 빈도 높은 알파벳 출력
	char maxR = 'A' + (max_element(cnt, cnt + 49) - cnt);
	cout << maxR;
	return 0;
}
