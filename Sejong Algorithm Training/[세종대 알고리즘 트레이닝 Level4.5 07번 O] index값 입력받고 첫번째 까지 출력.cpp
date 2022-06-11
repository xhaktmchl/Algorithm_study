#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level4.5 07번 O] index값 입력받고 첫번째 까지 출력
문제:
접근: 
풀이: 
시간복잡도: O()=
*/
int ar[10] = { 5,7,1,8,-4,-73,4,2,20,84 };
int n;

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

	cin >> n;
	for (int i = n; i>= 0; i--){
		cout << ar[i] << '\n';
	}
    return 0;
}
