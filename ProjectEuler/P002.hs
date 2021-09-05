module P002 where

sumEvenFibonacciNumbersLessThan :: Int -> Int
sumEvenFibonacciNumbersLessThan = sum . filter (even) . fibonacciLessThan 

fibonacciLessThan :: Int -> [Int]
fibonacciLessThan n = takeWhile (<= n) $ allFibonacci 

allFibonacci :: [Int]
allFibonacci = [fib k | k <- [1..]]
  where
    fib :: Int -> Int
    fib 1 = 1
    fib 2 = 2
    fib n = fib (n-1) + fib (n-2)
