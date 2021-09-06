module P020 where

import P016

numDigitsInFactorial :: Int -> Int
numDigitsInFactorial = (\x -> digitSum . product . take x $ [1..])
