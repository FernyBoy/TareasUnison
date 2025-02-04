/**
*   \file   Vector.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <istream>
#include <ostream>

/**
 * @brief Clase Vector para el manejo de vectores de números reales.
 *
 * La clase Vector permite crear y manipular vectores cuyos elementos son de tipo double.  
 * Se ofrecen operaciones aritméticas básicas (suma, resta, producto punto, producto por escalar),  
 * acceso a componentes mediante operadores de indexación, así como métodos para la entrada y  
 * salida de datos, impresión y cálculo de la norma del vector.
 */
class Vector
{
    // Operadores amigos
    /**
     * @brief Operador de multiplicación escalar (lado izquierdo escalar).
     *
     * Permite multiplicar un vector por un escalar cuando el escalar aparece a la izquierda.
     *
     * @param escalar Valor escalar por el cual se multiplica el vector.
     * @param v Vector a multiplicar.
     * @return Vector Resultado de la multiplicación.
     */
    friend Vector operator*(double escalar, const Vector v);

    /**
     * @brief Operador de inserción en flujo.
     *
     * Permite enviar el contenido del vector a un flujo de salida.
     *
     * @param salida Flujo de salida.
     * @param v Vector a imprimir.
     * @return std::ostream& Referencia al flujo de salida.
     */
    friend std::ostream & operator<<(std::ostream &salida, const Vector v);

    /**
     * @brief Operador de extracción en flujo.
     *
     * Permite extraer datos de un flujo de entrada y almacenarlos en el vector.
     *
     * @param entrada Flujo de entrada.
     * @param v Vector en el cual se almacenarán los datos.
     * @return std::istream& Referencia al flujo de entrada.
     */
    friend std::istream & operator>>(std::istream &entrada, Vector &v);

public:
    // ----- Constructores ----------------------------------------

    /**
     * @brief Constructor con parámetros.
     *
     * Crea un vector con una dimensión especificada y con todos sus componentes inicializados  
     * al valor \a val. Si no se especifican los parámetros, se crea un vector de dimensión 1  
     * con valor 0 en cada componente.
     *
     * @param dim Dimensión del vector. Valor predeterminado: 1.
     * @param val Valor inicial para cada componente del vector. Valor predeterminado: 0.
     */
    explicit Vector(int dim = 1, double val = 0);

    /**
     * @brief Constructor de copia.
     *
     * Crea un vector copiando los datos y la estructura de otro vector.
     *
     * @param v Vector del cual se copian los datos.
     */
    Vector(const Vector &v);

    /**
     * @brief Destructor.
     *
     * Libera la memoria asignada a los componentes del vector.
     */
    ~Vector();

    /**
     * @brief Operador de asignación.
     *
     * Asigna el contenido del vector \a v al vector actual, liberando la memoria previamente  
     * asignada y copiando los datos del vector fuente.
     *
     * @param v Vector del cual se asignarán los valores.
     * @return Vector& Referencia al vector actual.
     */
    Vector & operator=(const Vector &v);

    // ----- Métodos públicos -------------------------------------

    /**
     * @brief Obtiene la dimensión del vector.
     *
     * Retorna el número de componentes del vector.
     *
     * @return int Dimensión del vector.
     */
    int ObtenerDimension() const;

    /**
     * @brief Imprime el vector.
     *
     * Muestra en la salida estándar los componentes del vector en formato (a, b, c, ...).
     */
    void Imprimir() const;

    /**
     * @brief Captura los componentes del vector desde la entrada estándar.
     *
     * Solicita al usuario que ingrese los valores para cada componente del vector.
     */
    void Capturar();

    /**
     * @brief Suma dos vectores.
     *
     * Realiza la suma componente a componente entre el vector actual y el vector \a v.
     *
     * @param v Vector a sumar.
     * @return Vector Resultado de la suma.
     * @throws Lanza una excepción si las dimensiones de los vectores son incompatibles.
     */
    Vector operator+(const Vector v) const;

    /**
     * @brief Resta dos vectores.
     *
     * Realiza la resta componente a componente entre el vector actual y el vector \a v.
     *
     * @param v Vector a restar.
     * @return Vector Resultado de la resta.
     * @throws Lanza una excepción si las dimensiones de los vectores son incompatibles.
     */
    Vector operator-(const Vector v) const;

    /**
     * @brief Calcula el producto punto entre dos vectores.
     *
     * Realiza la suma de los productos de las componentes correspondientes entre  
     * el vector actual y el vector \a v.
     *
     * @param v Vector con el que se realiza el producto punto.
     * @return double Resultado del producto punto.
     * @throws Lanza una excepción si las dimensiones de los vectores son incompatibles.
     */
    double operator*(const Vector v) const;

    /**
     * @brief Multiplica el vector por un escalar.
     *
     * Multiplica cada componente del vector por el valor del escalar \a escalar.
     *
     * @param escalar Valor escalar por el cual se multiplicará el vector.
     * @return Vector Resultado de la multiplicación.
     */
    Vector operator*(const double escalar) const;

    /**
     * @brief Acceso a un componente del vector (lectura).
     *
     * Permite obtener el valor del componente en la posición \a i de manera segura.
     *
     * @param i Índice del componente.
     * @return double Valor del componente en la posición \a i.
     * @throws Lanza una excepción si el índice es inválido.
     */
    double operator[](int i) const;

    /**
     * @brief Acceso a un componente del vector (lectura/escritura).
     *
     * Permite acceder y modificar el componente en la posición \a i.
     *
     * @param i Índice del componente.
     * @return double& Referencia al componente en la posición \a i.
     * @throws Lanza una excepción si el índice es inválido.
     */
    double & operator[](int i);

    /**
     * @brief Calcula la norma del vector.
     *
     * Retorna la norma Euclidiana del vector, calculada como la raíz cuadrada de la  
     * suma de los cuadrados de sus componentes.
     *
     * @return double Norma del vector.
     */
    double NormaV() const;

private:
    // ----- Atributos --------------------------------------------

    /**
     * @brief Dimensión del vector.
     *
     * Indica el número de componentes que tiene el vector.
     */
    int dimension;

    /**
     * @brief Arreglo dinámico que almacena los componentes del vector.
     */
    double *components;
        
    // ----- Métodos de utilería ----------------------------------

    /**
     * @brief Establece la dimensión del vector.
     *
     * Valida y asigna la dimensión al vector.  
     * @param dim Nueva dimensión del vector.
     * @throws Lanza una excepción si \a dim es menor que 1.
     */
    void EstablecerDim(int dim);
};

#endif // !VECTOR_HPP_INCLUDED
