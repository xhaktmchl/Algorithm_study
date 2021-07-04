#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ V] 문자열 내 마음대로 정렬하기
// 문제: 문자열 배열을 받아서 원하는 인덱스의 문자를 기준으로 정렬하기, 같은 문자면 문자열 사전순으로 정렬
// 접근: sort에 인덱스 문자별 순서와 ,같은문자의 사전순서 정의함수 만들어서 넣어줌
// 풀이: 
// 문자열 배열 sort
// 사용자 정의 함수mysort : 다른 문자면 해당 인덱스 문자의 순서 부울 반환 / 같은 문자면 문자열의 순서 반환
// 정렬된 배열 저장
// 개념:
//sort(v.begin(), v.end());
//sort(v.begin(), v.end(),compare);//사용자 정의 함수 사용
//sort(v.begin(), v.end(),greater<자료형>()); //내림차순 (Descending order)
//sort(v.begin(), v.end(),less<자료형>());//오름차순 (default = Ascending order)
int N;
// 사용자 정의 함수
bool mysort(string a, string b){
    if(a[N] != b[N]){ // 다른 문자면 
        return a[N] < b[N]; // 문자의 순서 반환
    }
    else{// 같은 문자면
        return a < b; // 문자열의 순서 반환
    }
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N=n;
    sort(strings.begin(),strings.end(),mysort); // 사용자 정의함수로 조건만족하는 문자열 배열 정렬 됨
    answer = strings;
    return answer;
}
