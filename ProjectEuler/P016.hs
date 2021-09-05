module P016 where

import Data.Char

digitSum :: Integer -> Int
digitSum = sum . map digitToInt . show
