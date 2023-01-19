#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
#include <cstring> // memset, strok
#include <vector>
#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 14003 c++ X] 가장 긴 증가하는 부분 수열 5
접근1: LIS: DP
dp[i]: i번재 숫자까지의 최장 증가 수열의 길이
dp[i] = max(dp[0] ... dp[i-1])+1
p[i]: i번째 숫자까지의 최장증가수열 바로 전 인덱
접근2: LIS: dp+ 이진탐색
시간복잡도: nlogn
풀이:
    //1.입력
    //2.dp, lis길이배열,
    //3.출력: lis길이, lis 배열
*/
int n,len;
int a[1000000 + 10];
vector<int> lisLen;
int dp[1000000 + 10];
int maxdp = -1;
vector<int> lisAr;
int curIdx, dptp=-1;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);

    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    //2.dp, lis길이배열, 
    for (int i = 1; i <= n; i++) {
        
        //1)lis길이배열 채우기
        //2) lis dp배열 저장
        len = lisLen.size();
        if (len == 0) {
            lisLen.push_back(a[i]);
            len += 1;
        }
        else if (lisLen[len - 1] < a[i]) {
            lisLen.push_back(a[i]);
            len += 1;
        }
        else {
            auto it = lower_bound(lisLen.begin(), lisLen.end(), a[i]);
            *it = a[i];
            len = it - lisLen.begin()+1;
        }
        dp[i] = len;
        if (dp[i] > dptp) {
            curIdx = i;
            dptp = dp[i];
        }
    }
    //3.출력: lis길이, lis 배열
    cout << lisLen.size() << '\n';
    // lis 배열 추출
    lisAr.push_back(a[curIdx]);
    for (int i = curIdx - 1; i >= 1; i--) {
        if (a[i] < a[curIdx] && dp[i] + 1 == dp[curIdx]) {
            lisAr.push_back(a[i]);
            curIdx = i;

        }
    }
    len = lisAr.size();
    for (int i = len-1; i >= 0; i--) {
        cout << lisAr[i] << " ";
    }
    return 0;
}
