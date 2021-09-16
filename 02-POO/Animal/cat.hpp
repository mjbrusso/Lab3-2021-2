#ifndef CAT_HPP
#define CAT_HPP 1

#include <string>

#include "animal.hpp"

class cat : public animal {
   public:
    cat(const std::string &pn) : animal{pn} {
    }

    virtual void speak();
};
#endif