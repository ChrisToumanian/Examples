add :: Integer -> Integer -> Integer
add a b = a + b

sub :: Integer -> Integer -> Integer
sub a b =
    let c = a - b
    in c

isGreaterThan :: Integer -> Integer -> Bool
isGreaterThan a b =
    if a > b let o = true
    else let o = false
    in o

main = do
    putStrLn "Hello, World!"
    let x = round 6.59
    let y = 10
    print ((add x y) * (subtract y x))
    print (subtract y x)
	print (isGreaterThan x y)
