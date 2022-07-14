#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
/*
[세종대 알고리즘 트레이닝 수업0714 04번 V] 액체괴물 놀이
문제:
접근:
풀이: 구현, 정렬
	//1.입력
	//2.정렬
	//3.완탐: 2개씩 합
	//소요시간 추가
	//배열에 무게 갱신
	//4.출력: 최소시간
시간복잡도: O()=
*/
int n, t = 0, sum = 0;
int a[5010];

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//반복
	sum = 0;
	t = 0;
	for (int i = 0; i < n - 1; i++) {
		//2.오름차순 정렬
		sort(a + i, a + n);
		//3.앞에 두개 숫자 합침
		sum = a[i] + a[i + 1];//4.무게증가
		a[i + 1] = sum;//배열 적용
		t += sum;// 시간 증가
	}

	//5.출력
	cout << t << '\n';
	return 0;
}
