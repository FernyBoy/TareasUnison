/**
*   \file   CapturaSegura.tpp
*   \author Angel Fernando Borquez Guerrero
*   \date   18/02/2025
*/

using std::cout;
using std::cin;
using std::endl;



    // ------------------------------------ MÉTODOS PARA VALIDACIÓN DE TEXTO ------------------------------------

// Función para capturar un texto asegurando que la entrada sea válida
template <typename N, typename T>
T CapturaSegura<N, T>::TextoSeguro()
{
    T text;
    cin >> text;

    // Reintentar si la entrada es incorrecta
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa una respuesta válida.\n • ";
        cin >> text;
    }

    return text;
}

// Función para capturar un texto con una longitud mínima
template <typename N, typename T>
T CapturaSegura<N, T>::TextoMinimo(unsigned min)
{
    T text;
    cin >> text;

    // Reintentar si la entrada es incorrecta o el texto es más corto que el mínimo
    while(cin.fail() || text.size() < min)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "El texto ingresado debe tener mínimo " << min << " caracteres.\n • ";
        cin >> text;
    }

    return text;
}

// Función para capturar un texto con una longitud máxima
template <typename N, typename T>
T CapturaSegura<N, T>::TextoMaximo(unsigned max)
{
    T text;
    cin >> text;

    // Reintentar si la entrada es incorrecta o el texto es más largo que el máximo
    while(cin.fail() || text.size() > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "El texto ingresado debe tener máximo " << max << " caracteres.\n • ";
        cin >> text;
    }

    return text;
}

// Función para capturar un texto con una longitud entre un mínimo y máximo
template <typename N, typename T>
T CapturaSegura<N, T>::TextoCerrado(unsigned min, unsigned max)
{
    T text;
    cin >> text;

    // Reintentar si la entrada no cumple con los límites de longitud
    while(cin.fail() || text.size() < min || text.size() > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(text.size() < min)
        {
            cout << "El texto ingresado debe tener mínimo " << min << " caracteres.\n • ";
        }
        else if(text.size() > max)
        {
            cout << "El texto ingresado debe tener máximo " << max << " caracteres.\n • ";
        }
        
        cin >> text;
    }

    return text;
}

// Función para capturar texto permitiendo solo ciertos caracteres
template <typename N, typename T>
T CapturaSegura<N, T>::CaracteresPermitidos(const char caracteres[], unsigned int longitud) 
{
    T text;
    cin >> text;
    
    // Reintentar si el texto contiene caracteres no permitidos
    while (true) 
    {
        bool valid = true;

        for (char c : text) 
        {
            if (std::find(caracteres, caracteres + longitud, c) == caracteres + longitud)
            {
                cout << "\nError: El carácter '" << c << "' no está permitido." << endl;
                valid = false;
            }
        }

        if(!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto permitiendo solo ciertos caracteres usando un vector
template <typename N, typename T>
T CapturaSegura<N, T>::CaracteresPermitidos(const std::vector<char> caracteres)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto contiene caracteres no permitidos
    while (true) 
    {
        bool valid = true;

        for (char c : text) 
        {
            if (std::find(caracteres.begin(), caracteres.end(), c) == caracteres.end()) 
            {
                cout << "\nError: El carácter '" << c << "' no está permitido." << endl;
                valid = false;
            }
        }

        if (!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto excluyendo ciertos caracteres
template <typename N, typename T>
T CapturaSegura<N, T>::CaracteresExcluidos(const char caracteres[], unsigned int longitud) 
{
    T text;
    cin >> text;
    
    // Reintentar si el texto contiene caracteres excluidos
    while (true) 
    {
        bool valid = true;

        for (char c : text) 
        {
            if (std::find(caracteres, caracteres + longitud, c) != caracteres + longitud) 
            {
                cout << "\nError: El carácter '" << c << "' no está permitido." << endl;
                valid = false;
            }
        }

        if(!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto excluyendo ciertos caracteres usando un vector
template <typename N, typename T>
T CapturaSegura<N, T>::CaracteresExcluidos(const std::vector<char> caracteres)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto contiene caracteres excluidos
    while (true) 
    {
        bool valid = true;

        for (char c : text) 
        {
            if (std::find(caracteres.begin(), caracteres.end(), c) != caracteres.end()) 
            {
                cout << "\nError: El carácter '" << c << "' no está permitido." << endl;
                valid = false;
            }
        }

        if (!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto permitiendo solo ciertas palabras
template <typename N, typename T>
T CapturaSegura<N, T>::TextoPermitido(const std::string palabras[], unsigned int longitud)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto no es una de las palabras permitidas
    while (true) 
    {
        bool valid = true;

        if (std::find(palabras, palabras + longitud, text) == palabras + longitud) 
        {
            cout << "\nError: '" << text << "' no se acepta como entrada de texto." << endl;
            valid = false;
        }

        if(!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto permitiendo solo ciertas palabras usando un vector
template <typename N, typename T>
T CapturaSegura<N, T>::TextoPermitido(const std::vector<std::string> palabras)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto no es una de las palabras permitidas
    while (true) 
    {
        bool valid = true;

        if (std::find(palabras.begin(), palabras.end(), text) == palabras.end()) 
        {
            cout << "\nError: '" << text << "' no se acepta como entrada de texto." << endl;
            valid = false;
        }

        if (!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto excluyendo ciertas palabras
template <typename N, typename T>
T CapturaSegura<N, T>::TextoExcluido(const std::string palabras[], unsigned int longitud)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto es una de las palabras excluidas
    while (true) 
    {
        bool valid = true;

        if (std::find(palabras, palabras + longitud, text) != palabras + longitud) 
        {
            cout << "\nError: '" << text << "' no se acepta como entrada de texto." << endl;
            valid = false;
        }

        if(!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}

// Función para capturar texto excluyendo ciertas palabras usando un vector
template <typename N, typename T>
T CapturaSegura<N, T>::TextoExcluido(const std::vector<std::string> palabras)
{
    T text;
    cin >> text;
    
    // Reintentar si el texto es una de las palabras excluidas
    while (true) 
    {
        bool valid = true;

        if (std::find(palabras.begin(), palabras.end(), text) != palabras.end()) 
        {
            cout << "\nError: '" << text << "' no se acepta como entrada de texto." << endl;
            valid = false;
        }

        if (!valid)
        {
            cout << "\nIngresa de nuevo tu respuesta\n • ";
            cin >> text;
        }
        else
        {
            break;
        }
    }

    return text;
}



    // ------------------------------------ MÉTODOS PARA VALIDACIÓN NUMÉRICA ------------------------------------

// Función para capturar una longitud segura (número entero válido)
template <typename N, typename T>
N CapturaSegura<N, T>::LongitudSegura()
{
    N num;
    cin >> num;

    // Reintentar si la entrada no es válida
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa una respuesta válida.\n • ";
        cin >> num;
    }

    return num;
}

// Función para capturar una longitud positiva
template <typename N, typename T>
N CapturaSegura<N, T>::LongitudPositiva()
{
    N num;
    cin >> num;

    // Reintentar si el número no es positivo
    while(cin.fail() || num < 1)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < 1)
        {
            cout << "\nLa respuesta debe ser mayor a 0.";
            cout << "\nIngresa de nuevo tu respuesta.\n • ";
        }
        
        cin >> num;
    }

    return num;
}

// Función para capturar una longitud mínima
template <typename N, typename T>
N CapturaSegura<N, T>::LongitudMinima(N min)
{
    N num;
    cin >> num;

    // Reintentar si la longitud es menor que el mínimo
    while(cin.fail() || num < min)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < min)
        {
            cout << "\nLa respuesta no puede ser menor a " << min << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n • ";
        }
        
        cin >> num;
    }

    return num;
}

// Función para capturar una longitud máxima
template <typename N, typename T>
N CapturaSegura<N, T>::LongitudMaxima(N max)
{
    N num;
    cin >> num;

    // Reintentar si la longitud es mayor que el máximo
    while(cin.fail() || num > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num > max)
        {
            cout << "\nLa respuesta no puede ser mayor a " << max << ".";
            cout << "\nIngresa de nuevo tu respuesta.\n • ";
        }
        
        cin >> num;
    }

    return num;
}

// Función para capturar una longitud dentro de un rango cerrado
template <typename N, typename T>
N CapturaSegura<N, T>::LongitudCerrada(N min, N max)
{
    int num;
    cin >> num;

    // Reintentar si la longitud no está dentro del rango permitido
    while(cin.fail() || num < min || num > max)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        
        if(num < min)
        {
            cout << "\nLa respuesta debe ser mayor o igual a " << min << ".";
        }
        else if(num > max)
        {
            cout << "\nLa respuesta debe ser menor o igual a " << max << ".";
        }

        cout << "\nIngresa de nuevo tu respuesta.\n • ";
        cin >> num;
    }

    return num;
}
