import Data.Char
 

reduceStr :: String -> String
reduceStr [] = []
reduceStr [a] = [a]
reduceStr (a:b:xs) = helper [a] (b:xs)
 where 
  helper :: String -> String -> String
  helper stack [] = reverse stack
  helper (x:stack) (y:input)
   | x == chr (ord y - 32) || x == chr(ord y + 32) = helper stack input
   | otherwise =  helper (y:x:stack) input



main = do 
    print $ reduceStr "dabAcCaCBAcCcaDD" == "dabCBAcaDD"
    print $ reduceStr "AeeaAbsSB" == "Aee" -- my test