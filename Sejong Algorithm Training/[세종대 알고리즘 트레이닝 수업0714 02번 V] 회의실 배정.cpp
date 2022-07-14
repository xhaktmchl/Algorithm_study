#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0714 02번 V] 회의실 배정
문제:
접근:
풀이: 그리디
	//1.입력
	//2.끝나는 시간 정렬
	//3.그리디탐색: 끝나는 시간 젤 빠른 것 부터 시작시간이 전 끝나는 시간보다 뒤이면
	// 끝나는 시간 갱신
	//카운트
시간복잡도: O()=
*/
typedef struct Time {
	int a, b;
}T;
int n;
T t[100010];

bool cmp(T l, T r) {
	if (l.b < r.b) return 1;
	else return 0;
}

int finish = 0;
int cnt = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i].a >> t[i].b;
	}
	//2.끝나는 시간 정렬
	sort(t + 0, t + n, cmp);
	//3.그리디탐색: 끝나는 시간 젤 빠른 것 부터 시작시간이 전 끝나는 시간보다 뒤이면
	// 끝나는 시간 갱신
	//카운트
	for (int i = 0; i < n; i++) {
		if (t[i].a >= finish) {
			finish = t[i].b;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
