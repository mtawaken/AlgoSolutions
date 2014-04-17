"""
Square digit chains
Problem 92
A number chain is created by continuously adding the square of the digits in a
number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless
loop. What is most amazing is that EVERY starting number will eventually arrive
at 1 or 89.

How many starting numbers below ten million will arrive at 89?
"""
__date__ = '14-4-17'
__author__ = 'SUN'

def square_digits_sum(n):
    return sum(int(c) ** 2 for c in str(n))

def square_end_with(n):
    while square_digits_sum(n) != 1 and square_digits_sum(n) != 89:
        n = square_digits_sum(n)
    return n

if __name__ == '__main__':
    print(square_digits_sum(89))