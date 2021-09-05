module P014 where

import Data.List
import Data.Ord

longestCollatzChainUnder :: Int -> Int
longestCollatzChainUnder n = snd . (\xs -> maximumBy (comparing fst) (zip xs [1..])) . (fmap collatzChainLength) $ [1..n]

collatzChainLength :: Int -> Int
collatzChainLength 1 = 1
collatzChainLength n
    | even n    = 1 + collatzChainLength (n `div` 2)
    | otherwise = 1 + collatzChainLength (3 * n + 1)
