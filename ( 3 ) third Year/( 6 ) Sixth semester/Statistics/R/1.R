
# 1
#8 топки 1-8 
#вадим и връщаме


sim.ball <- function(){
  x <- sample( c(1:8), 2, replace=T)
  x[1] == x[2]
}

res <- replicate(100000, sim.ball())

sum(res)/length(res)


# 2 
# 3 чорапи
# вадим 2 чорапа
# какъв е шанса два чорапа да са чифт

sim.socks <- function(){
  x <- c(1,1,2,2,3,3)
  r <- sample(x,2,replace = F)
  r[1] == r[2]
}

res <- replicate(100000, sim.socks())

sum(res)/length(res)

prob.socks <- function(Nrep){
  res <- replicate(Nrep, sim.socks())
  sum(res)/length(res)
}

prob.socks(100000)


# 3 
# Иван - 4 ключа
# помни ключа - не връща
# шанса да отвори с 4-тия ключ

sim.keys <- function(){
  x <- sample( c(1:4), 4, replace =F)
  x[4] == 4
}

res <- replicate(100000, sim.keys())

sum(res)/length(res)


# 4 
# 20 върпоса
# не знаем 3
# тегли 2
# какъв е шанса да знае само 1 от изтеглените

sim.test <- function(){
  r <- c( rep(0,3), rep(1,17) )
  
  x <- sample(r, 2, replace = F)
  
  sum(x) == 1
}

res <- replicate(100000, sim.test())

sum(res)/length(res)


# 5 

sim.birthday <- function(){
  x <- sample(c(1:365), 20, replace = T)
  any(duplicated(x))
}

res <- replicate(10000, sim.birthday())
sum(res)/length(res);

# 6 
# 20 човека - 20 листа
# теглим без да връщаме
# каква е вероятността един да изтегли свое име



sim.gift <- function(){
  x <- sample(c(1:20), 20, replace = F)
  g <- x - c(1:20)
  any(g==0)
}

res <- replicate(100000, sim.gift())
sum(res)/length(res)



# 7
# мравка на триъгълник на ръб

sim.ants <- function(){
  a <- c(0:2)
  d <- c(-1,1)
  x <- sample(d,3,replace=T)
  a <- a + x
  a <- a %% 3
  any(duplicated(a)) == FALSE
}

res <- replicate(100000, sim.ants());
sum(res)/length(res)


# 8 
# 6 сурови, 2 варени яйца

sim.egg <- function(){
  x <- c( rep(0,6), rep(1,2))
  s <- sample(x, 8, replace=F)
  
  player1 <- s[seq(1,7,2)]
  player2 <- s[seq(2,8,2)]
  
  b1 <- sum(player1)
  b2 <- sum(player2)

  c(b1,b2)
}

N = 100000
res <- replicate(N, sim.egg())

# a)
(sum(res[1,] == 2) + sum(res[2,]==2))/ N

# b)
(sum(res[1,] == 1))/ N
(sum(res[2,] == 1))/ N

# v)
(sum(res[1,] == 2) )/N

# g)
(sum(res[2,] == 2) )/N



# 9
# изпит, не учи, появявае и отгражда 5 оговора, какъв е шанса 1 да е верен
sim.exam <- function(){
  #x <- c( rep(0,3), 1)
  #exam <- sample(x, 10, replace=T)
  exam <- sample(c(0,1),10, replace =T, prob=c(0.75,0.25))
  sum(exam) >= 5
}

res <- replicate(100000, sim.exam())
sum(res)/length(res)



# --- part 2 ---

# 10
# 143 билета, 138 места
# вероятност да се покаже на време 0.92
# независими събития

# a) да има място за всички

sim.seats <- function(){
  x <- sample( c(0,1), 143, T, c(0.08,0.92))
  sum(x)
}

res <- replicate(100000, sim.seats());
sum(res <= 138)/length(res)


# б) едно незаето място
sum(res == 137)/length(res)


# 11
# 2 зелени и 2 червени - ако е 6 зара
# 1 зелена и 4 червени - ако не е 6 зара 

# а) какъв е шанса да е зелена топка
sim.green_ball <- function(){

  boxes <- list(
    c("g", "g", "r", "r"),
    c("g", "r", "r", "r", "r")
  )
  
  box <- sample (c(1,2), 1,F, c(1/6,5/6));
  
  res <- sample(boxes[[box]], 1, F);
  res == 'g';
}

res <- replicate(100000,sim.green_ball());

sum(res)/length(res);

# b) ако е зелена какъв е шанса да е от втората кутия

sim.green_ball.b <- function(){
  box <- sample( c(1,2), 1,F, c(1/6,5/6));
  
  if(box ==1){
    g_ball <-sample(c("g","g","r","r"),1,F);  
  }else{
    g_ball <- sample(c("g","r","r","r","r"), 1, F);
  }
  
  c(box, g_ball)
}
  
res <- replicate(100000, sim.green_ball.b())

sum(res[1,] == 2 & res[2,] == "g")/ sum(res[2,]=="g")

#a)
sum(res[2,] == "g")/length(res)


# 12
# T11 - 2
# T22 - 1
# T12 - 2 

sim.coin.a <- function(){
  T11 <- c(1,1)
  T12 <- c(1,2)
  T22 <- c(2,2)
  
  coins <- list(T11,T11,T12,T12,T22);
  
  index <- sample(c(1:5),1);
  
  number <- sample(coins[[index]],1);
  
  number
}

res <- replicate(100000, sim.coin.a());

sum(res==1)/ length(res)



sim.coin.b <- function(){
  T11 <- c(1,1)
  T12 <- c(1,2)
  T22 <- c(2,2)
  
  coins <- list(T11,T11,T12,T12,T22);
  
  index <- sample(c(1:5),1);
  
  number <- sample(coins[[index]],1);
  
  c(number, index)
}

res <- replicate(10000,sim.coin.b())

sum( res[1,] == 1 & ( res[,2] == 3 | res[,3]== 4)) / sum(res[1,] == 1)

# res[1:10,]



## -- hw

# 13

# 1 ww
# 1 bb
# 1 bw


sim.cards <- function(){
  
  x <- sample( c('bb','ww','bw'), 1)
  
  side <- sample(c(1,2),1);
  
  c_side <- substr(x, side, side)
  
  c(x,c_side)
}

res <- replicate(10000, sim.cards())

sum(res[2,] == 'w' & res[1,] == 'ww') / sum(res[2,]=='w')



# 14
# 99 balls - 1..99
# take 4

sim.balls <- function(){
  
  x <- sample(c(1:99),4, F);
  
  # x[1] == max(x)
  ((x[[1]] > x[[2]]) & (x[[1]]) > x[[3]]) & (x[[1]] > x[[4]])
}

res <- replicate(100000, sim.balls())
sum(res)/length(res)


# 15

sim.people <- function(){
  x <- c(paste0('p',3:20), 'Иван', "Георги");
  x
  l <- sample(x,20, F)
  
  index1 <- which(l == 'Иван')
  index2 <- which(l == 'Георги')
  
  abs(index1 - index2) == 1
}

res <- replicate(100000, sim.people())

sum(res)/length(res)



# 16

sim.ace <- function(){
  x <- c(rep('a',4),rep(0,48));
 
  lis <- sample(x,52,F); 
  
  l1 <- lis[seq(1,52,4)]
  l2 <- lis[seq(2,52,4)]
  l3 <- lis[seq(3,52,4)]
  l4 <- lis[seq(4,52,4)]
  
  any(l1 == 'a') & any(l2 == 'a') &any(l3 == 'a') & any(l4 == 'a')
}

res <- replicate(10000,sim.ace())

sum(res)/length(res)


# 17
# 7 people, 15 floors
sim.elevator <- function(){
  x <- sample(c(1:16),7,T)
  
  any(duplicated(x))
}

res <- replicate(200000, sim.elevator())
sum(res)/length(res)


# b)

sim.elevator.b <- function(){
  x <- sample(c(1:15),6,T)
  
  b <- sample(c(1:15),1)
  
  any(x[1:6] == b)
}

res <- replicate(200000, sim.elevator.b())
sum(res)/length(res)



