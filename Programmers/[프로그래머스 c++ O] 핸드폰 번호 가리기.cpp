#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 핸드폰 번호 가리기
// 문제: 
// 접근: 
// 풀이:
// 개념:
// 문자열 뒤에 문자열 추가할 때 : string + "문자" 
string solution(string phone_number) {
    string answer = "";
    
    for(int i=0;i<phone_number.size();i++){
        if(i < phone_number.size()-4){ answer+= "*";}
        else { answer += phone_number[i];}
    }
    return answer;
}
