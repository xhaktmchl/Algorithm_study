#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level20 05번] 다섯글자 순차역순으로 출력 O
문제:
접근: 재귀
풀이:
	//1.입력
	//2.재귀(idx)
	//1)기저조건: 4인덱스이면
	//출력 , 중단
	//2) 현재 문자 출력
	//3) 재귀 idx+1
	//4) 현재 문자 출력
시간복잡도: O()=
*/
string str;

void re(int idx) {
	if (idx == 4) {
		cout << str[idx] << '\n';
		cout << str[idx];
		return;
	}

	cout << str[idx];
	re(idx + 1);
	cout << str[idx];
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
    
	//1.입력
	cin >> str;
	//2.재귀(idx)
	//1)기저조건: 4인덱스이면 
	//출력 , 출력 , 중단
	//2) 현재 문자 출력
	//3) 재귀 idx+1
	//4) 현재 문자 출력
	re(0);
	return 0;
}
