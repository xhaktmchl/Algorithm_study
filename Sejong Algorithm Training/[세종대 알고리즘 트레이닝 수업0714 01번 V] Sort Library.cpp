#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0714 01번 V] Sort Library
문제:
접근:
풀이: 
	//1.숫자 오름차순
	//2.숫자 내림차순
	//3.type3 조건 정렬
시간복잡도: O()=
*/
typedef struct Type {
	int a;
	char ch;

}T;

int n;
T t[100010];

bool cmp1(T l, T r) {
	//2.숫자 오름차순
	if (l.a < r.a) return true;
	else return false;
}

bool cmp2(T l, T r) {
	//2.숫자 내림차순
	if (l.a > r.a) return true;
	else return false;
}

bool cmp3(T l, T r) {
	//1.짝수 우선
	if (l.a % 2 == 0 && r.a % 2 == 1) return true;
	if (l.a % 2 == 1 && r.a % 2 == 0) return false;

	//2.숫자 오름차순
	if (l.a < r.a) return true;
	if (l.a > r.a) return false;

	//3.문자 오름차순
	if (l.ch < r.ch) return true;
	if (l.ch > r.ch) return false;

	return false;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i].a;
	}
	for (int i = 0; i < n; i++) {
		cin >> t[i].ch;
	}

	//1.숫자 오름차순
	sort(t + 0, t + n,cmp1);
	for (int i = 0; i < n; i++) {
		cout << t[i].a << " ";
	}cout << '\n';
	//2.숫자 내림차순
	sort(t + 0, t + n, cmp2);
	for (int i = 0; i < n; i++) {
		cout << t[i].a << " ";
	}cout << '\n';
	//3.type3 조건 정렬
	sort(t + 0, t + n, cmp3);
	for (int i = 0; i < n; i++) {
		cout << t[i].a << " ";
	}cout << '\n';
	for (int i = 0; i < n; i++) {
		cout << t[i].ch << " ";
	}
	return 0;
}
