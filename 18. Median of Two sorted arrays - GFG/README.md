# 18. Median of Two sorted arrays
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given two sorted arrays of sizes <strong>N</strong> and <strong>M</strong> respectively. The task is to find the median of the two arrays when they get merged.<br>
If&nbsp;there are even number of elements in the resulting array,&nbsp;find the floor of the average of two medians.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5, M = 6 
arr[] = {1,2,3,4,5}
brr[] = {3,4,5,6,7,8}
<strong>Output: </strong>4<strong>
Explanation: </strong>After merging two arrays, 
elements will be as 1 2 3 3 4 4 5 5 6 7 8
So, median is 4.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 2, M = 3 
arr[] = {1,2}
brr[] = {2,3,4}
<strong>Output: </strong>2<strong>
Explanation: </strong>After merging two arrays, 
elements will be as 1 2 2 3 4. So, 
median is 2.</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Complete&nbsp;<strong>findMedian()&nbsp;</strong>function which takes the two arrays and n and m as input parameters&nbsp;and returns&nbsp;their median. If&nbsp;there are total even elements,&nbsp;return floor of average of middle two elements.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(log(max(m,n)))<br>
<strong>Expected Auxilliary Space</strong> : O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N, M &lt;= 10<sup>6</sup><br>
1 &lt;= arr[i], brr[i] &lt;= 10<sup>7</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>