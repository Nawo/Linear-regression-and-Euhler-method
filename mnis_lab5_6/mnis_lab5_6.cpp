#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

// ============================ LAB 6 =========================== //

void rozniczka()
{

    float h = 0.1;

    float x = 0;
    int i = 0;

    vector<float> f;
    vector<float> y;

    y.push_back(1);

    while (x <= 20.0)
    {
        f.push_back(y[i]);
        y.push_back(y[i] + h * f[i]);

        cout << y[i + 1] << endl;

        i++;
        x += h;

    }

}

double function(double x, double y)
{

    int funkcja = 2*y + 3*x; // funkcja do zrozniczkowania

    return funkcja;
}

// ============================ LAB 6 =========================== //





// ============================ LAB 5 =========================== //

void regression(float* x, float* y, int n, float* a, float* b)
{

    float Sx = 0;
    float Sxx = 0;
    float Sy = 0;
    float Syy = 0;
    float Sxy = 0;

    for (int i = 0; i < n; i++)
    {

        Sx += x[i];
        Sxx += x[i] * x[i];
        Sy += y[i];
        Syy += y[i] * y[i];
        Sxy += y[i] * x[i];

    }

    float delta = n * Sxx - (Sx * Sx);

    *a = (n * Sxy - (Sx * Sy)) / delta;
    *b = (Sxx * Sy - (Sx * Sxy)) / delta;
}

// ============================ LAB 5 =========================== //

int main()
{

    // ============================ LAB 5 =========================== //

    float Y[6] = { 5, 10, 15, 20, 25, 30 };
    float X[6] = { 2.83, 3.7, 4.77, 5.95, 7.17, 8.52 };

    float* X_wsk = X;
    float* Y_wsk = Y;

    int S = 10;

    float alfa = 0;
    float beta = 0;

    float* alfa_wsk = &alfa;
    float* beta_wsk = &beta;

    regression(X_wsk, Y_wsk, S, alfa_wsk, beta_wsk);

    cout << "alfa: " << alfa << ", beta: " << beta << endl;

    float Y_2[10] = { 3.86, 5.18, 6.5, 7.82, 9.14, 10.46, 11.78, 13.1, 14.42, 15.74 };
    float Y_zasz[10];

    float* Y_zasz_wsk = Y_zasz;

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> gen(-100, 100);

    for (int i = 0; i < 10; i++)
    {
        Y_zasz[i] = Y_2[i] + gen(rng) / 27;
        //cout << Y_zasz[i] << ", ";
    }
    
    // ============================ LAB 5 =========================== //




    // ============================ LAB 6 =========================== //

    rozniczka();

    


    double h = 0.1; // probkowanie

    double y0 = 2; // wartosc poczatkowa
    double y = y0;

    double x0 = 0; // poczatek przedzialu
    double x = 0.5; // koniec przedzialu

    int i = 1;

    cout << "n\t" << "xn\t" << "yn\t" << endl;

    cout << "0" << "\t" << x0 << "\t" << y0 << "\t" << endl;

    while (x0 < x)
    {
        
        y = y + h * function(x0, y);
        x0 += h;

        cout << i << "\t" << x0 << "\t" << y << "\t" << endl;

        i++;

    }

    return 0;

    // ============================ LAB 6 =========================== //


}
