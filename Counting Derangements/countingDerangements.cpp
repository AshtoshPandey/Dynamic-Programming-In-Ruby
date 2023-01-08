#include <iostream>
#include <stdio.h>
#include <map>
#include <chrono>
#include <ctime>

using namespace std;

class calculateDerangements {
	private:
		long dpArr[1000000];
		map<int, long> memoiserMap;
	public: 
		calculateDerangements() {
			dpArr[0] = 0;
			dpArr[1] = 0;
			dpArr[2] = 1;

			memoiserMap.insert({0, 0});
			memoiserMap.insert({1, 0});
			memoiserMap.insert({2, 1});
		}

		long recursionWithoutMemoisation(long n) {
			if (n <= 0) {
				return 0;
			}
			if (n <= 2) {
				return n - 1;
			}
			return (n - 1) * (recursionWithoutMemoisation(n - 1) + recursionWithoutMemoisation(n - 2));
		}

		long recursionWithMemoisation(long n) {
			if (n <= 0) {
				return 0;
			}
			if (memoiserMap.count(n)) {
				return memoiserMap[n];
			}
			long derangementCount = (n - 1) * (recursionWithMemoisation(n - 1) + recursionWithMemoisation(n - 2));
			memoiserMap.insert({n, derangementCount});
			return derangementCount;
		}

		int dpCalculator(long n) {
			for (long i = 3; i <= n; i++) {
				dpArr[i] = (i - 1) * (dpArr[i-1] + dpArr[i - 2]);
			}
			return dpArr[n];
		}
};

int main() {
	calculateDerangements* derangementCalculator = new calculateDerangements();
	long n = 10;
	
	// Below calculcate the derangement count with plain recursion, and prints the time taken in seconds
	// auto recursiveStart = std::chrono::system_clock::now();
	long recursiveAnswer = derangementCalculator->recursionWithoutMemoisation(n);
	// auto recursiveEnd = std::chrono::system_clock::now();
	// auto timeTakenByRecursion = recursiveEnd - recursiveStart;
	cout<<"Recursive Answer: "<<recursiveAnswer<<". Time taken by Recursion: ";
	// Add: <<timeTakenByRecursion.count()<<endl; if you need timecheck
	
	// Below calculcate the derangement count with plain recursion, and prints the time taken in seconds
	// auto recursiveMemoisedStart = std::chrono::system_clock::now();
	long memoisedRecursiveAnswer = derangementCalculator->recursionWithMemoisation(n);
	// auto RecursiveMemoisedEnd = std::chrono::system_clock::now();
	// auto timetTakenByMemoisation = RecursiveMemoisedEnd - recursiveMemoisedStart;
	cout<<"Memoised Answer: "<<recursiveAnswer<<". Time taken by Memoisation: ";
	// Add: <<timetTakenByMemoisation.count()<<endl; if you need timecheck
	
	// Below calculcate the derangement count with DP, and prints the time taken in seconds
	// auto dpStart = std::chrono::system_clock::now();
	long dpAnswer = derangementCalculator->dpCalculator(n);
	// auto dpEnd = std::chrono::system_clock::now();
	// auto timeTakenByDP = dpEnd - dpStart;
	cout<<"DP Answer: "<<recursiveAnswer<<". Time taken by Recursion: ";
	// Add: <<timeTakenByDP.count()<<endl; if you need timecheck
}
