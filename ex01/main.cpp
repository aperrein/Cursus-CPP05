/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:30 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 13:43:32 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int     main(void)
{
    Bureaucrat      b1("b1", 42);
    Bureaucrat      b2("b2", 42);

    std::cout << b1;
    std::cout << b2;

    b2.decrement();
    std::cout << b2;

    std::cout << std::endl;

    Form            f1("f1", 42, 50);
    Form            f2("f2", 5, 50);
    Form            f3("f3", 42, 50);
    
    try
    {
    Form            f4("f4", 42, 250);
    
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << std::endl;
    try
    {
    Form            f5("f5", 42, 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << std::endl;

    std::cout << f1;
    std::cout << f2;
    std::cout << std::endl;

    b1.signForm(f1);
    b1.signForm(f2);
    b2.signForm(f3);
    b2.increment();
    b2.signForm(f3);

    std::cout << f1;
    std::cout << f2;
    std::cout << f3;
    std::cout <<std::endl;

    return (0);
}
