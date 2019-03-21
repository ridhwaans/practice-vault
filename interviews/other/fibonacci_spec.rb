require "./fibonacci.rb"

describe "fibonacci sequence" do
	it "can output the fibonacci sequence for 5 numbers" do
		expect((0..5).map {|i| fib(i)}).to eq([0,1,1,2,3,5])
		expect((0..5).map {|i| fib(i)}[-1]).to eq(5) # negative index refers to the last element
	end
end


