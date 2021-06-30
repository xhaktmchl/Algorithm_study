#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// [프로그래머스 c++ V] 구명보트
// 문제: 최대 2 명씩 태우는 보트를 이용해서 사람들을 운반했을 때 이용하는 배의 최소갯수 구하기
// 접근1: 최소-> 그리디/dp : 최대값 + 수용되는 범위의 최댓값 <= 한계 가 배의 최소갯수  // 정확도는 맞으나 시간초과
// 접근2 : 최소 = 최대값 + 최소값 <= 한계 가 배의 최소갯수 // 이 경우가 왜 배의 최소갯수인지 이해 안됨???
// 풀이: 
// 사람 몸무게 정렬
// 벡터의 앞뒤부터가 최대 최소니까 최대+최소 <= 한계 인경우 앞 인덱스 증가(2명 태우기)
// 최대+최소 > 한계 인 경우 는 최댁값 1명만 태우기
// 개념: 벡터.pop_back(대입할 대상)

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // 배의 최소 갯수는 최소+최대값 <= 배 한계 작을 때 
    sort(people.begin(),people.end());
    int idx=0; int backIdx = people.size()-1; // 맨 앞뒤 인덱스
    while(idx <= backIdx){ // 주의: = 때도 포함해야 함
        if(people[idx]+people[backIdx] <= limit){idx++; } // 최소+최대 값이 한계보다 작으면 최소값 에서 한칸 증가
        backIdx--; // 최대값 인덱스 감소
        answer++; 
    }
    
    return answer;
}
