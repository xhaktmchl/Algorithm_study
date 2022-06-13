#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level11 04번 O] 포인터 사용해서 변수 원격조정
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
char a, b, c;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> a >> b >> c;
	char* p1 = &a;
	char* p2 = &b;
	char* p3 = &c;

	*p1+=1;
	*p2+=1;
	(*p3)++;

	cout << a << " " << b << " " << c;
	return 0;
}
