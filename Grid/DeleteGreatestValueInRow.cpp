#include <bits/stdc++.h>
using namespace std;

int deleteGreatestValue(vector<vector<int>> &grid)
{
    int m = grid.size(), t = 0, ans = 0, maxRemoved = 0;
    for (int t = 0; t < grid[0].size(); t++)
    {
        for (int i = 0; i < m; i++)
        {
            int maxValue = grid[i][0];
            int row = i, col = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] > maxValue)
                {
                    maxValue = grid[i][j];
                    row = i;
                    col = j;
                }
            }
            grid[row][col] = 0;
            maxRemoved = max(maxRemoved, maxValue);
        }
        cout << "Max removed = " << maxRemoved << endl;
        ans += maxRemoved;
        maxRemoved = 0;
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int res = deleteGreatestValue(grid);
    cout << res;
    return 0;
}