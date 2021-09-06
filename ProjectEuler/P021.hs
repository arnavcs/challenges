module P021 where

sumOfProperDivisors :: Int -> Int
sumOfProperDivisors n = sum [ k | k <- [1..n-1], n `rem` k == 0 ]

amicableNumbersUnder :: Int -> [Int]
amicableNumbersUnder n = [ k | k <- [1..n-1], (sumOfProperDivisors . sumOfProperDivisors $ k) == k, sumOfProperDivisors k /= k ]
