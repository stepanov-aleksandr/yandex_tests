#include "jewels_stone.h"

void JewelsStone() {
    try {
        std::string jc(
            (std::istreambuf_iterator<char>(
                *(std::shared_ptr<std::ifstream>(new std::ifstream("input.txt")))
                     .get())),
            std::istreambuf_iterator<char>());

        auto end = std::find(jc.begin(), jc.end(), '\n');

        int jewels = 0;

        for (auto stone = end + 1; stone != jc.end(); stone++) {
            if (std::count(jc.begin(), end, *stone)) jewels++;
        }
        std::cout << jewels << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exeption = " << e.what() << std::endl;
    }
}
