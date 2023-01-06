#include <iostream>
#include <algorithm>
using namespace std;
/*
[백준 21318 c++ V] 피아노 체조
문제:
접근1: 완탐 -> 시간 초과
접근2: 누적합-> 구간 까지의 실수 갯수 저장
시간복잡도: O(n)
풀이:
    //1.입력
    //2.누적합: 실수한 곡의 갯수
    //만약 a[i] > a[i+1] 이라면 실수+1
    //아니라면 그대로
    //3.q번 구간합 구하기
*/
int n,q,s,e;
int a[100010];
int psum[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    //1.입력
    cin >> n;
    //2.누적합: 실수한 곡의 갯수
    //만약 a[i] > a[i+1] 이라면 실수+1
    //아니라면 그대로
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        
        if (a[i] < a[i - 1]) psum[i] = psum[i - 1] + 1;
        else psum[i] = psum[i - 1];
    }
    //3.q번 구간합 구하기
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> s >> e;

        cout << psum[e] - psum[s] << '\n';
    }
    return 0;
}  
