
// Leetcode 719. Find K-th Smallest Pair Distance
var smallestDistancePair = function (nums, k) {
    const max = Math.max(...nums);

    const diff = new Array(max + 1).fill(0);
    const n = nums.length;

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            let df = Math.abs(nums[i] - nums[j]);
            diff[df]++;
        }
    }

    for (let i = 0; i < max + 1; i++) {
        k -= diff[i];
        if (k <= 0) return i;
    }

    return 0;
};
