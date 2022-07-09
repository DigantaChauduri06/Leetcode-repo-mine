# 11. Smaller on Right
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>arr</strong>[] of <strong>N</strong> elements. The task is to count maximum number&nbsp;of distinct smaller elements on right side of any array element. For example, in {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}, the result is 4.&nbsp; Note that 20 has maximum 4 smaller elements on right side. Other elements have less count, for example 10 has 3 smaller elements on right side.</span></p>

<p><span style="font-size:18px"><strong>Example:</strong></span></p>

<pre><span style="font-size:18px"><strong>
Input:</strong>
4
10
10 6 9 7 20 19 21 18 17 16
5
5 4 3 2 1
5
1 2 3 4 5</span>
<span style="font-size:18px">5
1 2 3 2 1</span>

<span style="font-size:18px"><strong>Output:</strong>
4
4
0
2</span>

<span style="font-size:18px"><strong>Explanation:</strong></span>

<span style="font-size:18px"><strong>Testcase 1:</strong> Number of smaller elements on right side of every element (from left to right)
 in the array are 3 0 1 0 4 3 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.
<strong>Testcase 2:</strong> Number of smaller elements on right side of every element (from left to right) 
in the array are 4 3 2 1 and 0 respecitvely. Maximum of all these counts is 4.</span></pre>

<p><span style="font-size:18px"><strong>Input:</strong><br>
The first line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and next line contains array elements.</span></p>

<p><span style="font-size:18px"><strong>Output:</strong><br>
For each testcase, print the maximum count of smaller elements on right side. </span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= T &lt;= 100<br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>