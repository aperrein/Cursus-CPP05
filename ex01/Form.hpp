/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:43:06 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 13:43:07 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
        std::string const       _name;
        bool                    _signed;
        unsigned int const      _gradSign;
        unsigned int const      _gradExec;
        Form();

public:
        Form(std::string n,unsigned int s, unsigned int e);
        ~Form();
        Form(Form const & copy);
        Form &      operator=(Form const & rhs);

        std::string         getName() const;
        bool                getSigned() const;
        unsigned int        getGradSign() const;
        unsigned int        getGradExec() const;

        void                beSigned(Bureaucrat const & b);

    class GradeTooHighException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };
};

std::ostream &      operator<<(std::ostream & o, Form const & f);
#endif
