#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
/*
[백준 2143 c++ V] 두 배열의 합
문제:
접근1: A 투포인터 탐색 하면서 B투포인터 탐색으로 총 두 부분합이 T인지 확인
접근2: A,B의 모든 연속 부분합 구해놓고 -> 정렬 -> 이분탐색(합이 T가 되는 경우 찾기)
시간복잡도: n*n
접근3: A,B 각각 누적합 → 두개의 모든 합의 경우 ->정렬 → 이분탐색(lower, upper_bound)
풀이:
    //1.입력
    //2.A 모든 연속 누적합
    //3.B 모든 연속 누적합
    //// A,B 모든 부분합 구하기
    //4.정렬
    //5.이분탐색: 합이 T가 되는 갯수 구하기
*/
long long T;
int n, m;
int a[1010];
long long pSumA[1010];
int b[1010];
long long pSumB[1010];
vector<long long> vA;
vector<long long> vB;
long long res = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //1.입력
    cin >> T;
    cin >> n;
    //2.A 모든 연속 누적합
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pSumA[i] = pSumA[i - 1] + a[i];
    }
    //3.B 모든 연속 누적합
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        pSumB[i] = pSumB[i - 1] + b[i];
    }

    // A,B 모든 부분합 구하기
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vA.push_back(pSumA[j] - pSumA[i]);
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            vB.push_back(pSumB[j] - pSumB[i]);
        }
    }


    //4.정렬
    sort(vA.begin(), vA.end());
    sort(vB.begin(), vB.end());
    //5.이분탐색: 합이 T가 되는 갯수 구하기
    long long size = vA.size();
    for (int i = 0; i < size; i++) {
        int low = lower_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();
        int high = upper_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();

        res += high - low;
    }
    cout << res << '\n';
    return 0;
}
