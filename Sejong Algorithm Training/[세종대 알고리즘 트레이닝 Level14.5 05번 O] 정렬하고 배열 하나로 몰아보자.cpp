#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level14.5 05번 O] 정렬하고 배열 하나로 몰아보자
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
string a, b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	string result = a + b;
	cout << result;
	return 0;
}
