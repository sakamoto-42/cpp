/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:12:20 by julien            #+#    #+#             */
/*   Updated: 2025/07/04 10:25:17 by julien           ###   ########.fr       */
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
        const   Animal  *meta = new Animal();
        std::cout << std::endl;
        const   Animal  *i = new Cat();
        std::cout << std::endl;
        const   Animal  *j = new Dog();
        std::cout << std::endl;

        std::cout << meta->getType() << " " << std::endl;
        std::cout << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << std::endl;
        meta->makeSound();
        std::cout << std::endl;
        i->makeSound(); //will output the cat sound!
        std::cout << std::endl;
        j->makeSound();
        std::cout << std::endl;

        delete(meta);
        delete(i);
        delete(j);//should not  create a leak
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "------------------------------ END -----------------------------" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "------------------------ MY TESTS BEGIN ------------------------" << std::endl;
        {
            std::cout << "------------------ MY TESTS FOR LEAKS BEGIN ------------------" << std::endl;
            const int   array_of_animals_size = 4;
            Animal      **array_of_animals = new Animal*[array_of_animals_size];
            int         i = 0;

            while (i < (array_of_animals_size / 2))
            {
                array_of_animals[i] = new Dog();
                std::cout << std::endl;
                i++;
            }
            std::cout << std::endl;

            while (i < array_of_animals_size)
            {
                array_of_animals[i] = new Cat();
                std::cout << std::endl;
                i++;
            }
            std::cout << std::endl;

            i = 0;
            while (i < array_of_animals_size)
            {
                delete(array_of_animals[i]);
                std::cout << std::endl;
                i++;
            }
            std::cout << std::endl;

            delete[] array_of_animals;
            std::cout << "------------------ MY TESTS FOR LEAKS END ------------------" << std::endl;
            std::cout << std::endl;
        }
        {
            std::cout << "--------------- MY TESTS FOR DOG BRAIN BEGIN ---------------" << std::endl;
            Animal    *dog = new Dog();

            dog->learn("I should bark at the mailman");
            dog->learn("I want a treat");
            dog->learn("Time for a walk");
            std::cout << std::endl;

            std::cout << dog->recall(0) << std::endl;
            std::cout << dog->recall(1) << std::endl;
            std::cout << dog->recall(2) << std::endl;
            std::cout << std::endl;

            delete(dog);
            std::cout << "---------------- MY TESTS FOR DOG BRAIN END ----------------" << std::endl;
            std::cout << std::endl;
        }
        {
            std::cout << "--------------- MY TESTS FOR CAT BRAIN BEGIN ---------------" << std::endl;
            Animal    *cat = new Cat();

            cat->learn("Time for a nap ");
            cat->learn("I should knock that glass off the table");
            cat->learn("Is it dinner time yet ?");
            std::cout << std::endl;

            std::cout << cat->recall(0) << std::endl;
            std::cout << cat->recall(1) << std::endl;
            std::cout << cat->recall(2) << std::endl;
            std::cout << std::endl;

            delete(cat);
            std::cout << "---------------- MY TESTS FOR CAT BRAIN END ----------------" << std::endl;
            std::cout << std::endl;
        }
        {
            std::cout << "-------------- MY TESTS FOR DEEP COPIES BEGIN --------------" << std::endl;
            {
                std::cout << "----- MY TESTS FOR DOG COPY ASSIGNMENT OPERATOR BEGIN ------" << std::endl;
                Dog  *dog1 = new Dog();
                std::cout << std::endl;
                dog1->learn("Idea for dog 1");

                Dog  *dog2 = new Dog();
                std::cout << std::endl;
                dog2->learn("Idea for dog 2");

                std::cout << "*dog1 = *dog2" << std::endl;
                *dog1 = *dog2;
                std::cout << std::endl;

                std::cout << "dog2->learn(\"A second idea for dog 2\")" << std::endl;
                dog2->learn("A second idea for dog 2");
                std::cout << std::endl;

                std::cout << "Recall dog 1 first idea (must be \"Idea for dog 2\") :" << std::endl;
                std::cout << dog1->recall(0) << std::endl;
                std::cout << "Recall dog 1 second idea (must be empty) :" << std::endl;
                std::cout << dog1->recall(1) << std::endl;
                std::cout << std::endl;

                std::cout << "Recall dog 2 first idea (must be \"Idea for dog 2\") :" << std::endl;
                std::cout << dog2->recall(0) << std::endl;
                std::cout << "Recall dog 2 second idea (must be \"A second idea for dog 2\") :" << std::endl;
                std::cout << dog2->recall(1) << std::endl;
                std::cout << std::endl;

                delete(dog1);
                std::cout << std::endl;
                delete(dog2);
                std::cout << "------ MY TESTS FOR DOG COPY ASSIGNMENT OPERATOR END -------" << std::endl;
                std::cout << std::endl;
            }
            {
                std::cout << "----- MY TESTS FOR CAT COPY ASSIGNMENT OPERATOR BEGIN ------" << std::endl;
                Cat  *cat1 = new Cat();
                std::cout << std::endl;
                cat1->learn("Idea for cat 1");

                Cat  *cat2 = new Cat();
                std::cout << std::endl;
                cat2->learn("Idea for cat 2");

                std::cout << "*cat1 = *cat2" << std::endl;
                *cat1 = *cat2;
                std::cout << std::endl;

                std::cout << "cat2->learn(\"A second idea for cat 2\")" << std::endl;
                cat2->learn("A second idea for cat 2");
                std::cout << std::endl;

                std::cout << "Recall cat 1 first idea (must be \"Idea for cat 2\") :" << std::endl;
                std::cout << cat1->recall(0) << std::endl;
                std::cout << "Recall cat 1 second idea (must be empty) :" << std::endl;
                std::cout << cat1->recall(1) << std::endl;
                std::cout << std::endl;

                std::cout << "Recall cat 2 first idea (must be \"Idea for cat 2\") :" << std::endl;
                std::cout << cat2->recall(0) << std::endl;
                std::cout << "Recall cat 2 second idea (must be \"A second idea for cat 2\") :" << std::endl;
                std::cout << cat2->recall(1) << std::endl;
                std::cout << std::endl;

                delete(cat1);
                std::cout << std::endl;
                delete(cat2);
                std::cout << "------ MY TESTS FOR CAT COPY ASSIGNMENT OPERATOR END -------" << std::endl;
                std::cout << std::endl;
            }
            {
                std::cout << "--------- MY TESTS FOR DOG COPY CONSTRUCTOR BEGIN ----------" << std::endl;
                Dog  *dog1 = new Dog();
                std::cout << std::endl;
                dog1->learn("Idea for dog 1");

                std::cout << "Dog *dog2 = new Dog(*dog1)" << std::endl;
                Dog  *dog2 = new Dog(*dog1);
                std::cout << std::endl;
                dog1->learn("A second idea for dog 1");

                std::cout << "Recall dog 1 first idea (must be \"Idea for dog 1\") :" << std::endl;
                std::cout << dog1->recall(0) << std::endl;
                std::cout << "Recall dog 1 second idea (must be \"A second idea for dog 1\") :" << std::endl;
                std::cout << dog1->recall(1) << std::endl;
                std::cout << std::endl;

                std::cout << "Recall dog 2 first idea (must be \"Idea for dog 1\") :" << std::endl;
                std::cout << dog2->recall(0) << std::endl;
                std::cout << "Recall dog 2 second idea (must be empty) :" << std::endl;
                std::cout << dog2->recall(1) << std::endl;
                std::cout << std::endl;

                delete(dog1);
                std::cout << std::endl;
                delete(dog2);
                std::cout << "---------- MY TESTS FOR DOG COPY CONSTRUCTOR END -----------" << std::endl;
                std::cout << std::endl;
            }
            {
                std::cout << "--------- MY TESTS FOR CAT COPY CONSTRUCTOR BEGIN ----------" << std::endl;
                Cat  *cat1 = new Cat();
                std::cout << std::endl;
                cat1->learn("Idea for cat 1");

                std::cout << "Cat *cat2 = new Cat(*cat1)" << std::endl;
                Cat  *cat2 = new Cat(*cat1);
                std::cout << std::endl;
                cat1->learn("A second idea for cat 1");

                std::cout << "Recall cat 1 first idea (must be \"Idea for cat 1\") :" << std::endl;
                std::cout << cat1->recall(0) << std::endl;
                std::cout << "Recall cat 1 second idea (must be \"A second idea for cat 1\") :" << std::endl;
                std::cout << cat1->recall(1) << std::endl;
                std::cout << std::endl;

                std::cout << "Recall cat 2 first idea (must be \"Idea for cat 1\") :" << std::endl;
                std::cout << cat2->recall(0) << std::endl;
                std::cout << "Recall dog 2 second idea (must be empty) :" << std::endl;
                std::cout << cat2->recall(1) << std::endl;
                std::cout << std::endl;

                delete(cat1);
                std::cout << std::endl;
                delete(cat2);
                std::cout << "---------- MY TESTS FOR CAT COPY CONSTRUCTOR END -----------" << std::endl;
                std::cout << std::endl;
            }
            std::cout << "--------------- MY TESTS FOR DEEP COPIES END ---------------" << std::endl;
            std::cout << std::endl;
        }
        std::cout << "------------------------- MY TESTS END -------------------------" << std::endl;
    }
    return (0);
}
