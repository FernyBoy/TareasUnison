double Polinomio1(const vector<double>& C, double X)
{
    int N = C.size() - 1;

    double S = C[0];

    for(int i = 0; i <= N; ++i)
    {
        double XN = 1.0;

        for(int j = 1; j <= i; ++j)
        {
            XN *= X;
        }

        S += C[i] * XN;
    }

    return S;
}



double Potencia(double X, int j)
{
    if(j == 0)
    {
        return 1.0;
    }
    else if(j % 2 == 1)
    {
        return X * Potencia(X, j - 1);
    }
    else
    {
        double t = Potencia(X, j / 2);

        return t * t;
    }
}

double Polinomio2(const vector<double>& C, double X)
{
    int N = C.size() - 1;

    double S = C[0];

    for(int i = 0; i <= N; ++i)
    {
        S += C[i] * Potencia(X, i);
    }

    return S;
}



double Polinomio3(const vector<double>& C, double X)
{
    int N = C.size() - 1;

    double XN = 1.0;
    double S = C[0];

    for(int i = 0; i <= N; ++i)
    {
        XN *= X;
        S += C[i] * XN;
    }

    return S;
}



double Polinomio4(const vector<double>& C, double X)
{
    int N = C.size() - 1;

    double S = 0.0;

    for(int i = N; i >= 0; --i)
    {
        S = S * X + C[i];
    }

    return S;
}



float Sum(vector<float> a, int n)
{
    float s = 0.0;

    for(int i = 0; i < n; ++i) s += a[i];
    
    return s;
}



float RSum(vector<float> a, int n)
{
    float result;
    if(n <= 0)
    {
        result = 0.0;
    }
    else
    {
        result = RSum(a, n - 1) + a[n-1];
    }

    return result;
}



vector<vector<float>> Add(vector<vector<float>> a, vector<vector<float>> b, int n)
{
    vector<vector<float>> c(n, vector<float>(n));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    return c;
}



void Trasp(vector<vector<float>> & a, int n)
{
    float t = 0.0;

    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}



vector<vector<float>> Mult(const vector<vector<float>>& a, const vector<vector<float>>& b)
{
    int n = a.size();

    vector<vector<float>> c(n, vector<float>(n, 0.0f));

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            for(int k = 0; k < n; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}



void Perm(vector<int>& a, int k, int n)
{
    if(k == n)
    {
        for(int i = 0; i < n; ++i)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i = k; i < n; ++i)
        {
            swap(a[k], a[i]);

            Perm(a, k + 1, n);

            swap(a[k], a[i]);
        }
    }
}



int SeqSearch(vector<int>& a, int x)
{
    int n = a.size() - 1;

    a[0] = x;

    int i = n;

    while(a[i] != x)
    {
        i = i - 1;
    }

    return i;
}

