#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ O] K번째수
// 문제: 명령마다 원하는 인덱스 범위 벡터원소 정렬 후 원하는 위치의 원소 추출
// 접근: 일반 반복하면서 sort 를 이용해 정렬후 정답 배열에 추가하기
// 풀이: 
// commands 의 크기만큼 반복
// 숫자배열 변경방지 복사
// sort이용해서 commands에서 정렬 시작위치 끝 위치 정렬
// 원하는 위치 숫자 정답 배열에 추가
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    // 명령의 갯수만큼 명령 실행
    for(int i=0;i<commands.size();i++){
        vector<int> tp=array;
        sort(tp.begin()+commands[i][0]-1,tp.begin()+commands[i][1]); // 원하는 범위 정렬
        answer.push_back(tp[commands[i][0]-1+commands[i][2]-1]); // 원하는 위치 원소 정답 배열에 추가
    }
    return answer;
}
