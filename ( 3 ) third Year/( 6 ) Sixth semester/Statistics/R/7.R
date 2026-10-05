

exam <- read.table("examAB.txt", header=T)

a.points <- exam$points[exam$variant == "A"]
b.points <- exam$points[exam$variant == "B"]
  
t.test(a.points, b.points, alternative ="greater")
# p.value = 0.01668 < 0.05

t.test(points ~ variant, data=exam, alternative="greater")


# 81
reaction <- read.table("reacttime.txt", header=T)

before <- reaction$before
after <- reaction$after

t.test(before, after, alternative="less", paired = T)$p.value


# 82

# n 200 from A - 8 def
# n 200 from B - 15 def

x <- c(8,15)
n <- c(200, 200)

prop.test(x,n,correct=F)$p.value

# 0.13 > 0.05 - няма защо да си мислим че се различават



# 84

N = 10000

sim.t2 <- function(n, mu1, mu2, sigma1, sigma2){
  x <- rnorm(n,mu1,sigma1)
  y <- rnorm(n,mu2,sigma2)
  t.test(x,y)$p.value  
}

rs <- replicate(N, sim.t2(n=200, mu1=5, mu2=5, sigma1=1,sigma2=0.8 ))
sum(rs <= 0.05)/length(rs)
sum(rs <= 0.1)/length(rs)


# 85
rs <- replicate(N, sim.t2(n=1000, mu1=5, mu2=5.2, sigma1=1,sigma2=1 ))
sum(rs <= 0.05)/length(rs)
sum(rs <= 0.10)/length(rs)



# 86
n = 500
x = 26

n = 540
x = 43


x = c(26,43)
n = c(500,540)

prop.test(x,n,alternative="less", correct=F)$p.value


# 87

x1 <- c(1.2, 1.3, 1.5, 1.4, 1.7, 1.8, 1.4, 1.3)
x2 <- c(1.4, 1.7, 1.5, 1.3, 2.0, 2.1, 1.7, 1.6)


t.test(x1,x2, paired=T)$p.value
# двата метода не дават един и същ резултат


# 88

n = 50
x1 = 7.88
mu1 = 1.73

x2= 8.48
mu2 = 2.12

t.obs <- (x1-x2) / sqrt(mu1^2/n + mu2^2/n)
t.obs

#df <- (mu1^2/n +mu2^2/n) / (( mu1^2/n)^2)/(n-1) +(mu2^2/n)^2/(n-1) )



