module P009 where

prodPythagSummingTo :: Int -> Int
prodPythagSummingTo n = let [(a, b, c)] = pythagSummingTo n in a * b * c

pythagSummingTo :: Int -> [(Int, Int, Int)]
pythagSummingTo n = [(a, b, c) | a <- [1 .. n], b <- [a .. n], c <- [n - a - b], a < b, b < c, a^2 + b^2 == c^2]
