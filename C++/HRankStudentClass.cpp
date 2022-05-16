
class Student {
    private:
        int scores[5];
    public:
        void input() {
            int a, b, c, d, e;
            cin >> a >> b >> c >> d >> e;
            scores[0] = a;
            scores[1] = b;
            scores[2] = c;
            scores[3] = d;
            scores[4] = e;
        }
        int calculateTotalScore() {
            int sum = 0;
            for(int i = 0; i < 5; i++) {
                sum = sum + scores[i];                
            }
            return sum;
        }
        
    
};
