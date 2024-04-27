y <- c(1 , 2 , 3 , 4 , 7 )
g <- c("a","b","c","E","s" )
rbind( y , g )
cbind( y , g )
x <- scan()
1
2
3
1
2
3
5
6
4
5
2
2
2
1.123

length(x)
median(x)
mean(x)
names( sort( -table(x) ) ) [1]
range(x)
var(x)
sd(x)

# define function code
function_name <- function(k) {
  sqrt( var(k) / length(k) ) -> result
  return (result)
}
function_name(x)

#偏度&峰度
library(psych)
skew(x) #偏度
kurtosi(x) #峰度
shapiro.test(x) #判斷是否為常態分佈

#另一個判斷常態分佈的方法
library(nortest)
lillie.test(x)

#長條圖
hist(x)

