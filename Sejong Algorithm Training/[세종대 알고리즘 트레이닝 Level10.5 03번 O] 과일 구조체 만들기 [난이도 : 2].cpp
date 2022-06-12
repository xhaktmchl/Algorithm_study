#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level10.5 03번 O] 과일 구조체 만들기 [난이도 : 2]
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
typedef struct Fruit {
	int size;
	int price;
}F;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	F banana, apple;
	cin >> banana.size >> apple.size;
	cout << banana.size * 250 + apple.size * 500 << "원";
	return 0;
}
