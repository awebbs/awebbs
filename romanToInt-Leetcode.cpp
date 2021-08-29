class Solution {
public:
    int romanToInt(string s) {
     
        int romInt = 0;

        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == 'I') {
                romInt = romInt + 1;
                if(s[i + 1] == 'V') {
                    romInt = romInt - 1 + 4; 
                    i = i + 1;
                    continue;
                }
                if(s[i + 1] == 'X') {
                    romInt = romInt - 1 + 9;
                    i = i + 1;
                    continue;
                }                                  
                continue;
            }
            if(s[i] == 'V') {
                romInt = romInt + 5;
            }
            if(s[i] == 'X') {
                romInt = romInt + 10;
                if(s[i + 1] == 'L'){
                    romInt = romInt  - 10 + 40;
                    i = i + 1;
                    continue;
                }
                if(s[i + 1] == 'C') {
                    romInt = romInt - 10 + 90;
                    i = i + 1;
                    continue;
                }
                continue;
            }
           if(s[i] == 'C') {
                romInt = romInt + 100;
                if(s[i + 1] == 'D') {
                    romInt = romInt - 100 + 400;
                    i = i + 1;
                    continue;
                }
               if(s[i + 1] == 'M') {
                   romInt = romInt - 100 + 900;
                   i = i + 1;
                   continue;
               }
            }

            if(s[i] == 'L') {
                romInt = romInt + 50;
                continue;
            }
            if(s[i] == 'M'){
                romInt = romInt + 1000;
                continue;
            }
            if(s[i] == 'D') {
                romInt = romInt + 500;
                continue;
            }
            
        }
        
          return romInt;  
        }
         
};
