#include <string>
#include <vector>
#include <iostream>
using namespace std;
// [프로그래머스 c++ O] JadenCase 문자열 만들기
// 문제: 각 단어의 첫 단어는 대문자, 아니면 소문자인 JadenCase 문자열 만들기
// 접근: 완전탐색-> 문자열 탐색하며 대소문자 변경
// 풀이: 
// 완전탐색으로 첫번째 문자가 소문자 -> 대문자 변경
// 첫문자나 숫자가 아닌데 대문자인 겨웅 -> 소문자 변경
// idx변수로 각 단어의 인덱스를 표현

string solution(string s) {
    string answer = "";
    int idx=0;
    for(int i=0;i<s.size();i++){
        if(idx == 0 && (s[i] >= 'a' && s[i] <= 'z')){ // 완전탐색으로 첫번째 문자가 소문자 -> 대문자 변경
            s[i] = s[i]-32;
        }
        else if(idx != 0 && (s[i] >= 'A' && s[i] <= 'Z')){// 첫문자나 숫자가 아닌데 대문자인 겨웅 -> 소문자 변경
            s[i] = s[i] + 32; 
        }
        idx++;
        if(s[i] == ' '){ idx=0;} // idx변수로 각 단어의 인덱스를 표현
    }
    return answer = s;
}
