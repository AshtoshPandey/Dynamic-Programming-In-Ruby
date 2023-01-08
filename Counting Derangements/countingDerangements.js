const recursionWithoutMemoisation = function(n) {
    if (n <= 0) {
        return 0;
    }
    if (n <= 2) {
        return n -1;
    }
    return (n-1) * (recursionWithoutMemoisation(n - 1) + recursionWithoutMemoisation(n - 2));
}

const memoiser = {
    0: 0,
    1: 0,
    2: 1,
};

const recursionWithMemoiser = function(n) {
    if (n <= 0) {
        return 0;
    }
    if (memoiser[n]) {
        return memoiser[n];
    }
    const derangementCount = (n - 1) * (recursionWithMemoiser(n - 1) + recursionWithMemoiser(n - 2));
    memoiser[n] = derangementCount;
    return derangementCount;
}

const dpSolution = function (n) {
    const dpArr = [];
    dpArr[0] = 0;
    dpArr[1] = 0;
    dpArr[2] = 1;
    for(let i = 3; i <= n; i++) {
        dpArr[i] = (i-1) * (dpArr[i-1] + dpArr[i - 2]);
    }
    return dpArr[n];
}

const calculateDerangement = function(n) {
    // The below uses plain recursion to calculate the derangements, and shows the time taken in ms
    const timestampBeforePlainRecursion = Date.now();
    const recursiveAnswer = recursionWithoutMemoisation(n);
    const timeStampAfterPlainRecursion = Date.now();
    console.log(`Plain Recursion Answer: ${recursiveAnswer}. ` +
        `Time taken: ${timeStampAfterPlainRecursion - timestampBeforePlainRecursion}`)

    // The below uses memoisation to calculate the derangements, and shows the time taken in ms
    const timestampBeforeMemoisation = Date.now();
    const memoisedAnswer = recursionWithMemoiser(n);
    const timestampAfterMemoisation = Date.now();
    console.log(`Memoisation Answer: ${memoisedAnswer}. ` +
        `Time taken: ${timestampAfterMemoisation - timestampBeforeMemoisation}`);
    
    // The below uses Dynamic Programming to calculate the derangements, and shows the time taken in ms
    const timestampBeforeDP = Date.now();
    const dpAnswer = dpSolution(n);
    const timestampAfterDP = Date.now();
    console.log(`Memoisation Answer: ${dpAnswer}. ` +
    `Time taken: ${timestampAfterDP - timestampBeforeDP}`);
}

calculateDerangement(10);