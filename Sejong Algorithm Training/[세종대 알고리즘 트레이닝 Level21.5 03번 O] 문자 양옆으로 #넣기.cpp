#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level21.5 03번 O] 문자 양옆으로 #넣기
문제:
접근: 
풀이: 
	//1.입력
	//2.완탐: 문자열 탐색
	//문자 찾으면
	//좌우 인덱스 검사
	//결과 배열에 #저장
	//3.출력
시간복잡도: O()=
*/
string str;
char tar1, tar2;
string result;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> str;
	cin >> tar1 >> tar2;
	//2.완탐: 문자열 탐색
	//문자 찾으면 
	//좌우 인덱스 검사
	//결과 배열에 #저장
	result = str;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == tar1 || str[i] == tar2){
			int lidx = i - 1;
			int ridx = i + 1;
			if (lidx >= 0) {
				result[lidx] = '#';
			}
			if (ridx < len) {
				result[ridx] = '#';
			}
		}
	}
	//3.출력
	cout << result;
	return 0;
}
