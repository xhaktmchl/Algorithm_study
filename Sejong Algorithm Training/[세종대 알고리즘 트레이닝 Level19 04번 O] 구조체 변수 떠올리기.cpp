#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level19 04번 O] 구조체 변수 떠올리기
문제:
접근: 구현
풀이:
시간복잡도: O()=
*/
typedef struct Data {
	int x;
	int y;
	int z;
}D;

D a, b;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	//1.입력
	cin >> a.x >> a.y >> a.z;
	cin >> b.x >> b.y >> b.z;
	//2.출력:
	cout << a.x + b.x<<'\n';
	cout << a.y + b.y<<'\n';
	cout << a.z + b.z << '\n';
	return 0;
}
