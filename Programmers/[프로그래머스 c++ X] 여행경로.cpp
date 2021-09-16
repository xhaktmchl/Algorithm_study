#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// [프로그래머스 c++ X] 여행경로
// 문제: 
// 접근: 
// 풀이: 
// 주의: 노드가 서로 이어지지 않은 경우 처리하는 것 주의
#define MAX 10001
bool visit[MAX];
vector<string> answer;
bool ok;

void dfs(string start,vector<vector<string>>& tickets,vector<string> tp,int cnt){ // 현재 공항,티켓배열,현째까지 경로, 경로에 포함된 노드갯수
    // 경로를 다 돌은 경우
    if(cnt == tickets.size()){
        tp.push_back(start);
        answer = tp; 
        ok=1; // 하나만 발견시 다른 재귀 못하게
        return;
    }
    
    for(int i=0;i<tickets.size();i++){
        if(!visit[i] && start == tickets[i][0]){ // 방문, 다음 공항있으면
            visit[i] = 1; tp.push_back(tickets[i][0]); // 방문
            dfs(tickets[i][1],tickets,tp,cnt+1);
            if(ok){return;} // 경로 이미 찾았으면 종료
            visit[i] = 0; tp.pop_back(); // 못찾은 거면 노드 팝
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> tp;
    sort(tickets.begin(),tickets.end()); // 알파벳 순으로 탐색하기 위한 정렬
    
    dfs("ICN",tickets,tp,0);
    return answer;
}
