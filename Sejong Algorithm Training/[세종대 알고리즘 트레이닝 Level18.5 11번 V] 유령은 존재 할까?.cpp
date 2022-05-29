#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18.5 11번 V] 유령은 존재 할까?
문제:
접근: 
풀이: 완탐
	//1.입력
	//2.탐색: 문자열 안에 타겟 문자열 있는지
	//있으면 flag=1
	//3.출력:
시간복잡도: O(200)=
개념: str.find(문자열); 
-못 찾으면 string::npos 값 반환
*/
string a;
string tar = "GHOST";

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a;
	//2.탐색: 문자열 안에 타겟 문자열 있는지
	//있으면 flag=1
	if (a.find(tar)==string::npos) {
		cout << "존재하지 않음";
	}
	else { cout << "존재"; }
	//3.출력:
	return 0;
}
