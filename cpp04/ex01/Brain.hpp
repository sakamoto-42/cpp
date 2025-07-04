/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:54:49 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 10:18:34 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class   Brain
{
    public:
        Brain(void);
        Brain(Brain const &src);
        virtual             ~Brain(void);

        Brain               &operator=(Brain const &rhs);

        void                addIdea(const std::string &idea);

        const std::string   getIdea(int idea_index) const;
        int                 getIdeaCount(void) const;

    private:
        std::string _ideas[100];
        int         _ideas_next_index;
};

std::ostream    &operator<<(std::ostream &o, Brain const &brain);

#endif
