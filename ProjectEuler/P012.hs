module P012 where

import Data.List
import P003

firstTriNumOver :: Int -> Int
firstTriNumOver n = sum [1..index]
  where
    index = head . dropWhile (\k -> (numDivisors . triNum $ k) <= n) $ [1..]

triNum :: Int -> [(Int, Int)]
triNum n = fmap (\x -> (x !! 0, if x !! 0 == 2 then length x - 1 else length x)) . group $ (merge (primeFactors n) (primeFactors $ n + 1))
  where
    merge x y = sort $ x ++ y

numDivisors :: [(Int, Int)] -> Int
numDivisors [] = 1
numDivisors (x:xs) = (snd x + 1) * numDivisors xs
