class Solution:
    def canArrange(self, arr: list[int], k: int) -> bool:
        count = [0] * k

        for x in arr:
            x %= k
            if x < 0:
                x += k
            count[x] += 1

        if count[0] % 2 != 0:
            return False

        for i in range(1, (k // 2) + 1):
            if count[i] != count[k - i]:
                return False

        return True