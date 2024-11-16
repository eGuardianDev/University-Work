import Data.List

hasIncDigits :: Int -> Bool
hasIncDigits n = show n == (sort $ show n) 


main = do
    print $ hasIncDigits 1244 == True
    print $ hasIncDigits 12443 == False 
    print $ hasIncDigits 1203 == False -- my test