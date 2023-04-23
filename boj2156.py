n = int(input())
arr = [0] + [int(input())for _ in[0] * n]
dp = [0] * (n + 1)
if n >= 2:dp[2] = arr[1] + arr[2]
dp[1] = arr[1]
for i in range(3, n + 1) : dp[i] = max(dp[i - 1], max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]))
print(dp[n])