Project 02: lsort
===================

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].


1.  STL: 
        average: n^2
        best: n^2
        worst: n^2


    QSORT:
        average: n^2
        best: n
        worst: n^2

    MERGE:
        average: nlogn
        best: nlogn
        worst: nlogn

    QUICK:
        average: nlogn
        best: nlogn
        worst: n^2

2.

	| Mode     | Size     | Elapsed Time       | Memory           |
	|----------|----------|--------------------|------------------|
	| STL      | 10       | 0.001998 seconds   | 1.171875 Mbytes  |
	| STL      | 100      | 0.001998 seconds   | 1.183594 Mbytes  |
	| STL      | 1000     | 0.001999 seconds   | 1.183594 Mbytes  |
	| STL      | 10000    | 0.001998 seconds   | 1.183594 Mbytes  |
	| STL      | 100000   | 0.001999 seconds   | 1.183594 Mbytes  |
	| STL      | 1000000  | 0.001999 seconds   | 1.183594 Mbytes  |
	| STL      | 10000000 | 0.001998 seconds   | 1.183594 Mbytes  |
	| QSORT    | 10       | 0.001999 seconds   | 1.171875 Mbytes  |
	| QSORT    | 100      | 0.001998 seconds   | 1.179688 Mbytes  |
	| QSORT    | 1000     | 0.001999 seconds   | 1.179688 Mbytes  |
	| QSORT    | 10000    | 0.001999 seconds   | 1.179688 Mbytes  |
	| QSORT    | 100000   | 0.001998 seconds   | 1.179688 Mbytes  |
	| QSORT    | 1000000  | 0.001999 seconds   | 1.179688 Mbytes  | 
	| QSORT    | 10000000 | 0.001999 seconds   | 1.179688 Mbytes  |
	| MERGE    | 10       | 0.001999 seconds   | 1.167969 Mbytes  |
	| MERGE    | 100      | 0.001999 seconds   | 1.175781 Mbytes  |
	| MERGE    | 1000     | 0.001999 seconds   | 1.175781 Mbytes  |
	| MERGE    | 10000    | 0.001999 seconds   | 1.175781 Mbytes  |
	| MERGE    | 100000   | 0.001998 seconds   | 1.175781 Mbytes  |
	| MERGE    | 1000000  | 0.001998 seconds   | 1.179688 Mbytes  |
	| MERGE    | 10000000 | 0.001999 seconds   | 1.175781 Mbytes  |
	| QUICK    | 10       | 0.001999 seconds   | 1.167969 Mbytes  |
	| QUICK    | 100      | 0.001998 seconds   | 1.179688 Mbytes  |
	| QUICK    | 1000     | 0.001998 seconds   | 1.175781 Mbytes  |
	| QUICK    | 10000    | 0.001999 seconds   | 1.175781 Mbytes  |
	| QUICK    | 100000   | 0.001999 seconds   | 1.175781 Mbytes  |
	| QUICK    | 1000000  | 0.001998 seconds   | 1.175781 Mbytes  |
	| QUICK    | 10000000 | 0.001998 seconds   | 1.175781 Mbytes  |

3. 
	* Based on the benchmark, all sorting methods performed about the same on elapsed time. However, differences can be seen in their space efficiency. The memory usage for stl is the worst with qsort close behind it. However, merge and quick sort seem to be better on space. Quick sort may be slightly better in memory usage than merge, based on the benchmark, but it's hard to tell.

	* There is definitely a relationship between theoretical complexity and actual performance, but based on these results, it may not be as much as our textbooks make us believe. The amount of data has to be very great in order to really see differences in performance.

	* I think quick sort is the best, because most of the time you won't have a presorted data set, keeping it from hitting its worst case time complexity. But often times, you will have immense amounts of data to sort, so even slightly better performance in memory management is a plus.

**Individual Contributions**
We did all of our code and discussion of the theoretical/actual performance as a group. Everyone contributed evenly to the coding of this project.

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists
