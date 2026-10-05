
# 70

# 100 - 58 ezi

x <- 58
n <- 100
p <- 0.5

# h0 > h1

z.obs <- (x/n - p)/sqrt(p*(1-p)/n)
z.obs

p.value <- 1-pnorm(z.obs)
p.value

# 0.0548 > 0.05
#   h0   >  h1
# нямаме основание да изхвърлим h0


# 71
  
n <- 100
p <- 61
p0 <- 0.5
  
z.obs <- (p/n - p0) / sqrt( p0*(1-p0)/n)
1 - pnorm(z.obs)




# 72
u = 6.7
delta = 0.12
n = 45
real_u = 6.73

# P(X = 6.7)


z.obs <- (real_u - u)/ (delta / sqrt(n))

p.value <- 2 * ( 1- pnorm(abs(z.obs)))
p.value



# 73

EX = 6.7
DX = 0.12

n = 45

T_X = 6.76
# T_X ?= EX

z.obs <- (6.76 - 6.7)/(DX/ sqrt(n))
2*(1 - pnorm(z.obs))

# 0.00796 < 0.05
# отхвърляме хипотеза H0
# машината не произвежда 6.7 средна размерност

# 74 

x <- c(3.1, 3.0, 3.7, 2.6, 4.2, 3.8, 3.6, 2.7, 3.8, 4.4)
n <- length(x)

ex <- mean(x)
sigma <- sd(x)

z.obs <- (ex - 4) / (sigma / sqrt(n))
z.obs
p.value <- pt(z.obs, n-1)

t.test(x, mu = 4, alternative = "less")

# 75

#l <- 106

p <- 32
n <- 58

exp_p <- 0.51


z.obs <- (p/n - exp_p)/sqrt(exp_p*(1-exp_p)/n)

p.value <-  1 - pnorm(z.obs)

#     H0 > H1
p.value
# so H0 is accually > H1

prop.test( x=32, n=58, p=0.51, alternative="greater", correct=F )$p.value



# 76

x <- c(12.3, 11.2, 14.2, 15.3, 14.8, 13.5, 11.1, 15.1, 15.4, 13.2)
# H0 != H1
mu <- 14.6
n <- length(x)

t.test(x, mu=14.6)

# 0.08 > 0.05
# не отхвърляме че среднотот е 14.6

#z.obs <- (mean(x) - mu)/(sd(x)/sqrt(n))

#p.value <- 2*(1-pt(abs(t.obs), n-1))

#t.test(x, mu=14.6)


t.obs <- (mean(x)- mu)/(sd(x)/sqrt(n))
t.obs

# a)
t.test( x, mu=14.6 )

# b)
t.test(x, mu=14.6, alternative="less")


# 77
# 7.5

# n= 200, x = 14

prop.test(14, 200, p =0.075, correct=F)

prop.test(14, 200, p =0.075, alternative="less", correct=F)



# 78

n <- 66 # 18 30

Ex <- 61.9
Ed <- 4.1

mu <- 60

z.obs <- (Ex - mu) / ( Ed / sqrt(n)) # 3.764798

2*(1-pnorm(abs(z.obs)))



# 79

mu <- 170
Dx <- 3.9

n <- 50
x <- 168

z <- (x - mu) / (Dx/sqrt(n))
1 - pnorm(abs(z))

# h0 < h1









# 0.00016 < 0.05