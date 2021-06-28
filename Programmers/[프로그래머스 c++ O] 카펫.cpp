#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 카펫
// 문제: 갈색,노란색 타일의 갯수가 주어졌을 때 조건에 만족하는 카펫의 가로,세로 길이 구하기
// 접근: 가로의 길이를 완전탐색하며 조건에 맞는 가로,세로 구하기
// 풀이: 
// 가로길이는 갈색타일의 갯수보다는 무조건 작으므로 가로의 길이가 갈색갯수부터 작아지며 반복문 탐색
// 해당 가로길이가 전체타일갯수과 나누어 떨어지면
// 가로 >= 세로 조건
// 세로>=3 조건
// 실제 노란 카펫의 갯수가 맞는지 확인
// 모든 조건 만족되면 가로,세로길이 정답벡터에 푸쉬
// 주의: 실제 노란 카펫의 갯수가 맞는지 확인 조건
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 갈색카펫의 갯수부터 작아지면서 탐색
    for(int i=brown;i>=1;i--){      
        int x = i ; // 가로길이
        int y = (brown+yellow)/i; // 세로길이
        if((brown+yellow)%i==0){ // 카펫전체 갯수가 가로길이로 나누어 떨어저면
           
            if(x<y){continue;} // 가로 >= 세로 조건
            if(y<3){continue;} // 세로>=3 조건
            if((y-2)*(x-2) != yellow){continue;} // 주의: 실제 노란 카펫의 갯수가 맞는지 확인
            // 만족되는 가로,세로길이 정답벡터에 푸쉬
            answer.push_back(x);
            answer.push_back(y);
        }
    }
    return answer;
}
