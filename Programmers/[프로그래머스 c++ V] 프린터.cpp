#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// [프로그래머스 c++ V] 프린터
// 문제: 원하는 문서가 대기목록에서 언제 프린트 되는지 구하라
// 접근: 우선순위 큐로 중요도 순서, 큐로 프린터 대기명단 이용
// 풀이: 
// 대기목록과 중요도 순서 큐와 우선순위 큐에 입력
// 프린터 대기명단 제일 앞 문서가 중요도가 제일 높은지 확인
// 제일 높으면 자신이 원하는 문서인지 확인
// 높지 않으면 프린터 대기명단 제일 뒤에 삽입
priority_queue<int> pri_q; 
queue<pair<int,int>> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 우선순위와 인덱스 위치 큐에 입력
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i});
        pri_q.push(priorities[i]);   
    }
    
    // 우선순위 확인
    int c=1;
    while(!q.empty()){
        int val = q.front().first;
        int idx = q.front().second;
        // 프린터 대기목록 제일 앞의 문서가 제일 우선순위 높으면
        if(val == pri_q.top()){ 
            if(location == idx){ // 내가 원하는 프린터면 그 때의 순서 저장 및 중단
                answer = c; 
            break;
            }
            // 아니면 출력 후 대기명단에서 삭제
            q.pop();
            pri_q.pop();
            c++;
        }
        else{// 우선순위 제일 높지 않으면 
            q.pop();
            q.push({priorities[idx],idx});
        }
    }
    return answer;
}
