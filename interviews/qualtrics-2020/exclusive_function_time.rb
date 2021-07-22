# Suppose you have a single threaded computer which can execute functions one at a time each with a start and end timestamp.  
# There can be child functions which overlapp over larger functions.  
# Find the exclusive time for each individual function(s)

# Example:
# Input: n = 2 
# logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
# Output: [3,4]

# Assumptions:
# 1 <= n <= 100
# Two functions wont start or end at the same time
# Functions will always log when they exit

def exclusive_function_time(n, timestamps)
    ftimes = [0] * n
    stack = [] # the ids of function calls
    prev_start_time = 0
    
    timestamps.each do |stamp|
        fid, event, ftime = stamp.split(":")
        fid, ftime = fid.to_i, ftime.to_i

        if event == 'start'
            if stack.any?
                ftimes[stack[-1]] += ftime - prev_start_time
            end
            stack << fid
            prev_start_time = ftime
        else
            ftimes[stack.pop()] += ftime - prev_start_time + 1
            prev_start_time = ftime + 1
        end
    end
    ftimes
end

p exclusive_function_time(2, ["0:start:0","1:start:2","1:end:5","0:end:6"])