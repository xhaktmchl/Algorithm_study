#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20.5 02번 O] 앞으로 돌진하는 계단
문제:
접근:
풀이:
	//1.입력
	//2.인데그 /2 기준으로 나누어서 저장
	//3.출력: 같은지 비교
시간복잡도: O()=
*/
string a;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> a;
	//2.인데그 /2 기준으로 나누어서 저장
	string b, c;
	for (int i = 0; i < a.size(); i++) {
		if (i >= 0 && i < a.size() / 2) {
			b += a[i];
		}
		else {
			c += a[i];
		}
	}
	//3.출력: 같은지 비교
	if (b == c) { cout << "동일한문장"; }
	else { cout << "다른문장"; }
	return 0;
}
