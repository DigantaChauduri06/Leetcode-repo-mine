# 12. Maximum Water Between Two Buildings
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an integer array representing&nbsp;the heights of N buildings, the task is to delete N-2 buildings such that the water that can be trapped between the remaining two building is maximum.<br>
<strong>Note:&nbsp;</strong>The total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of the smaller building. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 6
height[] = {2,1,3,4,6,5}
<strong>Output: </strong>8<strong>
Explanation: </strong>The heights are 2 1 3 4 6 5.
So we choose the following buildings
<strong>2,</strong><strong>5&nbsp; </strong>and remove others. Now gap between 
two buildings is equal to 4, and the
height of smaller one is 2. So answer is
2 * gap = 2*4 = 8. There is
no answer greater than this.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 2
height[] = {2,1}
<strong>Output: </strong>0<strong>
Explanation: </strong>The heights are 2 1.
But there is no other buildings to be 
removed so total removed= 0.&nbsp; 
Now the height of smaller one is 2.
So answer is 2 * removed buildings = 2*0
= 0.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You need to<strong> complete the function maxWater</strong> that takes height array and size N as <strong>parameters </strong>and <strong>returns </strong>the max water that can be stored. The printing is done by the driver code.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= height<sub>i </sub>&lt;= 10<sup>6</sup><br>
1 &lt;= N &lt;= 10<sup>5</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>