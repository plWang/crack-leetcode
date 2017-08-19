## Problem 
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.


## Solution
使用BFS的方法。
把每个相差一个字母的单词定义为相邻的节点，那么整个问题可以用一个无向连接图来表示出来，那么最短ladderLength就是从beginWord到endWord的图中的最短路径。
使用BFS来遍历当前节点的所有相邻节点，最先到达endWord的路径就是最短路径。（由于本题只要求最短路径的长度，因此这样即可；如果要求所有可能的最短路径（如WordLadderII），那么处理方法会有所不同，要储存所有路径）。
