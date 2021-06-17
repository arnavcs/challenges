module P5 where

smallestMultipleOfFirst :: Int -> Int
smallestMultipleOfFirst n = smallestMultiple [1 .. n]

smallestMultiple :: [Int] -> Int
smallestMultiple = foldr lcm 1
