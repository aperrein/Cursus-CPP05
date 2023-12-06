/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:00 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 10:29:02 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int     main(void)
{
    try {
        Bureaucrat      b1("b1", 5);
        std::cout << b1;
    }
    catch (std::exception & e) {
        std::cout << "Error " << e.what() << std::endl;
    }

    try {
        Bureaucrat      b2("b2", 0);
        std::cout << b2;
    }
    catch (std::exception & e) {
        std::cout << "Error " << e.what() << std::endl;
    }

    try {
        Bureaucrat      b3("b3", 159);
        std::cout << b3;
    }
    catch (std::exception & e) {
        std::cout << "Error " << e.what() << std::endl;
    }

    try {
        Bureaucrat      b4("b4", 1);
        std::cout << b4;
        b4.decrement();
        std::cout << b4;
        b4.increment();
        b4.increment();
        std::cout << b4;
        std::cout << b4;
    }
    catch (std::exception & e) {
        std::cout << "Error " << e.what() << std::endl;
    }
    return (0);
}
