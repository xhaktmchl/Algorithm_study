#include <string>
#include <vector>
#include <iostream>
using namespace std;
// [프로그래머스 c++ O] 기능개발
// 문제: 기능이 배포되는데 걸리는 시간을 계산하여 한번 배포할 때 몇개의 기능들이 배포되는지 구하라
// 접근: 기본구현-> 배포일 계산 -> 앞 기능 배포일< 뒤기능 배포일 // 앞 기능 배포일> 뒤 기능 배포일 경우 나누어 생각
// 배포일이 5 1 1 6 이면 5,1,1 까지는 5보다 작으므로 함께 배포, 6은 5보다 크므로 따로 배포
// 풀이: 
// 배포에 걸리는 일 수 배열 작성
// 각 배포마다 배포되는 기능들의 개수 세기
// 원소 갯수가 1일때 예외처리
// 완전탐색 :   뒤의 기능은 나중에 배포되는 경우 + // 뒤의 기능까지 포함해서 배포되는 경우
// 마지막 남은 일 수가 앞의 배포일 보다 크든 작든 마지막것 추가해줘야 함
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int maxN=0,idx=0;
    vector<int> days;
    // 배포에 걸리는 일 수 배열 작성
    for(int i=0;i<progresses.size();i++){
        if((100 - progresses[i])%speeds[i] == 0){days.push_back((100 - progresses[i])/speeds[i]);}
        else {days.push_back((100 - progresses[i])/speeds[i]+1); }
        cout<<days[i]<<'\n';
    }
    // 각 배포마다 배포되는 기능들의 개수 세기
    maxN = days[0]; //제일 앞에 배포되는 기능의 배포일 수
    int c=1; 
    if(days.size() == 1){answer.push_back(c);} // 원소 갯수가 1일때 예외처리
    for(int i=1;i<days.size();i++){
        // 뒤의 기능은 나중에 배포되는 경우
        if(days[i] > maxN){
            maxN = days[i]; 
            answer.push_back(c);  
            c=1; 
            continue;
        }// 뒤의 기능까지 포함해서 배포되는 경우
        else { 
            c++;
        }
    }
    answer.push_back(c); // 마지막 남은 일 수가 앞의 배포일 보다 크든 작든 마지막것 추가해줘야 함
    
    return answer;
}
