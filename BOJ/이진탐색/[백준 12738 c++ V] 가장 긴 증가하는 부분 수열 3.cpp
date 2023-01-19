#include <iostream>
#include <algorithm>
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok
#include <vector>
//#include <queue>
//#include <set> // 트리, 중복 x
//#include <unordered_set>
using namespace std;
/*
[백준 12738 c++ V] 가장 긴 증가하는 부분 수열 3
접근1: DP
dp[i]: i번재 숫자까지의 최장 증가 수열의 길이
dp[i] = max(dp[0] ... dp[i-1])+1
p[i]: i번째 숫자까지의 최장증가수열 바로 전 인덱
시간복잡도: n*n
접근2: 이진탐색
n*n -> nlogn
풀이:
    //1.입력
    //2.lis 배열 만들고 저장
    //lis배열원소가 없거나, 새로들어오는 가장 큰 숫자면 푸쉬
    //아니면 이진탐색으로 자신보다 크거나 같은 수중 가장 첫번째 숫자 자리에 숫자 갱신
    //3.출력: lis 길이
*/
int n;
int a[1000000 + 10];
vector<int> lis;
int len;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(0);
    
    //1.입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //2.lis 배열 만들고 저장
    for (int i = 1; i <= n; i++) {
        
        //lis배열원소가 없거나, 새로들어오는 가장 큰 숫자면 푸쉬
        //아니면 이진탐색으로 자신보다 크거나 같은 수중 가장 첫번째 숫자 자리에 숫자 갱신
        len = lis.size();
        if (len == 0) lis.push_back(a[i]);
        else if (lis[len - 1] < a[i]) lis.push_back(a[i]);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }

    }
    //3.출력: lis 길이
    cout << lis.size() << '\n';
    return 0;
}
