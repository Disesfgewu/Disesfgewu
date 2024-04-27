import sys
ans=0-sys.maxsize
m,n=tuple([int(i) for i in input().split()])
MAP=[[int(j) for j in input().split()] for i in range(m)]
dp_left =[[ans for i in range(n)] for j in range(m)]
dp_right=[[ans for i in range(n)] for j in range(m)]
dp =[[ans for i in range(n)] for j in range(m)]

dp_right[0][0] = MAP[0][0]
dp_left[0][n-1] = MAP[0][n-1]
for i in range(1,n):
  dp_right[0][i] = max([dp_right[0][i-1] + MAP[0][i] , MAP[0][i]])
  dp_left[0][n-i-1] = max([dp_left[0][n-i] + MAP[0][n-i-1] , MAP[0][n-i-1]])
  dp[0][i] = max([dp_right[0][i] , dp_left[0][i]])
  dp[0][n-i-1] = max([dp_right[0][n-i-1] , dp_left[0][n-i-1]])

half = int(n/2)
for j in range(1,m):
  for i in range(0,n):
    if i == 0:
      dp_right[j][i] = dp[j-1][i]
    else:
      dp_right[j][i] = max([dp_right[j][i-1], dp[j-1][i]])
    dp_right[j][i] += MAP[j][i]

    if i == 0:
      dp_left[j][n-i-1] = dp[j-1][n-i-1]
    else:
      dp_left[j][n-i-1] = max([dp_left[j][n-i] , dp[j-1][n-i-1]])
    dp_left[j][n-i-1] += MAP[j][n-i-1]

    if i >= half:
      dp[j][i] = max([dp_right[j][i] , dp_left[j][i]])
      dp[j][n-i-1] = max([dp_right[j][n-i-1] , dp_left[j][n-i-1]])


print(max(dp[m-1]))