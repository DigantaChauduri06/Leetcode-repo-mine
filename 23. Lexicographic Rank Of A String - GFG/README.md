# 23. Lexicographic Rank Of A String
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You are given a string <strong>S </strong>of lowercase characters, find the <strong>rank </strong>of the string amongst its permutations when sorted lexicographically. <strong>Return 0 if the characters are repeated in the string</strong>.<br>
<strong>Note: </strong>Return the rank%1000000007<strong> </strong>as the answer as rank might overflow. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = abc
<strong>Output: </strong>1<strong>
Explanation: </strong></span><span style="font-size:18px">In 'abc' when we sort all the
permutations in lexicographic order 'abc'
will be at the first position.</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = acb
<strong>Output: </strong>2<strong>
Explanation: </strong>In 'acb' .</span><span style="font-size:18px">The
lexicographically sorted permutations
with letters 'a', 'c', and 'b' will be
at second position.&nbsp;</span>
</pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You only need to complete the function <strong>findRank </strong>that takes string <strong>S</strong> as a parameter and returns<strong> </strong>the rank.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span><br>
<span style="font-size:18px">1 ≤ |S| ≤ 26</span></p>

<p>&nbsp;</p>
 <p></p>
            </div>