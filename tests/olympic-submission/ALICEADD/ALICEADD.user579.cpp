#include <bits/stdc++.h>
 
using namespace std;

#define ll long long
#define ull unsigned long long

struct BigNum {
    int ndigits;
    int sign;
    vector<int> digits;

    // Default constructor
    BigNum() : sign(0), ndigits(0), digits(vector<int>()) {}

    BigNum(long long x) {
        if (x < 0) {
            this -> sign = -1;
            x = -x;
        }
        else this -> sign = 1;
        while (x > 0) {
            this -> digits.push_back(x % 10);
            x /= 10;
        }
        this -> ndigits = (int) this -> digits.size();
        reverse(this -> digits.begin(), this -> digits.end());
    }

    BigNum(string s) {
        if (s[0] == '-') {
            this -> sign = -1;
            s.erase(0, 1);
        }
        else this -> sign = 1;
        this -> ndigits = (int) s.size();
        this -> digits.resize(ndigits);
        for (int i = 0; i < (int) s.size(); i++) {
            this -> digits[i] = s[i] - '0';
        }
    }

    BigNum(vector<int> a) : sign(1), ndigits((int) a.size()), digits(a) {}

    // Comparison
    bool operator < (const BigNum& other) const {
        if (sign != other.sign) return sign < other.sign;
        if (ndigits != other.ndigits) return ndigits < other.ndigits;
        for (int i = 0; i < ndigits; i++) {
            if (digits[i] != other.digits[i]) {
                return digits[i] < other.digits[i];
            }
        }
        return false;
    }

    bool operator > (const BigNum& other) const {
        return other < *this;
    }

    bool operator >= (const BigNum& other) const {
        return !(*this < other);
    }

    bool operator <= (const BigNum& other) const {
        return !(*this > other);
    }

    bool operator == (const BigNum& other) const {
        return !(*this < other) && !(*this > other);
    }

    bool operator != (const BigNum& other) const {
        return *this < other || *this > other;
    }

    // Other functions
    bool isZero() const {
        return digits.empty() || (ndigits == 1 && digits[0] == 0);
    }

    BigNum abs() const {
        BigNum ret = *this;
        if (isZero()) return ret;
        ret.sign *= ret.sign;
        return ret;
    }

    // Operations
    // Compare vector (compare bignum with sign ingnored)
    bool cmp_vec(const vector<int>& a, const vector<int>& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = 0; i < (int) a.size(); i++) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return false;
    }
    
    // Addition, return vector of digits, sign ignored.
    vector<int> add(const BigNum& a, const BigNum& b) {
        vector<int> da = a.digits, db = b.digits;
        if (!cmp_vec(da, db)) swap(da, db);
        reverse(da.begin(), da.end());
        reverse(db.begin(), db.end());
        vector<int> ret;
        int c = 0;
        for (int i = 0; i < (int) da.size(); i++) {
            ret.push_back((da[i] + db[i] + c) % 10);
            c = (da[i] + db[i] + c) / 10;
        }
        for (int i = (int) da.size(); i < (int) db.size(); i++) {
            ret.push_back((db[i] + c) % 10);
            c = (db[i] + c) / 10;
        }
        if (c > 0) ret.push_back(c);
        while (!ret.empty() && ret.back() == 0) ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }

    // Subtraction, return vector of digits, sign ignored.
    vector<int> sub(const BigNum& a, const BigNum& b, bool& rev) {
        vector<int> da = a.digits, db = b.digits;
        if (cmp_vec(da, db)) {
            swap(da, db);
            rev = true;
        }
        reverse(da.begin(), da.end());
        reverse(db.begin(), db.end());
        vector<int> ret;
        int c = 0;
        for (int i = 0; i < (int) db.size(); i++) {
            int v = (da[i] - db[i] - c);
            if (v < 0) {
                v += 10; c = 1;
            }
            else c = 0;
            ret.push_back(v);
        }
        for (int i = (int) db.size(); i < (int) da.size(); i++) {
            int v = da[i] - c;
            if (v < 0) {
                v += 10; c = 1;
            }
            else c = 0;
            ret.push_back(v);
        }
        while (!ret.empty() && ret.back() == 0) ret.pop_back();
        reverse(ret.begin(), ret.end());
        return ret;
    }

    // Multiplication return vector of digits.
    static vector<int> simpleMultiply(const BigNum& a, const BigNum& b) {
        vector<int> res(a.digits.size() + b.digits.size(), 0);
        int ii = 0, jj = 0;
        for (int i = (int) a.digits.size() - 1; i >= 0; i--) {
            int c = 0;
            jj = 0;
            for (int j = (int) b.digits.size() - 1; j >= 0; j--) {
                int v = a.digits[i] * b.digits[j] + res[ii + jj] + c;
                c = v / 10;
                res[ii + jj] = v % 10;
                jj++;
            }
            if (c > 0) res[ii + jj] += c;
            ii++;
        }
        res.shrink_to_fit();
        while (!res.empty() && res.back() == 0) res.pop_back();
        if (res.empty()) return {0};
        reverse(res.begin(), res.end());
        return res;
    }

    // Karatsuba multiplication of two vectors
    static vector<long long> karatsubaMultiply(const vector<long long>& a, const vector<long long>& b) {
        int n = (int) a.size();
        vector<long long> ret(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) ret[i + j] += a[i] * b[j];
            }
            return ret;
        }
        int k = n >> 1;
        vector<long long> a1(a.begin(), a.begin() + k);
        vector<long long> a2(a.begin() + k, a.end());
        vector<long long> b1(b.begin(), b.begin() + k);
        vector<long long> b2(b.begin() + k, b.end());
        vector<long long> a1b1 = karatsubaMultiply(a1, b1);
        vector<long long> a2b2 = karatsubaMultiply(a2, b2);
        for (int i = 0; i < k; i++) a2[i] += a1[i];
        for (int i = 0; i < k; i++) b2[i] += b1[i];
        vector<long long> r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];
        for (int i = 0; i < (int) r.size(); i++) ret[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++) ret[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++) ret[i + n] += a2b2[i];
        return ret;
    }

    // Addition, with sign
    BigNum operator + (BigNum const& other) {
        BigNum ret;
        if (sign == 1 && other.sign == 1) {
            vector<int> t = add(*this, other);
            ret.sign = 1;
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else if (sign == 1 && other.sign == -1) {
            bool rev = false;
            vector<int> t = sub(*this, other, rev);
            ret.sign = (rev ? -1 : 1);
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else if (sign == -1 && other.sign == 1) {
            bool rev = false;
            vector<int> t = sub(other, *this, rev);
            ret.sign = (rev ? -1 : 1);
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else {
            ret.sign = -1;
            vector<int> t = add(*this, other);
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        return ret;
    }

    // Subtraction, with sign
    BigNum operator - (BigNum const& other) {
        BigNum ret;
        if (sign == 1 && other.sign == 1) {
            bool rev = false;
            vector<int> t = sub(*this, other, rev);
            ret.sign = (rev ? -1 : 1);
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else if (sign == 1 && other.sign == -1) {
            vector<int> t = add(*this, other);
            ret.sign = 1;
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else if (sign == -1 && other.sign == 1) {
            vector<int> t = add(*this, other);
            ret.sign = -1;
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        else {
            bool rev = false;
            vector<int> t = sub(other, *this, rev);
            ret.sign = (rev ? -1 : 1);
            ret.ndigits = (int) t.size();
            ret.digits = t;
        }
        return ret;
    }

    // Multiplication
    BigNum mul_simple(const BigNum& v) const {
        BigNum ret;
        ret.sign = sign * v.sign;
        ret.digits = simpleMultiply(*this, v);
        ret.ndigits = (int) ret.digits.size();
        return ret;
    }

    BigNum mul_karatsuba(const BigNum& v) const {
        vector<long long> a(digits.rbegin(), digits.rend());
        vector<long long> b(v.digits.rbegin(), v.digits.rend());
        while (a.size() < b.size()) a.push_back(0);
        while (b.size() < a.size()) b.push_back(0);
        // power of 2
        while (a.size() & (a.size() - 1)) {
            a.push_back(0);
            b.push_back(0);
        }
        vector<long long> c = karatsubaMultiply(a, b);
        BigNum ret;
        ret.sign = sign * v.sign;
        int carry = 0;
        for (int i = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            ret.digits.push_back((int) cur % 10);
            carry = cur / 10; 
        }
        while (carry > 0) {
            ret.digits.push_back(carry % 10);
            carry /= 10;
        }
        while (!ret.digits.empty() && ret.digits.back() == 0) {
            ret.digits.pop_back();
        }
        reverse(ret.digits.begin(), ret.digits.end());
        ret.ndigits = (int) ret.digits.size();
        return ret;
    }

    BigNum operator * (BigNum const& other) {
        if (isZero() || other.isZero()) return BigNum(0);
        BigNum ret;
        ret.sign = sign * other.sign;
        if (digits.size() * other.digits.size() <= 500000) return mul_simple(other);
        return mul_karatsuba(other);
    }

    void operator *= (const BigNum& other) {
        *this = *this * other;
    } 
};

void solve() {
    string sa, sb;
    cin >> sa >> sb;
    BigNum a = BigNum(sa), b = BigNum(sb);
    BigNum c = a + b;
    if (c.isZero()) cout << 0 << '\n';
    else {
        if (c.sign == -1) cout << '-';
        for (int i : c.digits) cout << i;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}