class Solution {
public:
    int countCommas(int n) {

        //thousands
        if(n>=1000 && n<10000) return (n-999);

        //ten thousands
        if(n>=10000 && n<100000) return (n-10000) + 9001;

        //lakh
        if(n==100000) return 99001;

        return 0;
    }
};