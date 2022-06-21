#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 06번 O] 화학물질 검사장비
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 각 문자열 탐색
	//인덱스에서 +3까지 탐색
	//만약 pass 이면 패스 카운트
	//만약 fail이면 패일 카운트
	//3.출력:비율
시간복잡도: O()=
*/
string str;
int idx = -1,cntP = 0, cntF=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str;
	//2.완탐: 각 문자열 탐색
	//인덱스에서 +3까지 탐색
	//만약 pass 이면 패스 카운트
	//만약 fail이면 패일 카운트
	int len = str.size();
	for (int i = 0; i < len-3; i++) {
		if ((str[i] == 'P' || str[i] == 'p') && (str[i + 1] == 'A' || str[i + 1] == 'a') && (str[i + 2] == 'S' || str[i + 2] == 's') && (str[i + 3] == 'S' || str[i + 3] == 's')) {
			cntP++;
		}
		if ((str[i] == 'F' || str[i] == 'f') && (str[i + 1] == 'A' || str[i + 1] == 'a') && (str[i + 2] == 'I' || str[i + 2] == 'i') && (str[i + 3] == 'L' || str[i + 3] == 'l')) {
			cntF++;
		}
	}
	//3.출력:비율
	cout << (cntP)*100 / (cntP + cntF) << "%";
	return 0;
}
