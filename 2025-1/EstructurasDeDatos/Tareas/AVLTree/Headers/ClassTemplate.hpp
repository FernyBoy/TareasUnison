/**
*   \file   ClassName.hpp
*   \author 
*   \date   
*/

#ifndef _HPP_INCLUDED
#define _HPP_INCLUDED

#include <iostream>
#include <ostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <typename Type>
class ClassName
{
    // --- Métodos externos
    template <typename T>
    friend std::ostream& operator<<(std::ostream& output, const ClassName<T> &ClassId);
    template <typename T>
    friend std::istream& operator>>(std::istream& input, ClassName<T> &ClassId);

    public:
        // --- Constructores
        explicit ClassName();
        ClassName(const ClassName &ClassId);
        ClassName & operator=(const ClassName &ClassId);

        // --- Destructor
        ~ClassName();

        // --- Métodos públicos


    private:
        // --- Atributos


        // --- Métodos privados


        // --- Métodos de utilería

};

#include "../Templates/ClassName.tpp"

#endif // !EXPRESSION_HPP_INCLUDED
