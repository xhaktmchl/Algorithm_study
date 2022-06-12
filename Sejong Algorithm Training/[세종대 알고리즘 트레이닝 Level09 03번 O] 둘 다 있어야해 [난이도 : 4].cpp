#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 03번 O] 둘 다 있어야해 [난이도 : 4]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char ch1, ch2;
char a[10] = "AFGABC";
int cnt1 = 0,cnt2=0;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	cin >> ch1 >> ch2;
	for (int i = 0; i < 6; i++) {
		if (a[i] == ch1) { cnt1++; }
		if (a[i] == ch2) { cnt2++; }
	}

	if (cnt1 >= 1 && cnt2 >= 1) { cout << "와2개"; }
	else if (cnt1 == 0 && cnt2 == 0) { cout << "우0개"; }
	else { cout << "오1개"; }
	return 0;
}
