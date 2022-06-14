#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level15.5 04번 O] 그가 사는 그집
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int ju[10] = { 402,401,302,301,202,201,102,101 };
char name[8][5] = {
	"KIM",
	"TEA",
	"SOM",
	"OPPO",
	"TOM",
	"GDK",
	"JAME",
	"MIN"
};
int juso,idx=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> juso;
	
	for (int i = 0; i < 8; i++) {
		if (ju[i] == juso) {
			idx = i;
			break;
		}
	}

	for (int i = 0; i < 5; i++) {
		if (name[idx][i] == 0) { break; }
		cout << name[idx][i];
	}
	return 0;
}
