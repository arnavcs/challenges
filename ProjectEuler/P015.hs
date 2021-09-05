module P015 where

numRoutes :: Integer -> Integer -> Integer
numRoutes a b = product [1+a..a+b] `div` product [1..b]
