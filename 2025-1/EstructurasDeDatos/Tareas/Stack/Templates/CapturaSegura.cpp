using std::cout;
using std::cin;
using std::endl;

template <typename N>
N CapturaSegura<N>::LongitudSegura()
{
    N num;
    cin >> num;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa una respuesta v\240lida.\n - ";
        cin >> num;
    }

    return num;
}

template <typename N>
N CapturaSegura<N>::LongitudPositiva()
{
    N num;
    cin >> num;

    while(cin.fail() || num < 1)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < 1)
        {
            cout << "\nLa respuesta debe ser mayor a 0.";
            cout << "\nIngresa de nuevo tu respuesta.\n - ";
        }
        
        cin >> num;
    }

    return num;
}

template <typename N>
N CapturaSegura<N>::LongitudMinima(N min)
{
    N num;
    cin >> num;

    while(cin.fail() || num < min)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < min)
        {
            cout << "\nLa respuesta no puede ser menor a " << min << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n - ";
        }
        
        cin >> num;
    }

    return num;
}

template <typename N>
N CapturaSegura<N>::LongitudMaxima(N max)
{
    N num;
    cin >> num;

    while(cin.fail() || num > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num > max)
        {
            cout << "\nLa respuesta no puede ser mayor a " << max << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n - ";
        }
        
        cin >> num;
    }

    return num;
}

template <typename N>
N CapturaSegura<N>::LongitudCerrada(N min, N max)
{
    int num;
    cin >> num;

    while(cin.fail() || num < min || num > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < min)
        {
            cout << "\nLa respuesta no puede ser menor a " << min << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n - ";
        }
        else if(num > max)
        {
            cout << "\nLa respuesta no puede ser mayor a " << max << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n - ";
        }
        
        cin >> num;
    }

    return num;
}
