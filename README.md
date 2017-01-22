# Semantic Knowledge Representation

Representations are created using sets of elements and relations with certain properties to form semantic networks.

A property is a label that describes some aspect of an element or relation. Each property has a set of possible values (e.g. a color can be red, green, blue, etc.) and takes on one of those values at any given time.

## Examples

**1) Create a blue circle, red triangle, and green rectangle**

- Create the properties (shape and color)

        Properties properties(2);

- Define the possible values

        properties.append("circle", 0);
        properties.append("triangle", 0);
        properties.append("rectangle", 0);
      
        properties.append("blue", 1);
        properties.append("red", 1);
        properties.append("green", 1);
        
        Representation representation(properties);
        
- Create a "colored shape" type
        
        std::vector<int> type;
        type.push_back(0);
        type.push_back(1);
        representation.addType(type);
        
- Create the elements
        Element circle = representation.createElementFromType(0);
        circle.state[0] = 0;
        circle.state[1] = 0;
        representation.addElement(circle);
        
        
        Element triangle = representation.createElementFromType(0);
        circle.state[0] = 1;
        circle.state[1] = 1;
        representation.addElement(triangle);
        
        
        Element rectangle = representation.createElementFromType(0);
        circle.state[0] = 2;
        circle.state[1] = 2;
        representation.addElement(circle);
