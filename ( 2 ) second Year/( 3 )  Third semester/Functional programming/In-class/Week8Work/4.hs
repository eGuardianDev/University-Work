
sumUnevenLC :: Int -> Int -> Int
sumUnevenLC a b =  sum [x | x<-[min a b .. max a b], odd x ]

sumUnevenHOF :: Int -> Int -> Int
sumUnevenHOF a b = sum $ filter odd [min a b .. max a b]
main = do
    print $ sumUnevenLC 5 50 == 621
    print $ sumUnevenLC 50 1 == 625
    print $ sumUnevenLC 564 565 == 565

    print $ sumUnevenHOF 5 50 == 621
    print $ sumUnevenHOF 50 1 == 625
    print $ sumUnevenHOF 564 565 == 565