#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09.5 02번 O] Index 찾아내기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a[10];
int cnt = 0;
bool visit[10];


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < 5; i++) {
		if (a[i] == 'A') { 
			cnt++;
			visit[i] = 1;
		}
	}

	cout << "문자A는 " << cnt << "개발견" << '\n';
	for (int i = 0; i < 5; i++) {
		if (visit[i] == 1) { cout << i << "번" << '\n'; }
	}
	return 0;
}
