#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ V] 전화번호 목록
// 문제: 전화번호가 적힌 문자열 벡터에서 한 전화번호가 다른 전화번호의 접두어인 경우가 있는지 탐색
// 접근: 문자열 길이순으로 정렬한 후 길이 작은 것이 큰 것의 접두어에 있는지 탐색 -> find는 크기달라도 자동처리되기 때문에 불필요
// 접근2: 문자열 사전 순으로 정렬 -> 접두어에 같은 문자열 있는지 완전탐색 -> 제한사항 같은 전화번호가 중복해서 들어있지 않아서 인접 문자열 끼리만 비교하면 됨
// 풀이: 
// 사전 순으로 정렬
// 전화번호 접두어에 포함되는지 탐색 , find함수 이용
// 개념:
// string.find(문자열) : 반환값= 찾는 문자열의 시작 위치 , 없으면 string::npos 라는 임이의 수 반환

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(),phone_book.end()); // 사전 순으로 정렬
    // 전화번호 접두어에 포함되는지 탐색
    for(int i=0;i<phone_book.size()-1;i++){
            if(phone_book[i+1].find(phone_book[i]) == 0){ // 접두어에 포함된 경우
                return answer = false;
            }
    }
    return answer;
}
