require "./math.rb"

describe "fib_iterative" do
	it "can get the fibonacci sequence for 5 numbers" do
		expect((0..5).map {|i| fib_iterative(i)}).to eq([0,1,1,2,3,5])
		expect((0..5).map {|i| fib_iterative(i)}[-2]).to eq(3)
	end
end

describe "fib_recursive" do
	it "can get the fibonacci sequence for 5 numbers" do
		expect((0..5).map {|i| fib_recursive(i)}).to eq([0,1,1,2,3,5])
	end
end

describe "prime_iterative" do
	it "can get the first 10 prime numbers" do
		expect(prime_iterative 10).to eq([2, 3, 5, 7, 11, 13, 17, 19, 23, 29])
	end
end

describe "prime_recursive" do
	it "can get prime numbers up to 50" do
		expect(prime_recursive(50)).to eq([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47])
	end
end

describe "factorial" do
	it "can get 5!" do
		expect(factorial(5)).to eq(120)
	end
end