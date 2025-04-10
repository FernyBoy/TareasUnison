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

class ClassName
{
    // --- Métodos externos
    friend std::ostream& operator<<(std::ostream& output, const ClassName &ClassId);
    friend std::istream& operator>>(std::istream& input, ClassName &ClassId);

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
#endif // !EXPRESSION_HPP_INCLUDED
