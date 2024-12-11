KthSmallestInBST: KthSmallestInBST.o
	g++ -g -o KthSmallestInBST.exe KthSmallestInBST.o -pthread    

KthSmallestInBST.o: KthSmallestInBST/KthSmallestInBST.cpp
	g++ -g  -c -pthread KthSmallestInBST/KthSmallestInBST.cpp
