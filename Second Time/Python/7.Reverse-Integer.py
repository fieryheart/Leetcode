class Solution:
    def reverse(self, x: int) -> int:
        s = (x > 0) - (x < 0)
        r = int(str(s*x)[::-1])
        return (r < 2**31) * s * r