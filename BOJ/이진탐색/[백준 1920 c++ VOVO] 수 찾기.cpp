#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
//#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 1920 c++ VOVO] 수 찾기
문제:
접근1: 벡터에서 find 로 숫자 찾기 -> 맞음 근데 이진탐색보다 느림
접근2: binary_search 함수로 원소 찾기 -> 일반 find보다 빠름
접근3: 이진탐색 직접 구현
시간복잡도: mlog2(n)
풀이:
    //1.입력
    //2.정렬
    //3.이진탐색: m개의 수 있는지 판별
    //출력: 있으면 1 없으면 0
*/
int n,num,m;
vector<int> v;

int binarySearch(int start, int end, int tar) {

    while (start <= end) {
        int mid = (start + end)/2;
        
        if (v[mid] == tar) return mid;
        else if (v[mid] > tar) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if (binarySearch(0,n-1,num) != -1) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
