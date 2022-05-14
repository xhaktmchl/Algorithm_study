#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[백준 4673 c++ O] 셀프 넘버
문제:
접근: 
풀이:
	//1.완탐 재귀
	//1)만약 체크 안되어 있으면 셀프넘버에 추가
	//2)1~10000까지 각 수에서 셀프넘버 확인 재귀 탐색
	//기저조건: 만약 num이 10000보다 크거나 같으면 중단
	//체크 표시
	//숫자의 각 자릿수 추출 후 합
	//재귀: 합한 수 넘겨줌
	//2.출력; 셀프넘버 배열 출력
시간복잡도: O()=
*/
bool self[10010];
bool check[10010];
string str;

void re(int num) {
	if (num >= 10000) {
		return;
	}
	
	check[num] = 1;
	str = to_string(num);
	for (int i = 0; i < str.size(); i++) {
		num += (str[i] - '0');
	}
	re(num);
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	//1.완탐 재귀
	//1)만약 체크 안되어 있으면 셀프넘버에 추가 
	//2)1~10000까지 각 수에서 셀프넘버 확인 재귀 탐색
	//기저조건: 만약 num이 10000보다 크거나 같으면 중단
	//체크 표시
	//숫자의 각 자릿수 추출 후 합
	//재귀: 합한 수 넘겨줌
	for (int i = 1; i < 10000; i++) {
		if (check[i] == 0) {
			self[i] = 1;
			re(i);
		}
	}
	//2.출력; 셀프넘버 배열 출력
	for (int i = 1; i < 10000; i++) {
		if (self[i] == 1) {
			cout << i << '\n';
		}
	}
	return 0;
}
