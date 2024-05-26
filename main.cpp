#include <ctime>
#include <cstdlib>
#include "testSort.hpp"

using namespace std;

int main()
{
    srand(time(0));
    int insTestSizes[] = {1000, 2000, 4000, 8000, 16000};
    int merTestSizes[] = {32000, 64000, 128000, 256000, 512000};
// if you're still getting errors on array allocations, try a smaller set of sizes:
// int merTestSizes[] = {16000, 32000, 64000, 128000, 256000};
    int numSizes = 5;
// change the last parameter to the number of sorting functions you are prepared to run:
// 1 = insertion
// 2 = insertion + merge
// 3 = insertion + merge + merge-insertion
    runTests(insTestSizes, merTestSizes, numSizes, 3);
    return 0;
}
