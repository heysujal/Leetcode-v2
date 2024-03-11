class Solution:
    # @return an integer
    def divide(self, dividend, divisor):
        if divisor == 1:
            count = dividend
        elif divisor == -1:
            count = -dividend
        else:
            count = 0
            div1 = abs(dividend)
            div2 = abs(divisor)
            diff = div1 - div2
            while diff >= div2:
                count += 1
                diff -= div2
        
            if dividend < 0 and divisor > 0 or dividend > 0 and divisor < 0:
                count = -count
        
        return count