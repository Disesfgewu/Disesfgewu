x <- scan()
5.5
4.7
6.5
4.6
3.7
7.6

t.test(x)

t.test(x,mu=5)

t.test(x,mu=5,alternative = "greater")

t.test(x,mu=5,alternative = "less")

y <- scan()
9.4
8.8
10.4
8.9
7.1
11.1

x
y

length(x)
length(y)

t.test(x,y,paired=TRUE,mu=-5)

hist(x)
hist(y)

t.test(x,y,paired=TRUE,alternative = "greater")
t.test(x,y,paired=TRUE,alternative = "less")

t.test(x,y)
t.test(x,y,alternative = "greater")
t.test(x,y,alternative = "less")

t.test(x,y,var.equal = TRUE )

t.test(x,y,var.equal = TRUE, mu=-5,alternative = "two.sided" )
