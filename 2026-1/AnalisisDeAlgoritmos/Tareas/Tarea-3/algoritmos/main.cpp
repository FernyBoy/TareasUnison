#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <random>
#include <string>
#include <functional>
#include <cmath>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// ─── Forward declarations ────────────────────────────────────────────────────

double Polinomio1(const vector<double>& C, double X);
double Potencia(double X, int j);
double Polinomio2(const vector<double>& C, double X);
double Polinomio3(const vector<double>& C, double X);
double Polinomio4(const vector<double>& C, double X);
float  Sum(vector<float> a, int n);
float  RSum(vector<float> a, int n);
vector<vector<float>> Add(vector<vector<float>> a, vector<vector<float>> b, int n);
void   Trasp(vector<vector<float>>& a, int n);
vector<vector<float>> Mult(const vector<vector<float>>& a, const vector<vector<float>>& b);
void   Perm(vector<int>& a, int k, int n);
int    SeqSearch(vector<int>& a, int x);

// ─── Benchmark helpers ───────────────────────────────────────────────────────

// Returns elapsed nanoseconds for a single call to fn()
template<typename Fn>
long long timeNs(Fn fn)
{
    auto t0 = high_resolution_clock::now();
    fn();
    auto t1 = high_resolution_clock::now();
    return duration_cast<nanoseconds>(t1 - t0).count();
}

void writeCSV(const string& path,
              const vector<long long>& ns,
              const vector<int>& values)
{
    ofstream f(path);
    f << "n,time_ns\n";
    for (size_t i = 0; i < ns.size(); ++i)
        f << values[i] << "," << ns[i] << "\n";
}

// ─── Random data generators ──────────────────────────────────────────────────

mt19937 rng(42);

vector<double> randDoubles(int n)
{
    uniform_real_distribution<double> dist(-10.0, 10.0);
    vector<double> v(n);
    for (auto& x : v) x = dist(rng);
    return v;
}

vector<float> randFloats(int n)
{
    uniform_real_distribution<float> dist(-100.0f, 100.0f);
    vector<float> v(n);
    for (auto& x : v) x = dist(rng);
    return v;
}

vector<vector<float>> randMatrix(int n)
{
    uniform_real_distribution<float> dist(-10.0f, 10.0f);
    vector<vector<float>> m(n, vector<float>(n));
    for (auto& row : m)
        for (auto& x : row)
            x = dist(rng);
    return m;
}

vector<int> randInts(int n)
{
    uniform_int_distribution<int> dist(1, 1'000'000'000);
    vector<int> v(n);
    for (auto& x : v) x = dist(rng);
    return v;
}

// ─── Progress reporting ──────────────────────────────────────────────────────

void progress(const string& algo, int done, int total)
{
    cout << "[" << algo << "] " << done << "/" << total << " completados\n";
    cout.flush();
}

// ─── Main ────────────────────────────────────────────────────────────────────

int main()
{
    const string CSV_DIR = "csv/";

    // ── 1. Polinomios (10 valores de n: grado del polinomio) ─────────────────
    // Complejidades: Pol1=O(n²)  Pol2=O(n log n)  Pol3=O(n)  Pol4=O(n)
    {
        vector<int> ns = {10000, 50000, 100000, 500000, 1000000,
                          2000000, 3000000, 5000000, 7000000, 10000000};

        const char* names[4] = {"Polinomio1","Polinomio2","Polinomio3","Polinomio4"};

        // Pol1 es O(n²), usamos rango más pequeño para que termine en tiempo razonable
        vector<int> ns_pol1 = {500, 1000, 2000, 3000, 5000,
                                7000, 10000, 15000, 20000, 30000};

        auto bench_pol = [&](int pol_idx)
        {
            const vector<int>& rango = (pol_idx == 0) ? ns_pol1 : ns;
            int total = rango.size();
            vector<long long> times(total);

            for (int i = 0; i < total; ++i)
            {
                int n = rango[i];
                auto C = randDoubles(n + 1);
                double X = 3.7;

                switch (pol_idx)
                {
                    case 0: times[i] = timeNs([&]{ Polinomio1(C, X); }); break;
                    case 1: times[i] = timeNs([&]{ Polinomio2(C, X); }); break;
                    case 2: times[i] = timeNs([&]{ Polinomio3(C, X); }); break;
                    case 3: times[i] = timeNs([&]{ Polinomio4(C, X); }); break;
                }

                progress(names[pol_idx], i + 1, total);
            }

            writeCSV(CSV_DIR + names[pol_idx] + ".csv", times, rango);
        };

        for (int p = 0; p < 4; ++p) bench_pol(p);
    }

    // ── 2. Sum ────────────────────────────────────────────────────────────────
    {
        vector<int> ns = {100000, 500000, 1000000, 2000000, 3000000,
                          5000000, 7000000, 10000000, 15000000, 20000000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randFloats(ns[i]);
            times[i] = timeNs([&]{ Sum(a, ns[i]); });
            progress("Sum", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "Sum.csv", times, ns);
    }

    // ── 3. RSum ───────────────────────────────────────────────────────────────
    // RSum es recursiva; stack overflow con n grande → rango conservador
    {
        vector<int> ns = {1000, 2000, 3000, 5000, 7000,
                          10000, 12000, 15000, 18000, 20000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randFloats(ns[i]);
            times[i] = timeNs([&]{ RSum(a, ns[i]); });
            progress("RSum", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "RSum.csv", times, ns);
    }

    // ── 4. Add ────────────────────────────────────────────────────────────────
    {
        vector<int> ns = {100, 200, 400, 600, 800,
                          1000, 1200, 1500, 1800, 2000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randMatrix(ns[i]);
            auto b = randMatrix(ns[i]);
            times[i] = timeNs([&]{ Add(a, b, ns[i]); });
            progress("Add", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "Add.csv", times, ns);
    }

    // ── 5. Trasp ──────────────────────────────────────────────────────────────
    {
        vector<int> ns = {100, 300, 600, 900, 1200,
                          1500, 2000, 2500, 3500, 5000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randMatrix(ns[i]);
            times[i] = timeNs([&]{ Trasp(a, ns[i]); });
            progress("Trasp", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "Trasp.csv", times, ns);
    }

    // ── 6. Mult ───────────────────────────────────────────────────────────────
    {
        vector<int> ns = {100, 200, 300, 400, 500,
                          600, 700, 800, 900, 1000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randMatrix(ns[i]);
            auto b = randMatrix(ns[i]);
            times[i] = timeNs([&]{ Mult(a, b); });
            progress("Mult", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "Mult.csv", times, ns);
    }

    // ── 7. Perm ───────────────────────────────────────────────────────────────
    // cout suprimido en Perm durante benchmark → solo mide el algoritmo
    {
        vector<int> ns = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            vector<int> a(ns[i]);
            iota(a.begin(), a.end(), 1);
            times[i] = timeNs([&]{ Perm(a, 0, ns[i]); });
            progress("Perm", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "Perm.csv", times, ns);
    }

    // ── 8. SeqSearch ─────────────────────────────────────────────────────────
    // Sentinel search: busca x=a[0] → peor caso lineal
    {
        vector<int> ns = {100000, 500000, 1000000, 5000000, 10000000,
                          20000000, 30000000, 50000000, 75000000, 100000000};
        vector<long long> times(ns.size());

        for (size_t i = 0; i < ns.size(); ++i)
        {
            auto a = randInts(ns[i]);
            // Guardamos el valor original de a[0] y lo restauramos
            // SeqSearch modifica a[0] como centinela
            int original = a[0];
            // Buscamos un valor que NO está en el arreglo → recorre todo
            int x = -1;
            times[i] = timeNs([&]{ SeqSearch(a, x); });
            a[0] = original;
            progress("SeqSearch", i + 1, ns.size());
        }
        writeCSV(CSV_DIR + "SeqSearch.csv", times, ns);
    }

    cout << "\n✓ Todos los benchmarks completados. CSVs en " << CSV_DIR << "\n";
    return 0;
}

// ─── Implementaciones ─────────────────────────────────────────────────────────

double Polinomio1(const vector<double>& C, double X)
{
    int N = C.size() - 1;
    double S = C[0];
    for (int i = 1; i <= N; ++i)
    {
        double XN = 1.0;
        for (int j = 1; j <= i; ++j) XN *= X;
        S += C[i] * XN;
    }
    return S;
}

double Potencia(double X, int j)
{
    if (j == 0)       return 1.0;
    if (j % 2 == 1)   return X * Potencia(X, j - 1);
    double t = Potencia(X, j / 2);
    return t * t;
}

double Polinomio2(const vector<double>& C, double X)
{
    int N = C.size() - 1;
    double S = C[0];
    for (int i = 1; i <= N; ++i) S += C[i] * Potencia(X, i);
    return S;
}

double Polinomio3(const vector<double>& C, double X)
{
    int N = C.size() - 1;
    double XN = 1.0, S = C[0];
    for (int i = 1; i <= N; ++i) { XN *= X; S += C[i] * XN; }
    return S;
}

double Polinomio4(const vector<double>& C, double X)
{
    int N = C.size() - 1;
    double S = 0.0;
    for (int i = N; i >= 0; --i) S = S * X + C[i];
    return S;
}

float Sum(vector<float> a, int n)
{
    float s = 0.0f;
    for (int i = 0; i < n; ++i) s += a[i];
    return s;
}

float RSum(vector<float> a, int n)
{
    if (n <= 0) return 0.0f;
    return RSum(a, n - 1) + a[n - 1];
}

vector<vector<float>> Add(vector<vector<float>> a, vector<vector<float>> b, int n)
{
    vector<vector<float>> c(n, vector<float>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[i][j] = a[i][j] + b[i][j];
    return c;
}

void Trasp(vector<vector<float>>& a, int n)
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(a[i][j], a[j][i]);
}

vector<vector<float>> Mult(const vector<vector<float>>& a, const vector<vector<float>>& b)
{
    int n = a.size();
    vector<vector<float>> c(n, vector<float>(n, 0.0f));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                c[i][j] += a[i][k] * b[k][j];
    return c;
}

void Perm(vector<int>& a, int k, int n)
{
    if (k == n) return;   // sin cout: solo ejecuta la recursión
    for (int i = k; i < n; ++i)
    {
        swap(a[k], a[i]);
        Perm(a, k + 1, n);
        swap(a[k], a[i]);
    }
}

int SeqSearch(vector<int>& a, int x)
{
    int n = a.size() - 1;
    a[0] = x;
    int i = n;
    while (a[i] != x) i--;
    return i;
}
