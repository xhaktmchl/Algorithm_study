#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14 07번 O] 선택정렬하기
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
vector<int> v;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 6; i++) {
		int tp;
		cin >> tp;
		v.push_back(tp);
	}

	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < 6; i++) {
		cout << v[i];
	}
	return 0;
}
