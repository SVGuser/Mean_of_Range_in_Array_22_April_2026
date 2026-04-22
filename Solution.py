class Solution:
    def findMean(self, arr, queries):
        n = len(arr)
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i+1] = pre[i] + arr[i]
        res = []
        for k, g in queries:
            al = pre[g + 1] - pre[k]
            lgt = g - k + 1
            mean = al // lgt
            res.append(mean)
        return res
