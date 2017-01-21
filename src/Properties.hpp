#ifndef PROPERTIES_HPP_INCLUDED
#define PROPERTIES_HPP_INCLUDED
#include <vector>

class Properties
{
    int total;
    std::vector<int> types;
`   `    std::vector<std::string> names;
    std::vector<std::vector<int>> index_spaces;

    bool is_duplicate(std::string name, int type)
    {
        for(int i = 0; i < index_spaces[type].size(); i++)
        {
            int index = index_spaces[type][i];
            if(names[index] == name && i != index)
                return true;
        }
        return false;
    }

public:

    Properties(int type_count)
    {
        total = 0;
        for(int i = 0; i < type_count; i++)
        {
            index_spaces.push_back(std::vector<int>());
        }
    }
    void append(std::string name, int type)
    {
        if(!is_duplicate(name, type))
        {
            names.push_back(name);
            types.push_back(type);
            index_spaces[type].push_back(total);
            total ++;
        }
    }

    std::vector<std::string> getNames()
    {
        return names;
    }
    std::vector<int> getTypes()
    {
        return types;
    }

    void setName(int i, std::string name)
    {
        names[i] = name;
    }
    std::string getName(int i)
    {
        return names[i];
    }

    void setType(int i, int type)
    {
        types[i] = type;
    }
    int getType(int i)
    {
        return types[i];
    }

    std::vector<int> getIndexSpace(int type)
    {
        return index_spaces[type];
    }

    std::vector<std::string> getStateSpace(int type)
    {
        std::vector<std::string> state_space;
        for(int i = 0; i < index_spaces[type].size(); i++)
        {
            int index = index_spaces[type][i];
            state_space.push_back(names[i]);
        }
        return state_space;
    }
};
#endif // PROPERTIES_HPP_INCLUDED
