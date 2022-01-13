#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int d[100001];
vector<pair<int, int>> graph[100001];

int solution(int n, vector<vector<int>> route)
{
    int answer = 0;

    fill(d, d + 100001, 1000000001); //MAX로 채움.
    for (int i = 0; i < route.size(); i++)
    {
        graph[route[i][0]].push_back({ route[i][1], route[i][2] });
        graph[route[i][1]].push_back({ route[i][0], route[i][2] });
    }

    int start = 1;
    priority_queue<pair<int, int>> pq;

    pq.push({ 0, start });
    d[start] = 0;

    while (pq.empty() == false)
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist)
        {
            continue;
        }

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist > graph[now][i].second ? dist : graph[now][i].second;

            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
    answer = d[n];
    return answer;
}


int main(void)
{
	cout << solution(3, {{0, 0, 0}, {0, 1, 4}, {1, 0, 2}, {4, 2, 0}}) << endl;	
	return 0;
}
