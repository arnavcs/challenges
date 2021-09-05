module P007 where

nthPrime :: Int -> Int
nthPrime n = allPrimes !! (n - 1)

allPrimes :: [Int]
allPrimes = sieve [2..] where
  sieve (p:xs) = p : sieve (filter (\x -> mod x p > 0) xs)
