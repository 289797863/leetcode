//关于状态转移方程该这么选择，像这样给的是一维数组的题目，并且数组中的数组都没有相似性，即有不同的权重，
//且数组有比较奇怪的特性，比如每进行一次选择就需要删除里面的一个数，或者每次的选择不连续，数组中的任意一个数都可能被选中
//或者每种选中都对应一个状态，如果不记录下来，会对后续的选中产生影响的，可以思考将
//二维数组dp[i][j]的i和j设置为i到j内的数组的子问题，这样就不会影响i到j之外的后续问题的选择。


//方法一：
class Solution {
public:
    vector<vector<int>> rec;
    vector<int> val;

public:
    int solve(int left, int right) {
        if (left >= right - 1) {
            return 0;
        }
        if (rec[left][right] != -1) {
            return rec[left][right];
        }
        for (int i = left + 1; i < right; i++) {
            int sum = val[left] * val[i] * val[right];
            sum += solve(left, i) + solve(i, right);
            rec[left][right] = max(rec[left][right], sum);
        }
        return rec[left][right];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2);
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        val[0] = val[n + 1] = 1;
        rec.resize(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1);
    }
};

//方法二
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};

