// Animal class declaration

#ifndef ANIMAL_HPP  //include guard
#define ANIMAL_HPP 1

#include <string>

class animal {
   protected:
    std::string name;

   public:
    animal(const std::string &pn = "") : name{pn} {
    }

    virtual ~animal(){}
    virtual void speak()=0;
};
#endif