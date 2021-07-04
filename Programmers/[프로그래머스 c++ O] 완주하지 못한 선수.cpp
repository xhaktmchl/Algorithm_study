#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ O] 완주하지 못한 선수
// 문제: 두개의 문자열 배열을 받고 빠져있는 1개 이름 찾기
// 접근: 두 백터를 정렬시킨 후 완전탐색 비교 -> 서로 다른 이름의 인덱스가 비완주자 인덱스
// 풀이: 
// 두 배열 정렬
// 완전탐색으로 다른지 비교
// 비완주자 이름 저장 (비완주자가 맨 뒤에 있는 경우 , 아닌 경우)

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // 정렬시킨 후 비교
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    int idx=-1; // 다른 이름 인덱스
    for(int i=0;i<completion.size();i++){ // 완전탐색으로 비교
        if(participant[i] != completion[i]){idx=i; break;}
    }
    if(idx == -1){answer+=participant[participant.size()-1];} // 비완주자가 마지막인 경우
    else { answer+= participant[idx];} // 아닌경우
    return answer;
}
