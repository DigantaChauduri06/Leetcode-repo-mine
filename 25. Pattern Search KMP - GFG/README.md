# 25. Pattern Search KMP
## Hard 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a string <strong>S</strong> and a pattern <strong>P</strong> of all lowercase characters. The task is to check if the pattern exists in the string or not.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = aabaacaadaabaaba
P = aaaab
<strong>Output: </strong>No<strong>
Explanation: </strong>Given pattern is not found
in the given string S.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = aabaacaadaabaaba
P = caada
<strong>Output: </strong>Yes<strong>
Explanation: </strong>Given pattern is found in
the given string S.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>KMPSearch</strong>() which returns true or false depending on whether pattern is present in the string or not,&nbsp;and <strong>computeLPSArray</strong>() which computes the longest prefix suffix for every index.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N+M).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(M).<br>
Note: N = |S|, M = |P|.</span></p>

<p><span style="font-size:18px"><strong>Constrsaints:</strong><br>
1 &lt;= |S|, |P| &lt;= 10<sup>4</sup></span></p>
 <p></p>
            </div>