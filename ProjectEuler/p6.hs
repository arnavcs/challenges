module P6 where

sumSquareDifference :: Int -> Int
sumSquareDifference n = (subtract) <$> sumOfSquare <*> squareOfSum $ [1 .. n]

squareOfSum :: [Int] -> Int
squareOfSum a = (sum a) ^ 2

sumOfSquare :: [Int] -> Int
sumOfSquare = sum . map (^2)
