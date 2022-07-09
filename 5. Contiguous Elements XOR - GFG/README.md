# 5. Contiguous Elements XOR
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given an array <strong>arr</strong>[] of <strong>N</strong> positive integers. This time you are supposed to choose numbers from a contiguous sub-sequence of the given array, so that <a href="https://www.geeksforgeeks.org/find-xor-of-two-number-without-using-xor-operator/" target="_blank"><strong>BITWISE XOR</strong></a> of all the chosen numbers is maximum.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 4
arr[] = {8,1,2,12}
<strong>Output: </strong>15<strong>
Explanation: 1</strong>, <strong>2</strong> and <strong>12</strong> can be chosen
from the array as contiguous sub
sequence which given us maximum
XOR value equal to 15.</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">N = 4
arr[] = {1,2,3,4}
<strong>Output: </strong>7<strong>
Explanation: 3</strong> and <strong>4</strong> from the array
can be chosen&nbsp; as contiguous sub
sequence which given us maximum XOR
value equal to 7.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Complete <strong>maxSubarrayXOR&nbsp;</strong>function and return&nbsp;the maximum XOR value.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>5</sup><br>
1 &lt;= arr[i] &lt;= 10<sup>6</sup> (Must be in range of 32 bits signed integer)</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity</strong> : O(NlogN)<br>
<strong>Expected Auxilliary Space </strong>: O(N)</span></p>
 <p></p>
            </div>