#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
using namespace std;
/*
[백준 14476 c++ V] 최대공약수 하나 빼기
문제:
접근: 
시간복잡도: n
풀이:1 유클리드호제+ 누적합
    //1.입력
    //2.왼 -> 오 최대공약수 누적
    //3.오 -> 왼 최대공약수 누적
    //4.i번재 수를 뺏을 때 최대공약수의 최댓값 구하기
    //1) 0번째를 뺀 경우
    //2) n-1번째를 뺀 경우
    //3) 1~n-2 번째를 뺀 경우
    //5.출력:
*/
int n,k;
int ar[1000000 + 10];
int L2R[1000000 + 10];
int R2L[1000000 + 10];
int maxGcd = 0;

// 유클리드 호제법: 최대 공약수 구하기
int gcd(int a, int b) {
    if (a < b) {
        int tp = a;
        a = b;
        b = tp;
    }

    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    //2.왼 -> 오 최대공약수 누적
    L2R[0] = ar[0];
    for (int i = 1; i < n; i++) {
        L2R[i] = gcd(L2R[i - 1], ar[i]);
    }
    //3.오 -> 왼 최대공약수 누적
    R2L[n - 1] = ar[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        R2L[i] = gcd(R2L[i + 1], ar[i]);
    }
    //4.i번재 수를 뺏을 때 최대공약수의 최댓값 구하기
    //1) 0번째를 뺀 경우
    //2) n-1번째를 뺀 경우
    //3) 1~n-2 번째를 뺀 경우
    //5.출력:
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (maxGcd < R2L[1] && ar[i]%R2L[1]!=0) {
                maxGcd = max(maxGcd, R2L[1]);
                k = ar[i];
            }
        }
        else if (i == n - 1) {
            if (maxGcd < L2R[1] && ar[i]%L2R[n-1-1]!=0) {
                maxGcd = max(maxGcd, L2R[n-1-1]);
                k = ar[i];
            }
        }
        else {
            int gcdN = gcd(L2R[i - 1], R2L[i + 1]);
            if (maxGcd < gcdN && ar[i]%gcdN!=0) {
                maxGcd = max(maxGcd, gcdN);
             
                k = ar[i];
            }
        }
    }
    if (maxGcd == 0) cout << -1 << '\n';
    else cout << maxGcd << " " << k;
    return 0;
}
