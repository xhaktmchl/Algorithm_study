#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level24 06번 OO] 화학물질 검사장비
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
풀이2:
	//1.입력
	cin >> str;
	//2.모든 문자 소문자로 변경
	//3.pass 문자 탐색
	//find
	//인덱스 -1이면 중단
	//카운트
	//4.fail 문자 탐색
	//find
	//인덱스-1이면 중단
	//카운트
	//5.출력
*/
string str;
int idx = -1,cntP = 0, cntF=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str;
	//2.모든 문자 소문자로 변경
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ('a' - 'A');
		}
	}
	//3.pass 문자 탐색
	//find
	//인덱스 -1이면 중단
	//카운트
	idx = -1;
	while (1) {
		idx = str.find("pass", idx + 1);
		if (idx == -1) {
			break;
		}
		cntP++;
	}
	//4.fail 문자 탐색
	//find
	//인덱스-1이면 중단
	//카운트
	idx = -1;
	while (1) {
		idx = str.find("fail", idx + 1);
		if (idx == -1) {
			break;
		}
		cntF++;
	}
	//5.출력
	cout << (cntP) * 100 / (cntP + cntF) << "%";
	return 0;
}
