
reverseNumber :: Int -> Int
reverseNumber = helper 0
 where
    helper result 0 = result
    helper result leftover = helper (result * 10 + mod leftover 10) (div leftover 10)

isPalindrome :: Int -> Bool
isPalindrome n = if n<0 then error "Input must be positive number" else reverseNumber n == n 


main = do
    print $ isPalindrome 6 == True
    print $ isPalindrome 1010 == False
    print $ isPalindrome 505 == True
    print $ isPalindrome 123321 == True
    print $ isPalindrome 654 == False
    print $ isPalindrome 01233210 == False -- my test