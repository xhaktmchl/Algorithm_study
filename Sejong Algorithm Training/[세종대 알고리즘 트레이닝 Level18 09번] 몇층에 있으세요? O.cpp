#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
[세종대 알고리즘 트레이닝 Level18 09번] 몇층에 있으세요? O
문제:
접근: 완탐,
풀이:
시간복잡도: O()=
*/
int apt[5][3] = {
    {15, 18, 17},
    {4, 6, 9},
    {10, 1, 3},
    {7, 8, 9},
    {15, 2, 6}
};
int family[5];
int cnt = 0, result = 0;

// y층에 family 세대가 일치하면 1, 아니면 0을 반환
int isPattern(int y) {
    cnt = 0;
    for (int j = 0; j < 3; j++) {
        if (apt[y][j] == family[j]) {
            cnt++;
        }
    }
    if (cnt == 3) {
        return 1;
    }
    else return 0;
}

int main() {
	ios::sync_with_stdio(false); // 계산시간 단축 // cin,scanf 같이 쓰면 오류
	cin.tie(nullptr); cout.tie(nullptr);// 입출력 시간 단축 // 이것을 쓰면 scanf,printf섞어 쓰면 안됨

    //1.입력
    for (int i = 0; i < 3; i++) {
        cin >> family[i];
    }
    //2.완탐: 아파트 각 층 마다 3개의 호수 일치 확인
    //맞으면 중단
    for (int i = 0; i <5; i++) {
        if (isPattern(i) == 1) {
            result = 5-i;
            break;
        }
    }
    //3.출력: 층
    cout << result << "층";
	return 0;
}
