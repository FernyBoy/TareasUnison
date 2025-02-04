/**
*   \file   CapturaSegura.hpp
*   \author Angel Fernando Borquez Guerrero
*   \author Javier Leonardo Miranda Sanchez
*   \date   03/02/2025
*/

#ifndef CAPTURA_SEGURA_HPP
#define CAPTURA_SEGURA_HPP

#include <iostream>
#include <limits>
#include <type_traits>


template <typename N>
class CapturaSegura
{
static_assert(std::is_arithmetic_v<N>, "N debe ser un numero");

public:
    //-------------------------------------------------------------------------------------------------------------------------
    /** \brief Verifica que el tipo de dato ingresado sea del tipo correcto.
    *
    * \return Devuelve el tipo de dato ingresado si este es correcto.
    */
    static N LongitudSegura();

    //-------------------------------------------------------------------------------------------------------------------------
    /** \brief Verifica que el valor ingresado sea positivo.
    *
    * \return Devuelve el valor ingresado si cumple con la condicion.
    */
    static N LongitudPositiva();

    //-------------------------------------------------------------------------------------------------------------------------
    /** \brief Verifica que el valor ingresado no sea menor al establecido.
    *
    * \param min Es el valor minmo que puede ser ingresado.
    * 
    * \return Devuelve el valor ingresado si cumple con la condicion.
    */
    static N LongitudMinima(N min);

    //-------------------------------------------------------------------------------------------------------------------------
    /** \brief Verifica que el valor ingresado no sea mayor al establecido.
    *
    * \param max Es el valor maximo que puede ser igresado.
    * 
    * \return Devuelve el valor ingresado si cumple con la condicion.
    */
    static N LongitudMaxima(N max);

    //-------------------------------------------------------------------------------------------------------------------------
    /** \brief Verifica que el valor ingresado no salga de los limites establecidos.
    *
    * \param min Es el valor minimo que puede ser ingresado.
    * \param max Es el valor maximo que puede ser ingresado.
    * 
    * \return Devuelve el valor ingresado si cumple con la condicion.
    */
    static N LongitudCerrada(N min, N max);
};

#include "../Templates/CapturaSegura.tpp"

#endif
