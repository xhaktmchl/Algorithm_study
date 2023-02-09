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
[백준 2805 c++ VVO] 나무 자르기
문제:
접근1: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 완전탐색 -> 20억 이어서 시간초과
접근2: 최댓값 -> 완탐/그리디/dp/이진탐색 -> 이진탐색 직접구현-> 자르는 길이 low=1, high=최대길이, 하고
시간복잡도: O(log2(m))
풀이: 이분탐색-파라메트릭서치
    //1.입력
    //2.이분탐색-파라메트릭서치: 높이를 mid로 탐색한다
    //중간값
    //자른 나무의 합 구하기
    //1)자른 나무의 합 >= m
    //2)자른 나무의 합 < m
    //3.출력: 최대 높이
*/
int n, m,num;
vector<int> v;
long long sub = 0;
long long maxH = -1;

long long cut(int mid) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sub = v[i] - mid;
        if (sub >= 0) sum += sub;
    }
    return sum;
}

void binary(int start, int end,int tar) {

    while (start <= end) {
        long long mid = (start + end) / 2;

        // 자른 나무의 합 구하기
        long long sum = cut(mid);
        if (sum == tar) {
            maxH = max(maxH, mid);
            return;
        }
        else if (sum > tar) {
            start = mid + 1;
            maxH = max(maxH, mid);
        }
        else end = mid - 1;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    //2.이진탐색: 자를 톱의 높이를 탐색 0~1000000000
    binary(0, 1000000000,m);
    cout << maxH << '\n';
    return 0;
}
