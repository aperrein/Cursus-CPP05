/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:04:07 by aperrein          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:09 by aperrein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
            std::string         _target;
            RobotomyRequestForm();

public:
            RobotomyRequestForm(std::string t);
            ~RobotomyRequestForm();
            RobotomyRequestForm(RobotomyRequestForm const & copy);
            RobotomyRequestForm &     operator=(RobotomyRequestForm const & rhs);

            std::string         getTarget() const;

            void                execute(Bureaucrat const & executor) const;
};

#endif
