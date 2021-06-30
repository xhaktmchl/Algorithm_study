#include <string>
#include <vector>

using namespace std;
// [프로그래머스 c++ O] 행렬의 덧셈
// 문제: 
// 접근: 
// 풀이: 1차원 벡터를 생성해 2차원 벡터에 push_back
// 주의: 2차원 벡터의 행,렬 길이 뽑기,행의 길이= arr1.size(),열의 길이 arr1[0].size()
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0;i<arr1.size();i++){ // 행의 길이= arr1.size()
        vector<int> tp;
        for(int j=0;j<arr1[0].size();j++){ // 열의 길이 arr1[0].size()
            tp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(tp);
    }
    return answer;
}
