# misread problem - treated numbers like sequence but process the digits
# class Solution:
#     def totalWaviness(self, num1: int, num2: int) -> int:
#         peaks = 0
#         size = num2 - num1
#         for idx, val in enumerate(range(num1, num2)):
#             left = (idx > 0 and (val-1 < val))
#             right = ((idx < size-1) and val > val+1)
#             if (left and right):
#                 peaks += 1
#         return peaks


class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        peaksAndValleys = 0
        for val in range(num1, num2 + 1):
            if len(str(val)) < 3:
                continue
            s = str(val)
            for idx, strDigit in enumerate(s):
                if idx == 0 or idx == len(s) - 1:
                    continue
                digit = int(strDigit)
                # mistake fixed - str(val[idx-1]) TypeError: 'int' object is not subscriptable
                leftDigit = int(s[idx - 1])
                rightDigit = int(s[idx + 1])
                # mistake fixed - TypeError: '>' not supported between instances of 'int' and 'str'

                if leftDigit < digit and digit > rightDigit:
                    peaksAndValleys += 1
                if leftDigit > digit and digit < rightDigit:
                    peaksAndValleys += 1
        return peaksAndValleys
