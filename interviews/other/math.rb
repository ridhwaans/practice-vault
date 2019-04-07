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

class Primes
  def initialize
    @primes = []
  end

  def prime_iterative(n)
  i = 2
  while @primes.size < n do
    @primes << i if is_prime?(i)
    i += 1
  end
  @primes
  end

  def prime_recursive(n)
    return @primes if n < 2
    prime_recursive(n - 1)
    @primes << n if is_prime?(n)
  end

  def is_prime?(n)
    @primes.each { |prime| return false if n % prime == 0 }
    true
  end
end

primes = Primes. new
puts primes.prime_recursive 10

def factorial(n)
  if n == 0
      1
  else
      n * factorial(n-1)
  end
end

puts factorial(5)