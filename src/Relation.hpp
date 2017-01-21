#ifndef RELATION_HPP_INCLUDED
#define RELATION_HPP_INCLUDED

#include "Element.hpp"

struct Relation: public Element
{
    std::vector<int> sources;
    std::vector<int> destinations;

};

#endif // RELATION_HPP_INCLUDED
