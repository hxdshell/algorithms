# Since we are performing large integer multiplication, we might as well do it in Python
from math import ceil,log10

def karatsuba(a: int,b: int) -> int:
    if(a < 10 or b < 10):
        return a * b
    
    maxlen = max(int(ceil(log10(a))),int(ceil(log10(b))))
    m = maxlen // 2

    # Split
    high1 = low1 = high2 = low2 = 0
    divisor = 10 ** m

    high1 = a // divisor
    low1 = a % divisor

    high2 = b // divisor
    low2 = b % divisor

    z0 = karatsuba(low1,low2)
    z1 = karatsuba(high1 + low1, high2 + low2)
    z2 = karatsuba(high1,high2)


    return (z2 * (10 ** (m * 2))) + ((z1 - z2 - z0) * (10 ** m)) + z0

# Test
a = int(input("Enter num1 : "))
b = int(input("Enter num2 : "))

assert (x := karatsuba(a,b)) == (a * b)

print(x)

