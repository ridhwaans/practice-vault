def fib_iterative(n)
  a = 0
  b = 1
  n.times do
    temp = a
    a = b
    b = temp + b
  end
  return a
end

puts (0..5).map {|i| fib_iterative(i)}

def fib_recursive(n)
   return n < 2 ? n : fib_recursive(n - 1) + fib_recursive(n - 2)
end

puts (0..5).map {|i| fib_recursive(i)}

@primes = []
def prime_iterative(n)
  i = 2
  while @primes.size < n do
    @primes << i if is_prime?(i)
    i += 1
  end
  @primes
end

def is_prime?(n)
  @primes.each { |prime| return false if n % prime == 0 }
  true
end

puts prime_iterative 15

def prime_recursive(n, primes=[])
	return primes.reverse if n < 2
  	primes << n if is_prime?(n)
  	prime_recursive(n - 1, primes)
end

def is_prime?(n)
	(2..Math.sqrt(n)).each { |i|
	if n % i == 0 && i < n
		return false
	end
	}
	true
end

puts prime_recursive 50

def factorial(n)
    if n == 0
        1
    else
        n * factorial(n-1)
    end
end

puts factorial(5)