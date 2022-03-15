//二维数据也可以从后向前遍历
//要想到一个没有！！后效性！！的子问题，有时候从前往后来不行就试一试从后往前遍历
//主要关注运算需要知道的数据
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(),m = dungeon[0].size();
        vector<int> dp(m+1,1);
        for(int i = m-1;i>=0;--i){
            dp[i] = dp[i+1] - dungeon[n-1][i];
            dp[i] = dp[i]>0?dp[i]:1;
        }
        dp[m] = pow(10,5);
        for(int i = n-2;i>=0;--i){
            for(int j = m-1;j>=0;--j){
                dp[j] = min(dp[j],dp[j+1]) - dungeon[i][j];
                dp[j] = dp[j]>0? dp[j]:1;
                cout<<dp[j]<<endl;
            }
        }
        return dp[0]>0?dp[0]:1;
    }
};
