#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*
[프로그래머스 42583 c++ VO] 다리를 지나는 트럭
문제: 다리의 무게한도를 초과하지 않으면서 트럭이 모두 지날 수 있는 최소 시간을 구해라
접근: 다리를 건너는 트럭에 트럭을 추가,삭제 -> 스택,큐 -> 순서대로: 큐를 사용
// 대기트럭의 무게와 다리의 무게합이 한도내에 있으면 다리를 건너는 큐에 푸쉬
// 큐의 크기가 다리의 길이와 같다 = 트럭이 다리 끝까지 왔다
풀이: 
// while반복문으로 걸리는 시간 ++
// 트럭이 다리끝에 도달한 경우 트럭 빼주기
// 다리의 무게를 초과하지 않으면 트럭 추가
// 대기트럭이 모두 빠졌을 때 시간 추가해주고 중단
주의: 다리의 무게 초과한 경우 0을 푸쉬해서 트럭을 한 칸 민다.

접근2: 벡터를 이용
풀이2:
    //1.다리에 차 진입
    //0)다리 길이 꽉차면 맨 처음 트럭 지우기
    //1)다리 무게 초과 안하면 진입
    //2)다리무게 초과하면 0 추가
*/
vector<int> br;
int si, cur_weight=0, ti=0, out_cnt=0, cur_truck;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int size_ori = truck_weights.size();
    //1.다리에 차 진입
    while(1){
        si = br.size();
        //0)다리 길이 꽉차면 맨 처음 트럭 지우기
        if(si>=bridge_length){
            cur_truck = br[0];
            br.erase(br.begin()); cur_weight-=cur_truck; // 대기 트럭 추출
            if(cur_truck!=0){ // 나온 실제 트럭 카운트
                out_cnt++;
            }
            if(out_cnt>= size_ori){ // 트럭 모두 다리 지난 경우
                ti++;
                break;
            }
        }
        
        //1)다리 무게 초과 안하면 진입
        if(truck_weights.size()!=0 && cur_weight+truck_weights[0] <= weight){
            br.push_back(truck_weights[0]);
            cur_weight+=truck_weights[0];
            truck_weights.erase(truck_weights.begin()+0);
            ti++;
        }
        else{ //2)다리무게 초과하면 0 추가
            br.push_back(0);
            ti++;
        }
    }
        
    return answer=ti;
}
