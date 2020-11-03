/*
Daily Coding Problem: Problem #18

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
*/

fun1 = function(array, k){
    let maxes = []
    for (i = 0; i < array.length-1; i++){
        let j = i + k;
        if (j > array.length){
            break;
        }
        console.log(`[${array.slice(i,j)}]`);
        maxes.push(Math.max(...array.slice(i,j)))
    }
    return maxes;
}
console.log(fun1([10, 5, 2, 7, 8, 7], 3));

/*
Time complexity is O(n)  
Space complexity is O(k)  

See also:
https://www.youtube.com/watch?v=MK-NZ4hN7rs
*/
