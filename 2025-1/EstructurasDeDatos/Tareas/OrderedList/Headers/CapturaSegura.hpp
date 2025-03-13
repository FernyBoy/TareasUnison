/**
*   \file   CapturaSegura.hpp
*   \author Angel Fernando Borquez Guerrero
*   \date   18/02/2025
*/

#ifndef CAPTURA_SEGURA_HPP
#define CAPTURA_SEGURA_HPP

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <type_traits>

/**
 * @class CapturaSegura
 * @brief Clase plantilla para validación segura de entradas de usuario.
 *
 * Esta clase permite capturar y validar datos de entrada, asegurando que cumplan con ciertos criterios.
 * Soporta tanto valores numéricos como cadenas de texto con restricciones configurables.
 *
 * @tparam N Tipo de dato numérico (por defecto int).
 * @tparam T Tipo de dato de texto (por defecto std::string).
 */
template <typename N = int, typename T = std::string>
class CapturaSegura
{
    // Restricciones en tiempo de compilación para los tipos de datos permitidos
    static_assert(std::is_arithmetic_v<N>, "N debe ser un número");
    static_assert(std::is_same_v<T, std::string> || std::is_same_v<T, char>, "T debe ser un tipo de texto (std::string o char)");

public:

    // ------------------------------------ MÉTODOS PARA VALIDACIÓN DE TEXTO ------------------------------------

    /**
     * @brief Captura un texto asegurando que sea del tipo correcto.
     * @return Devuelve la cadena ingresada si es válida.
     */
    static T TextoSeguro();

    /**
     * @brief Captura un texto con una longitud mínima establecida.
     * @param min Longitud mínima permitida.
     * @return Devuelve la cadena ingresada si cumple la restricción.
     */
    static T TextoMinimo(unsigned min);

    /**
     * @brief Captura un texto con una longitud máxima establecida.
     * @param max Longitud máxima permitida.
     * @return Devuelve la cadena ingresada si cumple la restricción.
     */
    static T TextoMaximo(unsigned max);

    /**
     * @brief Captura un texto dentro de un rango de longitud específico.
     * @param min Longitud mínima permitida.
     * @param max Longitud máxima permitida.
     * @return Devuelve la cadena ingresada si cumple la restricción.
     */
    static T TextoCerrado(unsigned min, unsigned max);

    /**
     * @brief Captura un texto asegurando que solo contenga ciertos caracteres permitidos.
     * @param caracteres Array de caracteres permitidos.
     * @param longitud Tamaño del array de caracteres.
     * @return Devuelve la cadena ingresada si solo contiene caracteres permitidos.
     */
    static T CaracteresPermitidos(const char caracteres[], unsigned int longitud);

    /**
     * @brief Captura un texto asegurando que solo contenga caracteres permitidos.
     * @param caracteres Vector de caracteres permitidos.
     * @return Devuelve la cadena ingresada si solo contiene caracteres permitidos.
     */
    static T CaracteresPermitidos(const std::vector<char> caracteres);

    /**
     * @brief Captura un texto asegurando que no contenga ciertos caracteres excluidos.
     * @param caracteres Array de caracteres prohibidos.
     * @param longitud Tamaño del array de caracteres prohibidos.
     * @return Devuelve la cadena ingresada si no contiene caracteres excluidos.
     */
    static T CaracteresExcluidos(const char caracteres[], unsigned int longitud);

    /**
     * @brief Captura un texto asegurando que no contenga ciertos caracteres excluidos.
     * @param caracteres Vector de caracteres prohibidos.
     * @return Devuelve la cadena ingresada si no contiene caracteres excluidos.
     */
    static T CaracteresExcluidos(const std::vector<char> caracteres);

    /**
     * @brief Captura un texto asegurando que esté dentro de una lista de palabras permitidas.
     * @param palabras Array de palabras permitidas.
     * @param longitud Tamaño del array de palabras.
     * @return Devuelve la palabra ingresada si está dentro de la lista de palabras permitidas.
     */
    static T TextoPermitido(const std::string palabras[], unsigned int longitud);

    /**
     * @brief Captura un texto asegurando que esté dentro de una lista de palabras permitidas.
     * @param palabras Vector de palabras permitidas.
     * @return Devuelve la palabra ingresada si está dentro de la lista de palabras permitidas.
     */
    static T TextoPermitido(const std::vector<std::string> palabras);

    /**
     * @brief Captura un texto asegurando que no contenga ciertas palabras excluidas.
     * @param palabras Array de palabras prohibidas.
     * @param longitud Tamaño del array de palabras prohibidas.
     * @return Devuelve la cadena ingresada si no contiene palabras excluidas.
     */
    static T TextoExcluido(const std::string palabras[], unsigned int longitud);

    /**
     * @brief Captura un texto asegurando que no contenga ciertas palabras excluidas.
     * @param palabras Vector de palabras prohibidas.
     * @return Devuelve la cadena ingresada si no contiene palabras excluidas.
     */
    static T TextoExcluido(const std::vector<std::string> palabras);

    // ------------------------------------ MÉTODOS PARA VALIDACIÓN NUMÉRICA ------------------------------------

    /**
     * @brief Captura un número asegurando que sea del tipo correcto.
     * @return Devuelve el número ingresado si es válido.
     */
    static N LongitudSegura();

    /**
     * @brief Captura un número asegurando que sea positivo.
     * @return Devuelve el número ingresado si es positivo.
     */
    static N LongitudPositiva();

    /**
     * @brief Captura un número asegurando que no sea menor a un valor mínimo establecido.
     * @param min Valor mínimo permitido.
     * @return Devuelve el número ingresado si cumple la restricción.
     */
    static N LongitudMinima(N min);

    /**
     * @brief Captura un número asegurando que no sea mayor a un valor máximo establecido.
     * @param max Valor máximo permitido.
     * @return Devuelve el número ingresado si cumple la restricción.
     */
    static N LongitudMaxima(N max);

    /**
     * @brief Captura un número asegurando que se encuentre dentro de un rango específico.
     * @param min Valor mínimo permitido.
     * @param max Valor máximo permitido.
     * @return Devuelve el número ingresado si cumple la restricción.
     */
    static N LongitudCerrada(N min, N max);
};

// Incluir la implementación del template
#include "../Templates/CapturaSegura.tpp"

#endif // CAPTURA_SEGURA_HPP
