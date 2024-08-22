class Solution {
public:
    string decToBinary(int n){
        int num[32];
        int i = 0;
        while (n > 0) {
            num[i] = n % 2;
            n /= 2;
            i++;
        }
        string bin = "";
        for(int j=i-1;j>=0;j--) bin += (char)(num[j] + '0');
        return bin;
    }

    int binaryToDec(string bin) {
        long long n = bin.size(), dec = 0, p = 1;
        for (int i=n-1;i>=0;i--) {
            if (bin[i] == '1') dec += p;
            p *= 2;
        }
        return (int)dec;
    }

    int findComplement(int num) {
        string bin = decToBinary(num);
        for(int i=0;i<bin.size();i++){
            (bin[i] == '0') ? bin[i] = '1' : bin[i] = '0';
        }
        int dec = binaryToDec(bin);
        return dec;
    }
};