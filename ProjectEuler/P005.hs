module P005 where

smallestMultipleOfFirst :: Int -> Int
smallestMultipleOfFirst n = smallestMultiple [1 .. n]

smallestMultiple :: [Int] -> Int
smallestMultiple = foldr lcm 1
