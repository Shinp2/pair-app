#include <iostream>  
#include "json.hpp"  

using json = nlohmann::json; // Fix: Define the `json` type using the nlohmann::json namespace  

int main() {  
    std::string input = R"({
  "board": [
    { "player": 1, "position": [0, 0] },
    { "player": 2, "position": [0, 1] }
  ],
  "move": [2, 3],
  "boardSize": 8,
  "flip": [ [2, 3], [2, 4] ]
})";

    std::cerr << input << std::endl;  
    json j;  
    try {  
        j = json::parse(input);  

        std::cout << j["name"];
    }  
    catch (const std::exception& e) {  
        std::cerr << "Error reading JSON from stdin: " << e.what() << std::endl;  
        return false;  
    }  
    while (1);
    return 0;  
}