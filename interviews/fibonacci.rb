def fib(n)
   n <= 2 ? 1 : fib(n - 1) + fib(n - 2)
end
(1..20).each { |n| puts fib(n) }

# TODO add test cases