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
[백준 7453 c++ V] 합이 0인 네 정수
문제:
시간복잡도: n*n= 구간합을 구하는 시간 때문
접근: (a,b) (c,d) 두집합의 전체 합의 경우 다 구하기 -> 정렬 → 이분탐색(lower, upper_bound)
풀이:
    //1.입력
    //2.두개의 집합으로 묶기 위해 (a,b) , (c,d)의 각 집합의 합 전체 구하기
    //3.정렬
    //4.이분탐색: 두 집합의 합이 0이되는 구간의 원소갯수 구하기
*/
int n;
int a[4005], b[4005], c[4005], d[4005];
vector<long long> v1, v2;
long long res = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    //2.두개의 집합으로 묶기 위해 (a,b) , (c,d)의 각 집합의 합 전체 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v1.push_back(a[i] + b[j]);
            v2.push_back(c[i] + d[j]);
        }
    }
    //3.정렬
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    //4.이분탐색: 두 집합의 합이 0이되는 구간의 원소갯수 구하기
    int size = v1.size();
    for (int i = 0; i < size; i++) {
        int low = lower_bound(v2.begin(), v2.end(), v1[i] * -1) - v2.begin();
        int high = upper_bound(v2.begin(), v2.end(), v1[i] * -1) - v2.begin();

        res += high - low;
    }
    cout << res << '\n';
    return 0;
}
