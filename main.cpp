#include <iostream>
#include "cube.hpp"
#include <chrono>


int main() {

    //The most optimal algorithm to solve a Rubiks cube
    //is just to peel and rearrange the stickers
    
    std::cout << R"(
        Rubix

         ___ ___ ___
       /___/___/___/|
      /___/___/___/||
     /___/___/__ /|/|
    |   |   |   | /||
    |___|___|___|/|/|
    |   |   |   | /||
    |___|___|___|/|/
    |   |   |   | /
    |___|___|___|/

    )" << std::endl;

    Cube qb;
    //std::vector<Cube> cubeVec;

    auto start = std::chrono::high_resolution_clock::now();

    unsigned long long count = 0;

    while (std::chrono::high_resolution_clock::now() - start < std::chrono::seconds(1)) {


        qb = qb.rotVert(static_cast<Column>(count&1),  static_cast<Direction>(count&1));
        //cubeVec.push_back(qb);
        qb = qb.rotHoriz(static_cast<Row>(count&1), static_cast<Direction>(count&1+2));
        //cubeVec.push_back(qb);

        count += 2;
    }

    std::cout << count;


    std::cout << qb << "\n\n";
    return 0;
}
