#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
// [프로그래머스 c++ V] 더 맵게
// 문제: 배열에 주어진 모든 음식의 스코빌 지수를 규칙에 따라 K 이상으로 만들기 위한 계산 횟수 구하기
// 접근: 벡터로 스코빌 지수들 정렬-> 최소 2개 음식 갖고 스코빌 지수 계산하고 정렬 반복 -> 생각만 함
// 접근: 힙,우선순위 큐에 스코빌 지수 저장하고 -> 최소 2개 뽑아서 -> 계산 반복 
// 풀이: 
// 우선순위 큐에 스코빌 지수 저장
// 반복된 규칙 계산으로 스코빌 지수보다 크게 만들기
// 1.스코빌 지수보다 모두 큰 경우
// 2.스코빌 지수로 못 만들 경우 예외처리
// 3.크코빌 지수보다 작은것이 있는 경우 : 2개 빼서 계산
int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 우선순위 큐에 스코빌 지수 저장
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
        //cout<<q.top()<<'\n';
    }
    
    // 반복으로 스코빌 지수보다 크게 만들기
    int time=0;
    while(1){
        
        // 스코빌 지수보다 모두 큰 경우
        if(q.top() >= K){answer = time; break;}
        // 스코빌 지수로 못 만들 경우 예외처리
        if(q.size()< 2){answer = -1; break;}
        // 크코빌 지수보다 작은것이 있는 경우
        int min1 = q.top(); q.pop();
        int min2 = q.top(); q.pop();
        int new_food = min1+ min2*2;
        q.push(new_food);
        time++;
    }
    
    return answer;
}
