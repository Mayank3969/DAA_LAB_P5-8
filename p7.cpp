#include <bits/stdc++.h>
using namespace std;

// Compute minimal expected search cost of an Optimal BST given p (success) and q (failure) probabilities.
static double optimalBST(const vector<double>& p, const vector<double>& q, int n) {
    vector<vector<double>> e(n + 1, vector<double>(n + 1, 0.0));
    vector<vector<double>> w(n + 1, vector<double>(n + 1, 0.0));

    for (int i = 0; i <= n; i++) {
        e[i][i] = q[i];
        w[i][i] = q[i];
    }

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len;
            e[i][j] = numeric_limits<double>::infinity();
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

            // Try each key in (i+1..j) as root
            for (int r = i + 1; r <= j; r++) {
                double cost = e[i][r - 1] + e[r][j] + w[i][j];
                if (cost < e[i][j]) e[i][j] = cost;
            }
        }
    }

    return e[0][n];
}

// Robustly read the next `count` numeric tokens from cin (ignoring non-number labels like "Keys:")
template <typename T>
static vector<T> readNumbers(size_t count) {
    vector<T> out;
    out.reserve(count);
    string tok;
    while (out.size() < count && (cin >> tok)) {
        // Strip trailing commas/colons if any (e.g., "Keys:")
        while (!tok.empty() && (tok.back() == ':' || tok.back() == ',')) tok.pop_back();
        if (tok.empty()) continue;
        try {
            size_t idx = 0;
            double v = stod(tok, &idx);
            if (idx == tok.size()) {
                out.push_back(static_cast<T>(v));
            }
        } catch (...) {
            // Ignore non-numeric labels
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Enter number of book IDs (n): " << endl;
    if (!(cin >> n)) return 0;

    // Read keys (not used in cost computation, but consumed from input)
    cout << "Enter " << n << " sorted book IDs (keys), space-separated:" << endl;
    vector<long long> keys = readNumbers<long long>(static_cast<size_t>(n));

    // Read probabilities p (size n) and q (size n+1)
    cout << "Enter p[i] for i=1.." << n << " (probabilities of successful searches), space-separated:" << endl;
    vector<double> p = readNumbers<double>(static_cast<size_t>(n));
    cout << "Enter q[i] for i=0.." << n << " (probabilities of unsuccessful searches), space-separated:" << endl;
    vector<double> q = readNumbers<double>(static_cast<size_t>(n + 1));

    // If inputs are insufficient, exit gracefully
    if (p.size() != static_cast<size_t>(n) || q.size() != static_cast<size_t>(n + 1)) {
        cerr << "Insufficient numbers provided. Please re-run and enter the required counts." << '\n';
        return 0;
    }

    double result = optimalBST(p, q, n);
    cout.setf(std::ios::fixed);
    cout << "Minimum expected cost of the Optimal BST: " << setprecision(4) << result << '\n';
    return 0;
}
