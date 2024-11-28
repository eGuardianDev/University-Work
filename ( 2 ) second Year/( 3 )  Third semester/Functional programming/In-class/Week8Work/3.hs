rev :: Int -> Int
rev = read . reverse . show

isPalindrome :: Int -> Bool
isPalindrome n = n == rev n 

getPalindromesLC :: Int -> Int
getPalindromesLC n = let vars = [x | x <- [2..n], isPalindrome x && mod n x ==0 ]
                    in head vars + last vars
getPalindromesHOF :: Int -> Int
getPalindromesHOF n = head vars + last vars
                where vars = filter (\x -> mod n x ==0 && isPalindrome x)  [2..n]
main = do
    print $ getPalindromesLC 132465 == 8
    print $ getPalindromesLC 654546 == 8
    print $ getPalindromesLC 100001 == 100012
    print $ getPalindromesLC 21612 == 21614
    print $ getPalindromesLC 26362 == 26364

    print $ getPalindromesHOF 132465 == 8
    print $ getPalindromesHOF 654546 == 8
    print $ getPalindromesHOF 100001 == 100012
    print $ getPalindromesHOF 21612 == 21614
    print $ getPalindromesHOF 26362 == 26364