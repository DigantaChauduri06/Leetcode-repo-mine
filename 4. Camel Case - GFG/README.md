# 4. Camel Case
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a dictionary of words <strong>dict </strong>where each word follows CamelCase notation, print all words in the dictionary that match with a given <strong>pattern </strong>consisting of uppercase characters only.<br>
<em>CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include: “PowerPoint” and “WikiPedia”, “GeeksForGeeks”, “CodeBlocks”, etc.</em><br>
<br>
<strong>Note: </strong>The order should be such that the output strings should be sorted by the lexicographic order of their abbreviations. For strings with same abbreviations the strings should be sorted by the usual lexicographic order. So, if Output Strings are Hi and HelloWorld, Hi should come first as H lexiographically is smaller than HW.</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">n = 8
dict[] = {Hi,Hello,HelloWorld,HiTech
HiGeek,HiTechWorld,HiTechCity,HiTechLab}
pattern = HA
<strong>Output: </strong>No match found</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">n = 3
dict[]={WelcomeGeek,WelcomeToGeeksForGeeks
GeeksForGeeks}
pattern = WTG
<strong>Output: </strong>WelcomeToGeeksForGeeks<strong>
Explanation: </strong>WTG occurs in
<strong>W</strong>elcome<strong>T</strong>o<strong>G</strong>eeksForGeeks.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Complete <strong>findAllWords()&nbsp;</strong>function and print as mentioned. If the pattern is not found, print "<strong>No match found"</strong> (without quotes) in the function itself. The new line is provided by the driver code.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N * WORD_LEN).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N * WORD_LEN).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 100<br>
1 &lt;= length of pattern &lt;= length of string &lt;= 100</span></p>
 <p></p>
            </div>