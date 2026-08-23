class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        int n = 9;
        char badc = (int)((char)'.' - (char)'0');
        for(int i = 0; i < 9; i++) 
        {
            vector<int> vis(10, 0);
            for(int j = 0; j < 9; j++)
            {
                int curc = b[i][j] - '0';
                if(curc == badc) continue;
                if(vis[curc]) return false;
                vis[curc] = 1;
            }
        }
        for(int j = 0; j < 9; j++) 
        {
            vector<int> vis(10, 0);
            for(int i = 0; i < 9; i++)
            {
                int curc = b[i][j] - '0';
                if(curc == badc) continue;
                if(vis[curc]) return false;
                vis[curc] = 1;
            }
        }
        for(int i = 0; i < 3; i++) 
        {
            
            for(int j = 0; j < 3; j++)
            {
                vector<int> vis(10, 0);

                for(int ii = 0; ii < 3; ii++)
                {
                    for(int jj = 0; jj < 3; jj++)
                    {
                        int curc = b[3*i+ii][3*j+jj] - '0';
                        if(curc == badc) continue;
                        if(vis[curc]) return false;
                        vis[curc] = 1;
                    }
                }
            }
        }
        return true;
    }
};
