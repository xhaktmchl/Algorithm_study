#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level16 03번] 문장 A 추가하기 O
문제: 
접근: 
풀이: 
시간복잡도: 
*/
string str,result, tp;
int idx;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.입력
	cin >> str>>idx;
	// 2.A추가
	int len = str.size();
	tp = str.substr(0, idx);
	tp = tp + 'A';
	tp += str.substr(idx, len);

	// 3.출력
	cout << tp << '\n';
	return 0;
}
