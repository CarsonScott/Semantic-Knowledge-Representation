#ifndef REPRESENTATION_HPP_INCLUDED
#define REPRESENTATION_HPP_INCLUDED

#include "Properties.hpp"
#include "Relation.hpp"

class Representation
{
    Properties properties;
    std::vector<std::vector<int>> types;
    std::vector<Element> elements;
    std::vector<Relation> relations;

public:
    Representation(){}

    void setProperties(Properties p)
    {
        properties = p;
    }

    Representation(Properties p)
    {
        setProperties(p);
    }

    void addType(std::vector<int> p)
    {
        types.push_back(p);
    }

    Element createElementFromType(int type)
    {
        Element element;
        element.properties = types[type];
        for(int i = 0; i < element.properties.size(); i++)
        {
            element.state.push_back(0);
        }
        return element;
    }

    void setElements(std::vector<Element> e)
    {
        elements = e;
    }

    void setRelations(std::vector<Relation> r)
    {
        relations = r;
    }

    void createElement(std::vector<int> properties)
    {
        Element element;
        element.properties = properties;
        for(int i = 0; i < properties.size(); i++)
        {
            element.state.push_back(0);
        }
        elements.push_back(element);
    }

    void createElement(std::vector<int> properties, std::vector<int> state)
    {
        Element element;
        element.properties = properties;
        element.state = state;
        elements.push_back(element);
    }

    void createRelation(std::vector<int> src_elements, std::vector<int> dst_elements, std::vector<int> properties)
    {
        Relation relation;
        relation.sources = src_elements;
        relation.destinations = dst_elements;

        relation.properties = properties;
        for(int i = 0; i < properties.size(); i++)
        {
            relation.state.push_back(0);
        }
        relations.push_back(relation);
    }

    void createRelation(std::vector<int> src_elements, std::vector<int> dst_elements, std::vector<int> properties, std::vector<int> state)
    {
        Relation relation;
        relation.sources = src_elements;
        relation.destinations = dst_elements;
        relation.properties = properties;
        relation.state = state;
        relations.push_back(relation);
    }

    Element getElement(int i)
    {
        return elements[i];
    }

    Relation getRelation(int i)
    {
        return relations[i];
    }
};

#endif // REPRESENTATION_HPP_INCLUDED
