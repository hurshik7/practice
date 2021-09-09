#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1;
	bool cont = false;
	int x = -1;
	int y = -1;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 1) 
			{
				int width = 0;
				int height = 0;
				for (int x = j; x < board[i].size(); x++)
				{
					if (board[i][x] == 1) 
					{
						width++;
					}
					else 
					{
						break;
					}
				}
				
				height++;
				for (int y = i + 1; y < board.size() &&  < width; y++)
				{
					
				}
			}
		}
	}

    return answer;
}

int main(void)
{
	cout << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl;
	cout << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl; 
	return 0;
}
