/*Author: Amber Paige Webber
Date: 08/ 04/ 2021
Leetcode Prompt: Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
*/
class Solution {
public:
    double myPow(double x, int n) {
        double power = 1;
        double denominator = 1;
        int j = n;
        if(n >= 0){   //if n is positive follow this loop
            for(int i = 0; i < n; i++) {
                power = power * x;  //multiply x by x for each n
             }
            return power;
        }
         
        else{ //if n is negative follow these commands
            while(n != 0 && n < 0){      //if n is not equal to 0 and not less than 0 continue
                denominator = denominator * x; //get the power result as a denominator term
                power = 1/denominator;   //divide denominator by 1 because x is negative
                n++;   //increase n
            }
            return power;
        }
    }
};
