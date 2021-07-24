#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// [프로그래머스 c++ V] 다리를 지나는 트럭
// 문제: 다리의 무게한도를 초과하지 않으면서 트럭이 모두 지날 수 있는 최소 시간을 구해라
// 접근: 다리를 건너는 트럭에 트럭을 추가,삭제 -> 스택,큐 -> 순서대로: 큐를 사용
// 대기트럭의 무게와 다리의 무게합이 한도내에 있으면 다리를 건너는 큐에 푸쉬
// 큐의 크기가 다리의 길이와 같다 = 트럭이 다리 끝까지 왔다
// 풀이: 
// while반복문으로 걸리는 시간 ++
// 트럭이 다리끝에 도달한 경우 트럭 빼주기
// 다리의 무게를 초과하지 않으면 트럭 추가
// 대기트럭이 모두 빠졌을 때 시간 추가해주고 중단
// 주의: 다리의 무게 초과한 경우 0을 푸쉬해서 트럭을 한 칸 민다.
queue<int> q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truckIdx=0;
    int time=0;
    int sum=0;
    int size = truck_weights.size();
    while(1){
        
        time++;
        // 트럭이 다리끝에 도착하면 빼줌
        if(q.size() == bridge_length){
            sum-= q.front(); // 다리의 무게합 최신화
            q.pop();
        }
            
        // 다리의 무게를 초과하지 않으면 트럭 추가
        if(sum+ truck_weights[truckIdx] <= weight){
            q.push(truck_weights[truckIdx]);
            //cout<<truck_weights[truckIdx]<<'\n';
            sum+= truck_weights[truckIdx]; // 다리에 무게 추가
            truckIdx++; // 대기트럭 하나 빠짐
            // 대기트럭이 모두 빠졌을 때
            if(truckIdx == size){ 
                time+=bridge_length;
                break;
            }
        }
        else{ //다리의 무게 초과하면 0을 푸쉬해서 트럭을 한 칸 민다.
            q.push(0);
        }
    }
    return answer=time;
}
