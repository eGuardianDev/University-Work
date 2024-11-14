
fibIter :: Int -> Int
fibIter n = helper 0 1 n
 where
    helper :: Int -> Int -> Int -> Int
    helper a _ 0 = a
    helper _ b 1 = b
    helper a b n = helper b (a + b) (n-1)

fibRec :: Int -> Integer
fibRec 0 = 0
fibrec 1 = 1
fibrec n = fibrec (n-1) + fibrec (n-2)

main = do
    print $ fibRec 11 == 89
    print $ fibIter 11 == 89
    print $ fibIter 110 == 43566776258854844738105