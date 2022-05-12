#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 04번] 두칸씩 점프하기 O
문제:
접근: 재귀
풀이:
	//1.입력
	//2.재귀(현재 숫자, 횟수 카운트)
	// 기저조건: 만약 3번 카운트면
	// 출력, 중단
	//2) 재귀: 숫자+2
	//출력
시간복잡도: O()=
*/
int n;

void re(int num, int cnt) {
	if (cnt == 3) {
		cout << num << " ";
		return;
	}

	re(num + 2, cnt + 1);
	cout << num << " ";
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
	//1.입력
	cin >> n;
	//2.재귀(현재 숫자, 횟수 카운트)
	// 기저조건: 만약 3번 카운트면 
	// 출력, 중단
	//2) 재귀: 숫자+2
	//출력
	re(n,0);
	return 0;
}
