# 60


N <- 1000
for (n in c(3, 7, 10, 30, 90, 200)) {
  xsum <- replicate( N, sum( rexp(n,1/5) ) )
  hist(xsum, main=paste("n =",n))
}

for (n in c(3, 7, 10, 30, 90, 200)) {
  xsum <- replicate( N, sum( rexp(n,1/5) ) )
  plot.ecdf(xsum, do.points=F, col='blue', lwd=2, main=paste("n =", n))
  curve(pnorm(x, 5*n, 5*sqrt(n)), add=T, col='coral', lty='longdash',lwd=2)
}


# 61

N <- 1000
for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(N, sum(rexp(n,1/5))/n )
  hist(x, main=paste("n = ",n))
}

for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(N, sum(rexp(n,1/5))/n )
  plot.ecdf(x, do.points=F, main=paste("n = ",n))
  curve(pnorm(x,5,5/sqrt(n)),add=T,lty='longdash')
}



# 62

for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, sum(rpois(n, 3)))
  hist(x, main=paste('n = ',n))
}


for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, sum(rpois(n, 3)))
  plot.ecdf(x, main = paste('n = ',n), do.points = F)
  curve(pnorm(x,3*n,sqrt(3*n)),add =T)
}

# 63
for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, mean(rpois(n, 3)))
  hist(x, main=paste('n = ',n))
}


for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, mean(rpois(n, 3)))
  plot.ecdf(x, main = paste('n = ',n), do.points = F)
  curve(pnorm(x,3,sqrt(3)/sqrt(n)),add =T)
}

# 64


for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, mean(runif(n, 2,8)))
  hist(x, main=paste('n = ',n))
}


for (n in c(3, 7, 10, 30, 90, 200)) {
  x <- replicate(1000, mean(runif(n, 2,8)))
  
  plot.ecdf(x, main = paste('n = ',n), do.points = F)
  curve(pnorm(x,0,sqrt(1)),add =T)
}


# 65 exp
u = 900 
n = 100
# P(X > 980)


a <- (980-u)/(u/sqrt(100))
1 - pnorm(a)

# sim
mean.vals <- replicate(1000, mean(rexp(100,1/900)))
sum(mean.vals > 980)/ length(mean.vals)
hist(mean.vals)

# 66
a = 0
b = 60
n = 50
# 25 < pos < 35

mean.vals <- replicate(10000, mean(runif(n,a,b)))
sum(mean.vals > 25 & mean.vals < 35)/ length(mean.vals)
hist(mean.vals)



# 67

X <- c(4:7)
P <- c(0.2, 0.4, 0.3, 0.1)


ex <- sum(X*P)
dx <- sqrt(sum((X^2)*P)-sum(ex)^2)

# normal
a <- (5.5-ex)/(dx/sqrt(49))
1-pnorm(a)

# sim

mean.vals <- replicate(100000, mean(sample(X, 49,replace=T,prob=P)))
sum(mean.vals > 5.5)/length(mean.vals)



# 68
# > 4000
U <- 24 
D <- 7
n <- 160

a <- (4000 - n*U)/(D*sqrt(n))
1 - pnorm(a)


# 69
lambda <- 5
n <- 80

# P(4.5 < X < 5.5)

x <- rexp(n,lambda)
sum(x > 4.5 & x < 5.5) / length(x)

pois()




