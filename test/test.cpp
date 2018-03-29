#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

void waitFor(int s) {
    int start = time();
    while(true) {
        if (time() >= start + s)
            break;
    }
}

int main () {
    int spaces = 80;
    int totalHashes = 20;
    int hashes;
    double percent;
    std::cout << "Testing out a progress bar" << std::endl;
    for (int i = 0; i < spaces; i++) {
        percent = (double)i/spaces;
        hashes = (int)(percent*totalHashes);
        std::cout << "\r";
        std::cout << "[";
        for (int j = 0; j < hashes; j++) {
            std::cout << "#";
            if (j == hashes-1 && hashes != totalHashes) {
                std::cout << ">";
            }
        }

        for (int k = 0; k < totalHashes - hashes; k++) {
            std::cout << " ";
        }
        std::cout << "]";
    }
}