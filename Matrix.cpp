#include <vector>
template <typename T>
class Matrix {
    int size;
    long long MOD;

   public:
    std::vector<std::vector<T>> mat;
    Matrix() : Matrix(2, 1000) {}
    Matrix(int size) : Matrix(size, 1000) {}
    Matrix(int size, int mod) : Matrix(size, mod, 0) {}
    Matrix(int size, int mod, T base) : size(size), MOD(mod) {
        mat.resize(size);
        for (int i{}; i < size; i++) mat[i].resize(size);
    }
    void setMatrix(std::vector<std::vector<T>>& t) {
        for (int i{}; i < t.size(); i++) {
            for (int j{}; j < t[i].size(); j++) {
                mat[i][j] = t[i][j];
            }
        }
    }

    void init() {
        for (int i = 0; i < size; i++) {
            mat[i][i] = 1;
        }
    }

    Matrix operator*(const Matrix<T>& m) {
        T n = m.mat.size();
        Matrix<T> c(n, this->MOD);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c.mat[i][j] = (c.mat[i][j] + this->mat[i][k] * m.mat[k][j]) % MOD;
                }
            }
        }
        return c;
    }
    T retMatrixRowColumn(int row, int column) { return mat[row][column]; }
    Matrix pow(long long b) {
        Matrix<T> tmp(size, MOD);
        tmp.init();
        while (b) {
            if (b & 1) tmp = tmp * *this;
            b >>= 1;
            *this = *this * *this;
        }
        return tmp;
    }
    void printAll() {
        for (int i = 0; i < this->mat.size(); i++) {
            for (int j = 0; j < this->mat[i].size(); j++) {
                std::cout << this->mat[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    static long long FIBO(long long n) {
        Matrix<long long> zero(2);
        zero.mat[0][0] = 1;
        zero.mat[0][1] = 0;
        zero.mat[1][0] = 0;
        zero.mat[1][1] = 1;
        Matrix<long long> BASE(2);
        BASE.mat[0][0] = 1;
        BASE.mat[0][1] = 1;
        BASE.mat[1][0] = 1;
        BASE.mat[1][1] = 0;
        while (n) {
            if (n & 1) zero = zero * BASE;
            n >>= 1;
            BASE = BASE * BASE;
        }
        return zero.mat[0][1];
    }
    void setMod(int mod) { this->MOD = mod; }
    int getMod() { return this->MOD; }
};
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }