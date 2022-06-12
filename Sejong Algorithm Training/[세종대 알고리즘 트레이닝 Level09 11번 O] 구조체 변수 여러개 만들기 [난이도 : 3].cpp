#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level09 11번 O] 구조체 변수 여러개 만들기 [난이도 : 3]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct Person {
	int age;
	int height;
}P;
int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨
	
	P p1, p2;
	cin >> p1.age >> p1.height >> p2.age >> p2.height;
	int avg1 = (p1.age + p2.age) / 2;
	int avg2 = (p1.height + p2.height) / 2;

	cout << avg1 << " " << avg2;
	return 0;
}
