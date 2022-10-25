#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝_22-2 05회차 04번 백준 13458 c++ V] 시험 감독
문제: 
접근: 총감독관은 각 시험관 마다 반드시 1명씩 존재한다.
시험 감독의 최소 수를 구하기 위해선 시험감독관이 관리하는 인원으로 학생을 나누면 된다 풀이:
풀이:
	//1.입력
	//a,b,c
	//2.완탐: a 각 학생 수에서
	//총감독관 관리인원 제외
	//2)만약 학생이 남았다면 부감독관으로 남은학생 나누기
	//나누어 떨어진다면 cnt++
	//아니라면 cnt+2
	//3.출력: 최소 감독관
시간복잡도: O()=
개념:
주의:
총 시험자수는 100만 * 100만 이어서 감독관 수는 int가 아닌 long long 으로 해야한다.
*/
int n,b,c;
int a[1000010];
long long res = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	//a,b,c
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	//2.완탐: a 각 학생 수에서
	//총감독관 관리인원 제외
	//2)만약 학생이 남았다면 부감독관으로 남은학생 나누기
	//나누어 떨어진다면 cnt++
	//아니라면 cnt+2
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		res++;
		if (a[i] < 0) { continue; }

		if (a[i] % c == 0) {
			res += a[i] / c;
		}
		else {
			res += a[i] / c;
			res += 1;
		}
	}
	//3.출력: 최소 감독관
	cout << res << '\n';
	return 0;
}
