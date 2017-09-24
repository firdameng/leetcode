/*
*
*   72. Edit Distance
* 
*/

// others 动态规划的思想，
// 边界情况（动态规划的初始条件） + 普通情况，dp[i][j]表示把[0..i-1]转化为[0...j-1]所需最小步骤数
// 然后普通情况分替换，删除，增加三种方式达到转换word1到word2的目的
// 前提：做改变的只有Word1，当遍历到word1[i-1],word2[j-1]（从0开始计数，实际为第i,j个）时，二者不等时
// 1. 替换 - 首先dp[i-1][j-1]（从1开始计数）的最小步骤没有改变，此时只需要对word[i-1]进行替换用word2[j-1],
//     即可实现word1[0..i-1]到word2[0..j-1]的转变，即dp[i][j] = dp[i-1][j-1] +１；
// 2. 删除 - 明确是对word1[i-1]操作，即word1[0...i-2]到word2[0...j-1]的最小操作数不变,
//    此时只需要一步删除word1[i-1]的操纵,即可实现word1[0..i-2]到word2[0..j-1]的转变，即dp[i][j] = dp[i-1][j] +１；
// 3. 增加 - 明确是对word1操作，在word1之后增加word2[j-1],可实现word1[0..i-1] + word2[j-1] 到word2[0..j-1]的转变
//    这意味着word1[0...i-1]到word2[0...j-2]的最小操作数不变，即在word1[0...i-1]= word2[0...j-2]的基础上
//    对前者增加word2[j-1]，即dp[i][j] = dp[i][j-1] +１；比如i=2,j=3时，即word1 = 'ab',word2 = 'hel'，通过增加的
//    方式是word1->word2,是将dp[i][j-1]+1实现的。

/*
word1 = "abhcclleo"
word2 = "hello"
dp: j  h e l l o
  i 0  1 2 3 4 5
  a 1  1 2 3 4 5 
  b 2  2 2 3 4 5 
  h 3  2 3 3 4 5 
  c 4  3 3 4 4 5 
  c 5  4 4 4 5 5 
  l 6  5 5 4 4 5 
  l 7  6 6 5 4 5 
  e 8  7 6 6 5 5 
  o 9  8 7 7 6 5 
*/
// 时间复杂度 O(m*n),空间复杂度也是O(m*n)
class Solution { 
public:
    int minDistance(string word1, string word2) { 
        int m = word1.length(), n = word2.length();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;  
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
        return dp[m][n];
    }
};


// 时间复杂度 O(m*n),空间复杂度也是O(m)or O(n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> cur(m + 1, 0);
        for (int i = 1; i <= m; i++)
            cur[i] = i;
        for (int j = 1; j <= n; j++) {
            int pre = cur[0];
            cur[0] = j;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                if (word1[i - 1] == word2[j - 1])
                    cur[i] = pre;
                else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
                pre = temp;
            }
        }
        return cur[m]; 
    }
};