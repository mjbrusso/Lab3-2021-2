#ifndef DOG_HPP
#define DOG_HPP 1

#include <string>

#include "animal.hpp"

class dog : public animal {
   public:
    dog(const std::string &pn) : animal(pn) {
    }

    virtual void speak();
};
#endif  // dog.hpp
