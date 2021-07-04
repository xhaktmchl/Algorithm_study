#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 이상한 문자 만들기
// 문제: 주어진 문자열에서 공백으로 단어를 구분하고 단어의 짝수인덱스는 대문자, 홀수인덱스는 소문자로 변환해라
// 접근: 완전탐색 -> 공백으로 단어 구분하고 단어속에서 대소문자 확인
// 풀이: 
// 완전탐색으로 
// 공백인 경우 확인, 단어속 인덱스 초기화
// 짝수인덱스 소문자->대문자 , 홀수인덱스 대문자 -> 소문자
// 단어속 인덱스 증가
// 정답 문자열 저장
string solution(string s) {
    string answer = "";
    int idx=0; // 각 단어속의 인덱스
    // 완전탐색으로 대소문자 비교
    for(int i=0;i<s.size();i++){
        if(s[i] == ' '){ idx=0; continue;} // 공백이면 단어속 인덱스 초기화
        if(idx%2 ==0 && (s[i] >= 'a' && s[i] <= 'z')) { s[i] -= 32; } // 짝수에서 소문자->대문자
        else if(idx%2 != 0 && (s[i] >= 'A' && s[i] <= 'Z')){ s[i] += 32;} // 홀수에서 대문자 -> 소문자
        idx++;
    }
    // 정답 문자열 저장
    answer = s;
    return answer;
}
