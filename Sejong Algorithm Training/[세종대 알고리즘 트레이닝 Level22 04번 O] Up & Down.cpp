#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level22 04번 O] Up & Down
문제:
접근: 
풀이: 
	//1.입력
	//2.명령 수행
	//1)up이면 +1
	//2)down이면 -1
	//3.출력:
	//양수이면 F 몇층
	//0이하이면 -1하고 B붙이기
시간복잡도: O()=
*/
string op;
int cur = 1;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	//1.입력
	//2.명령 수행
	//1)up이면 +1
	//2)down이면 -1
	for (int i = 0; i < 5; i++) {
		cin >> op;
		if (op == "up") {
			cur += 1;
		}
		if (op == "down") {
			cur -= 1;
		}
	}
	//3.출력: 
	//양수이면 F 몇층 
	//0이하이면 -1하고 B붙이기
	if (cur > 0) {
		cout << cur;
	}
	else {
		cur--;
		cur *= -1;
		cout << "B" << cur;
	}
	return 0;
}
