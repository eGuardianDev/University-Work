# 49

library(MASS)
data(survey)
?survey

table(survey$Exer)

attach(survey)
table(Exer)


sort(table(Exer),decreasing=T)
100 * table(Exer)/length(Exer)
100 * prop.table(table(Exer))

barplot(table(Exer))
barplot(sort(table(Exer))/length(Exer))

barplot(100*(table(Exer))/length(Exer))

pie(table(Exer))
pie(table(Exer), col=c("green","red","blue"))


# 50

table(Pulse)
table(Pulse, useNA="ifany")
barplot(table(Pulse))

pulse.interval <- cut(Pulse, breaks=(seq(30,110,10)))
pulse.interval
table(pulse.interval)

hist(table(pulse.interval))
hist(Pulse)
hist(Pulse, breaks=seq(30,110,5))


stripchart(Pulse, method="stack",pch=20)
stripchart(Pulse, method="stack",pch=18)
stripchart(Pulse, method="stack",pch=1)
stripchart(Pulse, method="stack",pch='*')


# 51

age.intervals <- cut(Age, breaks = seq(15,75,10))
table(age.intervals)

barplot(table(age.intervals))
pie(table(age.intervals))
hist(Age)

stripchart(Age, method='stack', pch='*')



my.summary <- function(x){
  res <- c(median(x,na.rm=T), mean(x,na.rm=T),sd(x,na.rm=T))
  names(res) <- c("Median", "Mean", "StDev")
  res
}

my.summary(Age)


# 52

v1 <- rep(4, 30)
v2 <- rep(c(3.5,4.5), 15)
v3 <- rep(c(3,5), 15)
v4 <- rep(c(2:6), 6)
v5 <- rep(c(2,6), 15)

my.summary(v1)
my.summary(v2)
my.summary(v3)
my.summary(v4)
my.summary(v5)


par(mfrow=c(2,3))
stripchart(v1,pch='*',method='stack',xlim=c(2,6),ylim=c(0,10))
stripchart(v2,pch='*',method='stack',xlim=c(2,6),ylim=c(0,10))
stripchart(v3,pch='*',method='stack',xlim=c(2,6),ylim=c(0,10))
stripchart(v4,pch='*',method='stack',xlim=c(2,6),ylim=c(0,10))
stripchart(v5,pch='*',method='stack',xlim=c(2,6),ylim=c(0,10))

par(mfrow=c(1,1))



# 53

load("cereals.RData")

head(table(cereals),20)

summary(cereals)

summary(carbo)
mean(carbo, na.rm=T)
sd(carbo, na.rm=T)
my.summary(carbo)
hist(carbo)
boxplot(carbo,horizontal=T)

summary(sodium)
mean(sodium, na.rm=T)
sd(sodium, na.rm=T)
my.summary(sodium)
hist(sodium)
boxplot(sodium,horizontal=T)

summary(potass)
mean(potass, na.rm=T)
sd(potass, na.rm=T)
my.summary(potass)
hist(potass)
boxplot(potass,horizontal=T)



library(MASS)
attach(survey)

boxplot(Pulse ~ W.Hnd)
boxplot(Pulse[W.Hnd == "Left"], Pulse[W.Hnd == "Right"])

my.summary(Pulse[W.Hnd == "Left"])
my.summary(Pulse[W.Hnd == "Right"])


# 55
# a)

my.summary(Pulse)
my.summary(Pulse[Sex == "Female"])

my.summary(Pulse[Age <= 25])

my.summary(Pulse[Exer == "Freq"])
my.summary(Pulse[Exer == "Freq" & Smoke == "Never"])


# 56
boxplot(Pulse ~ Exer)


# 57
my.summary(table(Smoke))
pie(table(Smoke))


?survey
# 58
my.summary(Age)
my.summary(Age[Smoke != "Never"])
my.summary(Age[Smoke != "Never" & W.Hnd == "Right"])
my.summary(Age[Pulse >=70])
my.summary(Age[Exer == "None"])


# 59

boxplot(Height, horizontal = T)

stripchart(Height,pch='*',method='stack', xlim=c(150,205), ylim=c(0,10))
my.summary(Height)
