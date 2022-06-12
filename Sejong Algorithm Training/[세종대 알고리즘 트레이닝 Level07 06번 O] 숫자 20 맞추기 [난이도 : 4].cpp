#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level07 06번 O] 숫자 20 맞추기 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int n;


int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	for (int i = 0; i < 4; i++) {
		cin >> n;
		if (n == 20) { cout << "정답입니다"<<'\n'; }
		else if (n > 20) { cout << "더 작은수를 입력하세요"<<'\n'; }
		else if (n < 20) { cout << "더 큰수를 입력하세요"<<'\n'; }
	}
    return 0;
}
