
sqAvg :: Int -> Int -> Double
sqAvg x y = (fromIntegral x ^2 + fromIntegral y ^2 )/2

main = do
    print $ sqAvg 5 0 == 12.5
    print $ sqAvg 10 13 == 134.5    
    print $ sqAvg 23 0 == 264.5 --my test