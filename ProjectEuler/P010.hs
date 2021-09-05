module P10 where

import P7

sumOfPrimesBelow :: Int -> Int
sumOfPrimesBelow n = sum . takeWhile (< n) $ allPrimes
