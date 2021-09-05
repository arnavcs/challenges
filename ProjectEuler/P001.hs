module P1 where

sumOfMultiplesLessThan :: [Int] -> Int -> Int
sumOfMultiplesLessThan xs n = sum [k | k <- [1 .. (n-1)], isMultiple k xs]

isMultiple :: Int -> [Int] -> Bool
isMultiple n [] = False
isMultiple n (x:xs) = (n `mod` x == 0) || isMultiple n xs
