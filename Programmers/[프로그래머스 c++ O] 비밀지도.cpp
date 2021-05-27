#include <string>
#include <vector>
#include <cstring>

using namespace std;
// [프로그래머스 c++ O] 비밀지도
// 문제: 두 개의 지도의 벽과 공백을 십진수->이진수 해독 후 하나의 지도로 합쳐서 비밀지도 해석 후 문자열 출력
// 접근:  2개의 지도를 해석해서 벽은1 공백은 0으로 1개의 지도배열 합침 -> 비밀지도배열 해석
// 풀이: 
// 2차 비밀지도 배열 0으로 초기화
// 지도1, 지도2 각각 십진수->이진수 변환하며 1인 경우 비밀지도1 대입
// 합쳐진 비밀지도 반복문 탐색하며 1인 경우 tp 스트링에 추가
// 한 행이 완성되면 정답 스트링에 tp추가
// 개념: memset(배열,원소,크기sizeof(배열)) , 헤더#include <cstring>

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int maps[n][n];
    memset(maps, 0, sizeof(maps));

    // arr1
    for (int i = 0; i < n; i++) {
        // 십진수 -> 이진수
        int c = 0;
        while (arr1[i] > 0) {
            if (arr1[i] % 2 == 1) { maps[i][n - 1 - c] = arr1[i] % 2; }
            arr1[i] /= 2; c++;
        }
    }

    // arr2
    for (int i = 0; i < n; i++) {
        // 십진수 -> 이진수
        int c = 0;
        while (arr2[i] > 0) {
            if (arr2[i] % 2 == 1) { maps[i][n - 1 - c] = arr2[i] % 2; }
            arr2[i] /= 2; c++;
        }
    }

    // 완성된 비밀지도 해독
    for (int i = 0; i < n; i++) {
        string tp;
        for (int j = 0; j < n; j++) {
            if (maps[i][j] == 1) { tp.push_back('#'); }
            else { tp.push_back(' '); }
        }
        // 해석된 행 답 문자에 푸쉬
        answer.push_back(tp);
    }
    return answer;
}