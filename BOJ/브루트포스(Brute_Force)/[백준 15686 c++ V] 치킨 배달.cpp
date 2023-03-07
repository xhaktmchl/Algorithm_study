#include <iostream>
#include <algorithm> // fill_n, min,max, swap
//#include <map> // 중복 x 
//#include <string> // getline
//#include <cstring> // memset, strok, strstr
#include <vector>
//#include <queue> // priority_queue<자료형, 구현체, 비교 연산자> (중복허용), 
//#include <set> // 트리, 중복 x , multiset
//#include <unordered_set>
#include <cmath>
using namespace std; // lower_bound, upper_bound
/*
[백준 15686 c++ V] 치킨 배달 
문제:
접근: 완탐, 조합(next_permutation)
시간복잡도: O()
풀이:
    //1.입력
    //2.조합 완탐 재귀: 살릴 m개의 치킨집 조합
    //1) m개의 치킨집 선택
    //2) 도시 치킨거리 구하기
    //모든 집의 치킨거리 구하고, 합하기
    //3)최솟값 갱신
*/
int n, m;
int ma[55][55];
vector<pair<int, int>> vhome;
vector<pair<int, int>> vchick;
vector<int> sel_chi;
int minChi = 10000;
int minCityChi = 10000, sum;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);

    //1.입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ma[i][j];
            if (ma[i][j] == 1) vhome.push_back({ i, j });
            if (ma[i][j] == 2) vchick.push_back({ i,j });
        }
    }
    //2.조합 완탐 재귀: 살릴 m개의 치킨집 조합
    //1)m개의 치킨집 선택
    int size = vchick.size();
    for (int i = 0; i < size - m; i++) sel_chi.push_back(0);
    for (int i = size - m; i < size; i++) sel_chi.push_back(1);

    do {
        //2) 도시 치킨거리 구하기
        //모든 집의 치킨거리 구하고, 합하기
        int hsize = vhome.size();
        sum = 0;
        for (int i = 0; i < hsize; i++) {
            minChi = 10000;// 각 집의 치킨거리 초기화
            for (int j = 0; j < size; j++) {
                if (sel_chi[j] == 1) {
                    int dist = abs(vchick[j].first - vhome[i].first) + abs(vchick[j].second - vhome[i].second);
                    minChi = min(minChi, dist);

                }
            }

            sum = sum + minChi; // 도시치킨거리
        }
        //3)최솟값 갱신
        minCityChi = min(minCityChi, sum); // 최소 도시치킨거리 갱신
    } while (next_permutation(sel_chi.begin(), sel_chi.end()));

    cout << minCityChi << '\n';
    return 0;
}
