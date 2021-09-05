module P010 where

import P007

sumOfPrimesBelow :: Int -> Int
sumOfPrimesBelow n = sum . takeWhile (< n) $ allPrimes
