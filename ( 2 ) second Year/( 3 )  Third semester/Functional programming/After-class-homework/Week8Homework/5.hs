import GHC.RTS.Flags (DebugFlags(weak))


reverseOrdSuff :: Int -> Int
reverseOrdSuff a = helper (mod a 10) (div a 10)
 where
    helper :: Int -> Int -> Int
    helper x y
     | y < 10 = (x*10 + y)
     | mod y 10 > mod x 10 = helper (x*10 + (mod y 10)) (div y 10)
     | mod y 10 == mod x 10 = helper x (div y 10)
     | otherwise = x


main = do
    print $ reverseOrdSuff 37563 == 36
    print $ reverseOrdSuff 32763 == 367
    print $ reverseOrdSuff 32567 == 7
    print $ reverseOrdSuff 32666 == 6
    print $ reverseOrdSuff 1230 == 3 -- my test