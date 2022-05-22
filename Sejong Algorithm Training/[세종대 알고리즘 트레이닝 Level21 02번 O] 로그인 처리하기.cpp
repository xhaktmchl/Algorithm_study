#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21 02번 O] 로그인 처리하기
문제:
접근: 
풀이:
	//1.입력: 아이디,비번
	//2.일치 확인
	//3.출력:
시간복잡도: O()=
*/
string a, b;
bool flag = 0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력: 아이디,비번
	cin >> a >> b;
	//2.일치 확인
	if(a=="qlqlaqkq" && b=="tkaruqtkf"){
		flag = 1;
	}
	//3.출력: 
	if (flag) { cout << "LOGIN"; }
	else { cout << "INVALID"; }
	return 0;
}
