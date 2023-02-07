#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
//#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용)
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
#include <cmath>
using namespace std;
/*
[백준 4386 c++ O] 별자리 만들기
문제: 
접근1: 모든 그래프 연결 최소비용 -> MST
시간복잡도: O(n*n/2)
풀이1: MST-크루스칼 -> 간선 구조체 배열 정의
    //1.입력
    //2.좌표를 이용해 간선 생성 후 배열에 저장
    //3.MST-크루스칼(유니온 파인드)
    //1) 부모배열 초기화
    //2)정렬: 간선배열 비용 오름차순
    //3) 유니온 파인드
    //파인드: 같은 집합 아니면
    //유니온: 합집합
풀이2: 풀이1과 같은데 MST-크루스칼 -> 간선 배열을 벡터로 정의, vector<pair<int, pair<int,int>>>
*/
struct ed {
    int n1, n2;
    double dist;
    
    bool operator<(ed& ref) {
        return this->dist < ref.dist;
    }
}Ed[10005];

int n;
double loc[105][3];
int cnt = 0;
int par[105];
double sum = 0;

void init() {
    for (int i = 1; i <= n; i++) par[i] = i;
}

int fin(int node) {
    if (par[node] == node) return node;
    else return par[node] = fin(par[node]); //경로 압축: 시간 단축
}

void uni(int a, int b) {
    int rootA = fin(a);
    int rootB = fin(b);

    if (rootA < rootB) par[rootB] = rootA;
    else par[rootA] = rootB;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    //1.입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> loc[i][0] >> loc[i][1];
    }
    //2.좌표를 이용해 간선 생성 후 배열에 저장
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Ed[cnt].n1 = i; Ed[cnt].n2 = j;
            Ed[cnt++].dist = sqrt( pow(abs(loc[i][0] - loc[j][0]),2) + pow(abs(loc[i][1] - loc[j][1]),2) );
        }
    }
    //3.MST-크루스칼(유니온 파인드)
    //1) 부모배열 초기화
    init();
    //2)정렬: 간선배열 비용 오름차순
    sort(Ed, Ed + cnt);
    //3) 유니온 파인드
    //파인드: 같은 집합 아니면
    //유니온: 합집합
    for (int i = 0; i < cnt; i++) {
        int n1 = Ed[i].n1, n2 = Ed[i].n2;
        double dist = Ed[i].dist;
        if (fin(n1) != fin(n2)) {
            uni(n1, n2);
            sum += dist;
        }
    }
    cout << fixed; cout.precision(2); // cout 소수점 고정
    cout << sum << '\n';
    return 0;
}
