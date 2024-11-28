

revOneLine :: Int -> Int
revOneLine = helper 0
 where 
    helper :: Int -> Int -> Int
    helper leftover 0 = leftover
    helper leftover n = helper (leftover*10 + mod n 10) (div n 10)

revOneLineMagic :: Int -> Int
revOneLineMagic = read . reverse . show 


sumDivsOneLineLC :: Int -> Int
sumDivsOneLineLC n= sum [x | x<-[1..n], mod n x == 0]


sumDivsOneLineHOF :: Int -> Int
sumDivsOneLineHOF n = sum $ filter (\x -> mod n x == 0) [1..n]

primeOneLineLC :: Int -> Bool
primeOneLineLC n = [1, n] == [x | x<- [1..n], mod n x == 0 ]


primeOneLineHOF :: Int -> Bool
primeOneLineHOF n = [1,n] == filter (\x -> mod n x == 0 ) [1..n]

main = do
    print $ revOneLine 123 == 321
    print $ revOneLineMagic 123 == 321

    print $ sumDivsOneLineLC 6 == 12
    print $ sumDivsOneLineHOF 6 == 12

    print $ primeOneLineLC 6 == False
    print $ primeOneLineLC 17 == True

    print $ primeOneLineHOF 6 == False
    print $ primeOneLineHOF 17 == True