#include <time.h>
#include <cassert>
#include "cube.hpp"
#include "edge_cubies.hpp"
#include "mini_cube.hpp"

#include <iostream>
#include <iterator>
#include <sys/_types/_off_t.h>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <locale>
#include <array>
#include "alg.hpp"
#include "cube.hpp"

//extern uint64_t nodesGenerated;

constexpr std::string_view VERSION = "0.2.1";

int benchRotations(int rotations) {
    Cube qb;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < rotations/27; i++) {
        qb = qb.getNeighbors()[rand()%27];
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    int rotationRate = rotations / duration.count() * 1000;
    return rotationRate;
}

int main() {

    //The most optimal algorithm to solve a Rubiks cube
    //is just to peel the stickers

    std::cout << R"(

            ██████    █████                         █████
          ███░░░░███ ░░███                         ░░███
         ███    ░░███ ░███████   ██████  ████████  ███████
        ░███     ░███ ░███░░███ ███░░███░░███░░███░░░███░
        ░███   ██░███ ░███ ░███░███████  ░███ ░░░   ░███
        ░░███ ░░████  ░███ ░███░███░░░   ░███       ░███ ███
         ░░░██████░██ ████████ ░░██████  █████      ░░█████
           ░░░░░░ ░░ ░░░░░░░░   ░░░░░░  ░░░░░        ░░░░░

)" << "Version " << VERSION << R"(

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

    //std::cout << qb;
    /*
    std::cout << "Cube: " << qb;
    std::cout << qb.changePerspective(Perspective::Left).changePerspective(Perspective::Left).changePerspective(Perspective::Left).changePerspective(Perspective::Left);
    std::cout << "Right perspective: " << qb.changePerspective(Perspective::Right);
    std::cout << "Left perspective: " << qb.changePerspective(Perspective::Left);

    std::cout << MiniCube(qb) << "\n";*/

    /*
    std::cout << "Original: " << qb << "\n\n\n";

    std::cout << "X axis back right rot: " << qb.rotXaxis(CrossSection::Back, Direction::Right);
    std::cout << "X axis back left rot: " << qb.rotXaxis(CrossSection::Back, Direction::Left);
    std::cout << "X axis back 180 rot: " << qb.rotXaxis(CrossSection::Back, Direction::_180);
    std::cout << "X axis middle left rot: " << qb.rotXaxis(CrossSection::Middle, Direction::Left);*/


    /*
    std::cout << "Neighbors:" << std::endl;

    for (int i = 0; i < 9; i++) {
        std::cout << qb.getNeighbors()[i];
    }*/

    //srand(time(NULL));

    Cube qb;

    /*
    for (int i = 0; i < 10000000; i++) {
        //auto allNeighbors = qb.getNeighbors();

        //std::array<Cube, 18> selectNeighbors;
        //std::copy(allNeighbors.begin(), allNeighbors.begin()+9, selectNeighbors.begin());
        //std::copy(allNeighbors.begin()+18, allNeighbors.begin()+27, selectNeighbors.begin()+9);

        //std::cout << "\nneighbor index: " << nghbrIdx;
        //std::cout << qb;

        //int nghbrIdx = rand()%27;
        qb = qb.getNeighbors()[3];


        if (!(qb.hasProperCorners() && MiniCube(qb).getIdx() <= 3674160 && qb.isValidColorDistribution())) {

            std::cout << "\n\n\nError:" << std::endl;
            std::cout << "Loop index: " << i << std::endl;
            std::cout << "Neighbor index: " << nghbrIdx << std::endl;
            std::cerr << "Normal cube:\n" << qb;
            std::cout << "\nMini cube:\n" << MiniCube(qb) << std::endl;
            std::cout << "Index: " << MiniCube(qb).getIdx() << std::endl;
            assert(false);
        }
    }

    return 0;*/


    /*
    std::cout << "Old cube: " << qb;

    int nghbrIdx = rand()%27;
    qb = qb.getNeighbors()[nghbrIdx];
    MiniCube mini = MiniCube(qb);
    uint32_t cubeIdx = mini.getIdx();

    std::cout << "Neighbor index: " << nghbrIdx << std::endl;
    std::cerr << "New cube:\n" << qb;
    std::cout << "\nMini cube:\n" << MiniCube(qb) << std::endl;
    std::cout << "Index: " << cubeIdx<< std::endl;*/


    //for (int i = 0; i < )


    //PDB database(MiniCube(), 3674160);
    /*
    MiniCube qb;
    qb = qb.rotVert(Column::Left, Direction::Up);
    std::cout << (int) database.getDist(qb.getIdx()) << std::endl;

    qb = qb.rotHoriz(Row::Top, Direction::Left);
    std::cout << (int) database.getDist(qb.getIdx()) << std::endl;

    qb = qb.rotVert(Column::Right, Direction::Down);
    std::cout << (int) database.getDist(qb.getIdx()) << std::endl;*/
    /*
    std::array<uint32_t, 12> counts{};
    PDB database(MiniCube(), 3674160);

    for (int i = 0; i < 3674160; i++) {
        uint8_t numMoves = database.getDist(i);
        counts[numMoves]++;
    }

    std::cout << "Cubes that can be solved in [x] moves: [n]\n\n";

    for (int i = 0; i < 12; i++) {
        std::cout << i << ": " << counts[i] << "\n";
    }

    std::cout << qb << std::endl;*/

    /*
    Cube qb;

    qb = qb.rotVert(Column::Right, Direction::Down);
    std::cout << database.getDist(MiniCube(qb).getIdx()) << std::endl;

    qb = qb.rotHoriz(Row::Bottom, Direction::Right);
    std::cout << database.getDist(MiniCube(qb).getIdx()) << std::endl;

    qb = qb.rotVert(Column::Right, Direction::Up);
    std::cout << database.getDist(MiniCube(qb).getIdx()) << std::endl;

    qb = qb.rotHoriz(Row::Bottom, Direction::Right);
    std::cout << database.getDist(MiniCube(qb).getIdx()) << std::endl;

    std::cout << "Index: " << MiniCube(qb).getIdx() << std::endl;
    std::cout << "Cube: " << qb << std::endl;
    std::cout << "Minicube:\n" << MiniCube(qb) << std::endl;*/


    //return 0;


    //Cube qb;

    /*
    EdgeCubies testEdges();
    std::cout << testEdges << std::endl;
    uint32_t testIdx = testEdges.getIdx();

    return 0;
     */
    //PDB cornerCubieDB(MiniCube(), 3674160);
    //PDB edgCubieDB(EdgeCubies(), 42577920);
    //return 0;

    using Color::White;
    using Color::Green;
    using Color::Red;
    using Color::Yellow;
    using Color::Blue;
    using Color::Orange;

    /*
    for (int i = 0; i < 20; i++) {
        auto allNeighbors = qb.getNeighbors();

        //std::array<Cube, 18> selectNeighbors;
        //std::copy(allNeighbors.begin(), allNeighbors.begin()+9, selectNeighbors.begin());
        //std::copy(allNeighbors.begin()+18, allNeighbors.begin()+27, selectNeighbors.begin()+9);


        uint32_t nghbrIdx = (rand()%27);
        qb = qb.getNeighbors()[nghbrIdx];

    }*/

    //Apparently I input this wrong
    /*
    qb.front = White<<24 | Blue<<21 | Orange<<18
            | Yellow<<15 | Red<<12 | Orange<<9
            | Orange<<6 | White<<3 | Blue;

    qb.back = Orange<<24 | Green<<21 | Red<<18
            | Green<<15 | Orange<<12 | Green<<9
            | Red<<6 | Blue<<3 | Red;

    qb.top = White<<24 | Red<<21 | Blue<<18
            | Yellow<<15 | White<<12 | Red<<9
            | Green<<6 | White<<3 | Green;

    qb.bottom = White<<24 | Orange<<21 | Orange<<18
                | White<<15 | Yellow<<12 | Blue<<9
                | Green<<6 | Orange<<3 | Blue;

    qb.left = Blue<<24 | Blue<<21 | Red<<18
            | Yellow<<15 | Green<<12 | Red<<9
            | Yellow<<6 | Green<<3 | Green;

    qb.right = Yellow<<24 | Blue<<21 | Yellow<<18
            | Yellow<<15 | Blue<<12 | Orange<<9
            | White<<6 | Red<<3 | Yellow;*/
    /*
    if (!(qb.hasProperCorners() && MiniCube(qb).getIdx() <= 3674160 && qb.isValidColorDistribution())) {
        throw std::exception();
    }*/





    //std::cout << edgeCubieDB.data.size() << std::endl;

    //89 distinct values so far
    //std::vector<uint8_t> database = edgeCubieDB.data;
    //std::sort(database.begin(), database.end());

    //int uniqueCount = std::unique(edgeCubieDB.data.begin(), edgeCubieDB.data.end());

    //std::cout << "Non-zero values in edgeCubieDB: " << nonZeroCount << std::endl;


    /*EdgeCubies edgeCubies;
    std::array<EdgeCubies, 27> neighbors = edgeCubies.getNeighbors();

    std::cout << "Neighbors of the default EdgeCubies:\n";
    for (const auto& neighbor : neighbors) {
        std::cout << neighbor << std::endl;
    }*/

    /*
    EdgeCubies edgeCubies;
    std::cout << "Starting state: \n" << edgeCubies << std::endl;
    std::cout << "Starting idx: " << edgeCubies.getIdx() << std::endl;

    //std::vector<bool> foundIndices(42577920);

    srand(time(NULL)); */

    /*
    for (int i = 0; i < 10000000; i++) {
        int nghbrIdx = rand() % 27;
        edgeCubies = edgeCubies.getNeighbors()[nghbrIdx];
        foundIndices[edgeCubies.getIdx()] = true;
    }

    std::cout << "Number of found indices: " << std::count(foundIndices.begin(), foundIndices.end(), true) << std::endl; */
    /*
    for (int i = 0; i < 20; i++) {
        int nghbrIdx = rand() % 27;
        edgeCubies = edgeCubies.getNeighbors()[nghbrIdx];
    }
    std::cout << "Random neighbor after 20 twists:\n" << edgeCubies << std::endl;

    std::cout << edgeCubies.getIdx() << std::endl;
 */
    //assert(edgeCubies.hasProperCorners() && MiniCube(edgeCubies).getIdx() <= 3674160 && edgeCubies.isValidColorDistribution());


    //std::cout << qb;
    //std::cout << qb.getNeighbors()[6];
    /*constexpr int PADDING = 12;
    alignas(uint64_t) uint8_t indices[8] = {
		PADDING+0, PADDING+1, PADDING+2, PADDING+3,
		PADDING+4, PADDING+5, PADDING+6, PADDING+7//,
		//PADDING+8, PADDING+9, PADDING+10, PADDING+11,
		//PADDING, PADDING, PADDING, PADDING
	};*/

	PDB firstEdgeCubieDB(EdgeCubies(), 42577920);
	return 0;


	constexpr int PADDING = 12;

	alignas(uint64_t) uint8_t indices0[16] = {
		0+PADDING, 1+PADDING, 2+PADDING, 3+PADDING,
		4+PADDING, 5+PADDING, 6+PADDING, 7+PADDING,
        8+PADDING, 9+PADDING, 10+PADDING, 11+PADDING,
        PADDING, PADDING, PADDING, PADDING,
	};


	alignas(uint64_t) uint8_t indices1[8] = {
	   8+PADDING, 9+PADDING, 10+PADDING, 11+PADDING,
	   PADDING, PADDING, PADDING, PADDING
	};

	std::cout << std::hex << *reinterpret_cast<uint64_t*>(indices0) << std::endl;
	std::cout << std::hex << *reinterpret_cast<uint64_t*>(indices1) << std::endl;
	return 0;

	alignas(uint64_t) uint8_t indices2[8] = {
	   0, 1, 2, 3, 4, 5, 6, 7
	};



	/*
	std::cout << std::hex << *reinterpret_cast<uint64_t*>(indices2) << std::endl;
	std::cout << (&indices2[7] - &indices2[0]) << std::endl;
	return 0;
 */
    for (uint8_t i = 0; i < 12; i++) {
        std::cout << "\n\ni = " << (int) i << std::endl;

        //I'm a genius for this
        uint64_t packed = *reinterpret_cast<uint64_t*>(indices0);
        std::cout << (int) std::min(i, (uint8_t) 8) << std::endl;
		uint64_t subtractConst = (0x0101010101010101ULL << (i*8));
		subtractConst = i <= 7 ? subtractConst : 0;
		//std::cout << std::hex << subtractConst << std::endl;
		//subtractConst = i <= 7 ? subtractConst : 0;
		packed -= subtractConst;
		*reinterpret_cast<uint64_t*>(indices0) = packed;


		packed = *reinterpret_cast<uint64_t*>(&indices0[8]);
		std::cout << std::hex << packed << std::endl << std::dec;
		subtractConst = (0x0101010101010101ULL << (std::max(i - 8, 0)*8));
		subtractConst = i-8 <= 7 ? subtractConst : 0;
		packed -= subtractConst;
		*reinterpret_cast<uint64_t*>(indices0) = packed;




    	//I'm a genius for this
        /*
    	packed = *reinterpret_cast<uint64_t*>(indices1);
    	subtractConst = (0x0000000001010101ULL << (std::max((int) i-8, 0))*8);
    	packed -= subtractConst;
    	*reinterpret_cast<uint64_t*>(indices1) = packed;
 */
        for (int j = 0; j < 12; j++) {
            std::cout << std::dec << "indices["<<j<<"]:\t" << (unsigned int) indices0[j]-PADDING << std::endl;
  		}
    }

    return 0;

    //EdgeCubies edgeCubies;
    //std::cout << edgeCubies.getIdx() << std::endl;
    //return 0;
    //lets see if I can run depth 16 overnight!
    //it can do up to 15!
    qb = qb.rotVert(Column::Middle, Direction::Up);
    qb = qb.rotHoriz(Row::Middle, Direction::_180);
    qb = qb.rotVert(Column::Right, Direction::Down);
    qb = qb.rotHoriz(Row::Bottom, Direction::Right);
    qb = qb.rotXaxis(CrossSection::Middle, Direction::Right);
    qb = qb.rotVert(Column::Right, Direction::_180);
    qb = qb.rotHoriz(Row::Bottom, Direction::Left);
    qb = qb.rotXaxis(CrossSection::Front, Direction::_180);
    qb = qb.rotVert(Column::Left, Direction::_180);
    qb = qb.rotXaxis(CrossSection::Front, Direction::Right);
    qb = qb.rotHoriz(Row::Top, Direction::Left);
    qb = qb.rotXaxis(CrossSection::Back, Direction::_180);
    qb = qb.rotVert(Column::Right, Direction::_180);
    //qb = qb.rotHoriz(Row::Bottom, Direction::_180);
    //qb = qb.rotXaxis(CrossSection::Middle, Direction::Right);
    //qb = qb.rotHoriz(Row::Bottom, Direction::Right);


    //assert(qb.hasProperCorners() && MiniCube(qb).getIdx() <= 3674160 && qb.isValidColorDistribution());


    std::cout << "Scrambled cube:\n" << qb;

    std::cout << "\nSolving cube using IDA*:" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    auto sol = idaStar(qb);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    int len = sol.first.size()-1;
    bool useAn = len==8 || len==11 || len==18;

    //Remove if compiling with GCC
    std::locale::global(std::locale(""));
    std::cout.imbue(std::locale());

    std::cout << "Done! Found " << (useAn ? "an " : "a ") <<
        (sol.first.size()-1) << " move solution in " << duration.count() << "ms :" << std::endl;
    std::cout << "Generated " << sol.second << " nodes " << std::endl;//<< "in " << duration.count() << "ms";
    //std::cout << " (" << (sol.second*1000/duration.count()) << " nodes/s)";


    for (auto cube : sol.first) {
        std::cout << cube << std::endl;
    }


    //std::cout << "Rotations per second: " << benchRotations(1000000000) << std::endl;

    return 0;
}

//54 669 934
