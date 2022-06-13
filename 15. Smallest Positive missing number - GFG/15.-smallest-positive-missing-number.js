// { Driver Code Starts
//Initial Template for javascript
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let arr = new Array(n);
        let input_ar = readLine().split(' ').map(x=>parseInt(x));
        for(let i=0;i<n;i++)
            arr[i] = input_ar[i];
        let obj = new Solution();
        console.log(obj.missingNumber(arr, n));
        
    }
}// } Driver Code Ends


/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {number}
*/

class Solution
{
    //Function to find the smallest positive number missing from the array.
    missingNumber(arr, n) {
        //your code here
        const st = new Set();
        for (let num of arr) {
            st.add(num);
        }
        for (let i = 1;i <= arr.length;i++) {
            if (!st.has(i)) return i;
        }
        return Math.max(...arr)+1;
    }
}