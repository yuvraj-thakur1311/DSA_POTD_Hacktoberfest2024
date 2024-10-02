
// 1497. Check If Array Pairs Are Divisible by k

var canArrange = function (arr, k) {
    const count = new Array(k).fill(0);

    for (let i = 0; i < arr.length; i++) {
        ++count[arr[i] % k];
    }

    if (count[0] % 2 != 0) return false;

    for (let i = 1; i < k; i++) {
        if (count[i] != 0 && count[i] != count[k - i]) return false;
    }
    return true;
};