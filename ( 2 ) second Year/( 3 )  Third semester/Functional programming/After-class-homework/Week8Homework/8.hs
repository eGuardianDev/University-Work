
import Data.Char

reduceStr :: String -> String
reduceStr a = helper "" a
 where 
    helper :: String -> String -> String
    helper toReturn [] = toReturn
    helper toReturn (x:y:xs)
      | x== toLower y || y == toLower x = helper toReturn (y:xs)
      | otherwise = helper (x:toReturn) (y:xs) 

main = do 
    print $ reduceStr "dabAcCaCBAcCcaDD" == "dabCBAcaDD"