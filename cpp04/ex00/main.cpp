/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 10:12:20 by julien            #+#    #+#             */
/*   Updated: 2025/06/30 14:34:20 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "-------------------- WITH ANIMAL, CAT AND DOG ------------------" << std::endl;
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
        delete(j);
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "-------------------- WITH ANIMAL, CAT AND DOG ------------------" << std::endl;
        std::cout << "------------------------------ END -----------------------------" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "------------- WITH WRONG ANIMAL, WRONG CAT AND DOG -------------" << std::endl;
        std::cout << "----------------------------- BEGIN ----------------------------" << std::endl;
        const   WrongAnimal  *meta = new WrongAnimal();
        std::cout << std::endl;
        const   WrongAnimal  *i = new WrongCat();
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
        i->makeSound(); //will output the wrong animal sound!
        std::cout << std::endl;
        j->makeSound();
        std::cout << std::endl;

        delete(meta);
        delete(i);
        delete(j);
        std::cout << "------------------------- SUBJECT TESTS ------------------------" << std::endl;
        std::cout << "------------- WITH WRONG ANIMAL, WRONG CAT AND DONE -------------" << std::endl;
        std::cout << "------------------------------ END -----------------------------" << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "------------------------ MY TESTS BEGIN ------------------------" << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "--- A Dog is a Dog ---" << std::endl;
        std::cout << std::endl;
        std::cout << "--- Dog *dog = new Dog(); ---" << std::endl;
        Dog     *dog = new Dog();
        std::cout << std::endl;
        std::cout << "--- A Dog that is a Dog can bark but don't meow ---" << std::endl;
        std::cout << *dog << std::endl;
        dog->makeSound();
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "--- A Cat is a Cat ---" << std::endl;
        std::cout << std::endl;
        std::cout << "--- Cat *cat = new Cat(); ---" << std::endl;
        Cat     *cat = new Cat();
        std::cout << std::endl;
        std::cout << "--- A Cat that is a Cat can meow but don't bark ---" << std::endl;
        std::cout << *cat << std::endl;
        cat->makeSound();
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "--- An Animal is an Animal ---" << std::endl;
        std::cout << std::endl;
        std::cout << "--- Animal *animal = new Animal(); ---" << std::endl;
        Animal  *animal = new Animal();
        std::cout << std::endl;
        std::cout << "--- An Animal that is an Animal can't meow or bark ---" << std::endl;
        std::cout << *animal << std::endl;
        animal->makeSound();
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "--- A Dog is an Animal ---" << std::endl;
        std::cout << std::endl;
        std::cout << "--- Animal  *animal_dog = new Dog(); ---" << std::endl;
        Animal  *animal_dog = new Dog();
        std::cout << std::endl;
        std::cout << "--- A Dog that is an Animal can bark but don't meow ---" << std::endl;
        std::cout << *animal_dog << std::endl;
        animal_dog->makeSound();
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "--- A Cat is an Animal ---" << std::endl;
        std::cout << std::endl;
        std::cout << "--- Animal  *animal_cat = new Cat(); ---" << std::endl;
        Animal  *animal_cat = new Cat();
        std::cout << std::endl;
        std::cout << "--- A Cat that is an Animal can meow but don't bark ---" << std::endl;
        std::cout << *animal_cat << std::endl;
        animal_cat->makeSound();
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "--- An Animal is not a Dog ! ---" << std::endl;
        std::cout << "--- Dog  *dog_animal = new Animal(); ---" << std::endl;
        std::cout << "error: invalid conversion from ‘Animal*’ to Dog*’" << std::endl;
        //Dog  *dog_animal = new Animal();
        std::cout << std::endl;

        std::cout << "--- An Animal is not a Cat ! ---" << std::endl;
        std::cout << "--- Cat  *cat_animal = new Animal(); ---" << std::endl;
        std::cout << "error: invalid conversion from ‘Animal*’ to ’Cat*’" << std::endl;
        //Cat  *cat_animal = new Animal();
        std::cout << std::endl;

        std::cout << "--- delete(dog); ---" << std::endl;
        delete(dog);
        std::cout << std::endl;

        std::cout << "--- delete(cat); ---" << std::endl;
        delete(cat);
        std::cout << std::endl;

        std::cout << "--- delete(animal); ---" << std::endl;
        delete(animal);
        std::cout << std::endl;

        std::cout << "--- delete(animal_dog); ---" << std::endl;
        delete(animal_dog);
        std::cout << std::endl;

        std::cout << "--- delete(animal_cat); ---" << std::endl;
        delete(animal_cat);
        std::cout << std::endl;

        /*
        std::cout << "--- delete(dog_animal); ---" << std::endl;
        delete(dog_animal);
        std::cout << std::endl;
        */

        /*
        std::cout << "--- delete(cat_animal); ---" << std::endl;
        delete(cat_animal);
        std::cout << std::endl;
        */
        std::cout << "------------------------- MY TESTS END -------------------------" << std::endl;
    }
    return (0);
}
