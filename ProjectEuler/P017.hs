module P017 where

numOfCharsTill :: Int -> Int
numOfCharsTill n = sum . map layerThree $ [1..n]

layerOne :: Int -> Int
layerOne n
    | n == 1    = length "one"
    | n == 2    = length "two"
    | n == 3    = length "three"
    | n == 4    = length "four"
    | n == 5    = length "five"
    | n == 6    = length "six"
    | n == 7    = length "seven"
    | n == 8    = length "eight"
    | n == 9    = length "nine"
    | n == 10   = length "ten"
    | n == 11   = length "eleven"
    | n == 12   = length "twelve"
    | n == 13   = length "thirteen"
    | n == 14   = length "fourteen"
    | n == 15   = length "fifteen"
    | n == 16   = length "sixteen"
    | n == 17   = length "seventeen"
    | n == 18   = length "eighteen"
    | n == 19   = length "nineteen"
    | otherwise = 0

layerTwo :: Int -> Int
layerTwo n
    | n < 20    = layerOne n
    | n < 30    = length "twenty"  + layerOne (n `rem` 10)
    | n < 40    = length "thirty"  + layerOne (n `rem` 10)
    | n < 50    = length "forty"   + layerOne (n `rem` 10)
    | n < 60    = length "fifty"   + layerOne (n `rem` 10)
    | n < 70    = length "sixty"   + layerOne (n `rem` 10)
    | n < 80    = length "seventy" + layerOne (n `rem` 10)
    | n < 90    = length "eighty"  + layerOne (n `rem` 10)
    | n < 100   = length "ninety"  + layerOne (n `rem` 10)
    | otherwise = 0

layerThree :: Int -> Int
layerThree n
    | n < 100          = layerTwo n
    | n == 1000        = length "onethousand"
    | n `rem` 100 == 0 = layerOne (n `div` 100) + length "hundred"
    | n < 1000         = layerOne (n `div` 100) + length "hundredand" + layerTwo (n `rem` 100)
    | otherwise        = 0
