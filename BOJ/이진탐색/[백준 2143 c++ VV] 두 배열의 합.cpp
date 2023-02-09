#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 2143 c++ VV] 두 배열의 합
문제:
접근1: A 투포인터 탐색 하면서 B투포인터 탐색으로 총 두 부분합이 T인지 확인
접근2: A,B의 모든 연속 부분합 구해놓고 -> 정렬 -> 이분탐색(합이 T가 되는 경우 찾기)
시간복잡도: n*n= 구간합을 구하는 시간 때문
접근3: A,B 각각 누적합 → 두개의 모든 합의 경우 ->정렬 → 이분탐색(lower, upper_bound)
풀이:
    //1.입력
    //2.A의 모든 연속 누적합
    //3.B의 모든 연속 누적합
    //3.A,B의 모든 구간합 구하기
    //4.정렬
    //5.이분탐색: A,B의 구간합이 T가 되는 경우의 수 구하기
*/
int T,n,m;
int a[1005], b[1005];
int pSumA[1005], pSumB[1005];
vector<int> vA, vB;
long long res = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> T;
    //2.A의 모든 연속 누적합
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pSumA[i] = pSumA[i - 1] + a[i];
    }
    //3.B의 모든 연속 누적합
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        pSumB[i] = pSumB[i - 1] + b[i];
    }
    //3.A,B의 모든 구간합 구하기
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
    //5.이분탐색: A,B의 구간합이 T가 되는 경우의 수 구하기
    int size = vA.size();
    for (int i = 0; i < size; i++) {
        int low = lower_bound(vB.begin(), vB.end(), T - vA[i])-vB.begin();
        int high = upper_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();
        
        res += high - low;
    }
    cout << res << '\n';
    return 0;
}
