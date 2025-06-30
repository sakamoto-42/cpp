/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:12:20 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 17:41:40 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "----------------------------- BEGIN ----------------------------" << std::endl;
        //const   Animal  *meta = new Animal();
        //std::cout << std::endl;
        const   Animal  *i = new Cat();
        std::cout << std::endl;
        const   Animal  *j = new Dog();
        std::cout << std::endl;

        //std::cout << meta->getType() << " " << std::endl;
        //std::cout << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << std::endl;
        //meta->makeSound();
        //std::cout << std::endl;
        i->makeSound(); //will output the cat sound!
        std::cout << std::endl;
        j->makeSound();
        std::cout << std::endl;

        //delete(meta);
        delete(i);
        delete(j);//should not  create a leak
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "------------------------------ END -----------------------------" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "------------------------ MY TESTS BEGIN ------------------------" << std::endl;
        const int   array_of_animals_size = 10;
        Animal      **array_of_animals = new Animal*[array_of_animals_size];
        int         i = 0;

        while (i < (array_of_animals_size / 2))
        {
            array_of_animals[i] = new Dog();
            i++;
        }
        while (i < array_of_animals_size)
        {
            array_of_animals[i] = new Cat();
            i++;
        }

        array_of_animals[0]->learn("idea");
        
        i = 0;
        while (i < array_of_animals_size)
        {
            delete(array_of_animals[i]);
            i++;
        }
        delete[] array_of_animals;
        std::cout << "------------------------- MY TESTS END -------------------------" << std::endl;
    }
    return (0);
}
