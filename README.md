# pre-test

Q1.
In order to use the binary search, I do the merage sort first. Assume array 1 has n elements, then the time complexity is O(nlogn).
Then, for all element in array 2, say, there are m element in array 2, I do the binary search to check that element in array 2 indeed also belong to array1.
So, the time complexity is O(mlog n) because I do m times.
The total time complexity is O((m+n)logn).

Q2.
For get(key), the time complexity should be O(1). 
For put (key), we need to check all element in the dict() with size n, so the time complexity should be O(n).

Q3.
arr[i] = function(x) { return x + i; }
This is the statment that make trouble.The computer don't know what is x. If I change arr[i] = function, then create function like :
function F(x,j){
    return x+j;
}
The code can run correctly.
The code also provided in github.
