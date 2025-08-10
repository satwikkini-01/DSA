class Solution {
public:
    unsigned long long encode(int x) {
        int freq[10] = {0};
        if (x == 0) freq[0] = 1;
        while (x > 0) { freq[x % 10]++; x /= 10; }

        unsigned long long sig = 0, mul = 1;
        for (int d = 0; d < 10; ++d) {
            sig += (unsigned long long)freq[d] * mul;
            mul *= 11ULL; // base 11, safe for counts <= 10
        }
        return sig;
    }

    bool reorderedPowerOf2(int n) {
        unordered_set<unsigned long long> S;
        for (int i = 0; i < 30; ++i) S.insert(encode(1 << i));
        return S.count(encode(n)) > 0;
    }
};
