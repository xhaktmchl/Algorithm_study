#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 07번 O] 몇번째 행운
문제:
접근: 
풀이: 완탐재귀
	//1.입력
	//2.재귀
	//1)기저조건: 만약 3번째 충이면
	//카운트
	//중단
	//2)재귀:ABCD
시간복잡도: O()=
*/
string target;
int cnt = 0;
string path;

void re(int lv) {
	if (lv == 3) {
		cnt++;
		if (path == target) {
			cout << cnt << "번째";
		}
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		path += 'A' + i;
		re(lv + 1);
		path.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	cin >> target;
	//2.재귀
	//1)기저조건: 만약 3번째 충이면
	//카운트
	//중단
	//2)재귀:ABCD
	re(0);
	return 0;
}
