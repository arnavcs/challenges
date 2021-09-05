module P004 where

largestPalindromeProduct :: Int -> Int
largestPalindromeProduct = maximum . filter isPalindrome . allProducts

isPalindrome :: Int -> Bool
isPalindrome n = n == flip n 0
  where 
    flip :: Int -> Int -> Int
    flip 0 b = b
    flip a b = let (q, r) = a `quotRem` 10 in flip q (10 * b + r)

allProducts :: Int -> [Int]
allProducts k = (*) <$> allDigits <*> allDigits
  where
    allDigits = [10 ^ (k - 1) .. 10 ^ k - 1]
