

# 32
# 3,5 - 500 numbers
# histogram
# U(3,5) - 5000 numbers

# r_unif
x1 <-runif(500000, 3,5)
x2 <- dunif(5000, 3,5)
hist(x2)
hist(x1)

hist(x1, probability=T)

curve(dunif(x,3,5), from=3, to=5, add=T, lwd=2)

# 33
# 500 l=1/7

x1<- rexp(5000,1/7)
hist(x1,probability=T)
curve(dexp(x,1/7),from=0, to=max(x1) , add=T, lwd=2)



# 34
# 500 u =0 e = 1

x1 <- rnorm(5000,0,1)
hist(x1,probability=T)
curve(dnorm(x,0,1),add=T,lwd=2)


# 35
# n =200 n=1000
# (7,9)

n<-1000
x1 <- runif(n,7,9)

plot.ecdf(x1,do.points=F)
curve(punif(x,7,9), add=T, col='red')


# 36
# n = 200
# lambda= 3

n <- 1000
x1 <- rexp(n, 3)
plot.ecdf(x1,do.points=F)
curve(pexp(x,3),add=T,col='blue')


# 37
n <- 200
x1 <- rnorm(n,4,1.2)
plot.ecdf(x1,do.points=F)
curve(pnorm(x,3,1.2), add=T, col='blue')




# 38

par(mfrow=c(1,3))
curve(dunif(x,7,9),from=7,to=9)
curve(punif(x,7,9),from=7,to=9)
curve(qunif(x,7,9),from=0,to=1)


# 39
par(mfrow=c(1,3))
curve(dexp(x,3), from=0, to=4)
curve(pexp(x,3), from=-1,to=4)
curve(qexp(x,3), from =0, to =1)


# 40
par(mfrow=c(1,3))
curve(dnorm(x,4,1.2), from =0, to =8)
curve(pnorm(x,4,1.2), from =0, to =8)
curve(qnorm(x,4,1.2), from =0, to =1)


# 41
# a)
1 -punif(500,495,502)
# b)
qunif(0.2,495,502)


# 42 - 1/4
# a)
1 - pexp(3,1/4)
# b)
pexp(2,1/4)
# v)
# no! - pexp(6,1/4) - pexp(3,1/4)
(1-pexp(6, 1/4))/(1-pexp(3,1/4))
# d)
qexp(0.9,1/4)


# 43
# norm(41,5)
# a)
1- pnorm(51, 41,5)
# b) P( 45 <= x <= 50)
# no ! -- pnorm(51,41,5) - pnorm(44,41,5) # no
pnorm(50,41,5) - pnorm(45,41,5)
# v)
qnorm(0.99,41,5)


# 44

n <- 50000
x <- runif (n,-1,1)
y <- runif (n,-1,1)

res <- (x^2 + y^2 < 1)
sum(res)/n



# 45
n <- 500000
x <- runif(n,0.8,4)

t <- exp(1)^((-x^2)/2)/sqrt(2*pi)

sum(t)/n * (4-0.8)


# 46

n <- 5000
x <- rexp(n,1/8)
y <- 1 - exp(1)^(-1/8*x)
hist(y,probability=T)


# 47
lambda <- 1/8
n <- 5000
x <- runif(n,0,1)
hist(x,probability=T)
y <- -(1/lambda)*log(1-x)
hist(y,probability=T)
curve(dexp(x,lambda),add=T)



# 48

1-pnorm(4*60,260,50)

# 3< x < 5
pnorm(5*60, 260,50) - pnorm(3*60, 260,50)

qnorm(1-0.90,260,50)





