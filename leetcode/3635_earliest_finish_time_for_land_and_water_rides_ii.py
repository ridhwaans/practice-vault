class Solution:

    def finishTime(
        self,
        firstStartTime: List[int],
        firstDuration: List[int],
        secondStartTime: List[int],
        secondDuration: List[int],
    ) -> int:
        # go land ride first
        # n^2 to n optimization: finding min landride start time to avoid computing for every inner ride and because ride list is not necesssarily sorted time ascending
        # mistake - INF is not defined. use float("inf") or 10 ** 20
        finishTime = 10**20
        startTime = 10**20
        for idx, val in enumerate(secondStartTime):
            startTime = min(startTime, val + secondDuration[idx])
            # startTime now ends the earliest (aka landEnds) greedy
        # go water ride first
        for idx, val in enumerate(firstStartTime):
            if val >= startTime:
                # finishTime = min(startTime, val + firstDuration[idx])
                finishTime = min(finishTime, val + firstDuration[idx])
            else:
                finishTime = min(finishTime, startTime + firstDuration[idx])
        return finishTime

    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int],
    ) -> int:
        # try land first water second and reverse order
        # mistake - add self to finishTime because it is a class method not a standalone func
        return min(
            self.finishTime(landStartTime, landDuration, waterStartTime, waterDuration),
            self.finishTime(waterStartTime, waterDuration, landStartTime, landDuration),
        )
