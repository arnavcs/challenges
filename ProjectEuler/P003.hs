module P003 where

largestPrimeFactor :: Int -> Int
largestPrimeFactor = maximum . primeFactors

primeFactors :: Int -> [Int]
primeFactors = tryFactor 2
  where
    tryFactor :: Int -> Int -> [Int]
    tryFactor p n
      | p * p > n      = [n]
      | n `mod` p == 0 = p:(tryFactor p (n `div` p))
      | otherwise      = tryFactor (p + 1) n
