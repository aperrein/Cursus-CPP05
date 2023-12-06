/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:29:53 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/23 10:29:55 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
private:
            std::string const   _name;
            unsigned int        _grade;
            Bureaucrat();

public:
            Bureaucrat(std::string n, unsigned int g);
            ~Bureaucrat();
            Bureaucrat(Bureaucrat const & copy);
            Bureaucrat &    operator=(Bureaucrat const & rhs);

            std::string         getName() const;
            unsigned int        getGrade() const;

            void                increment();
            void                decrement();

    class GradeTooHighException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
            virtual char const  *what() const throw();
    };

};

std::ostream &      operator<<(std::ostream & o, Bureaucrat const & b);

#endif
