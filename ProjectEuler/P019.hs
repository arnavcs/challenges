module P019 where

-- formula Zeller's Congruence
dayOfWeek :: Int -> Int -> Int -> Int
dayOfWeek y m q = (q + ((13 * (m' + 1)) `div` 5) + k + (k `div` 4) + (j `div` 4) - 2 * j) `mod` 7
    where
        (j, k) = y `divMod` 100
        m' = ([13, 14] ++ [3..12]) !! (m - 1)

numFirstSundaysDuring :: (Int, Int) -> Int
numFirstSundaysDuring (y, y') = length . filter (==1) $ (dayOfWeek <$> [y..y'] <*> [1..12] <*> pure 1)
