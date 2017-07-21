//
// Created by Jiachen Ren on 7/21/17.
// First C++ source file I ever wrote.
//

#include "Lagrange.h"
#include <cmath>

/**
 * Sets the interval in which a output is produced.
 * Set i to 0 to disable print.
 * @param i
 */
void Lagrange::setPrintInterval(unsigned int i) {
    debugPrint = i;
}

/**
 * @param s start
 * @param t stop
 * @param maxTerms maximum allowed squared terms.
 */
Lagrange::Lagrange(int start, int stop, int maxTerms) {
    this->start = start;
    this->stop = stop;
    this->maxTerms = maxTerms;
    this->solutions = new int[maxTerms];
    this->hashMap = new int[stop + 1];
    this->results = new str[stop - start + 1];
}

/**
 * Designed by Jiachen Ren. All Rights Reserved.
 *
 * @param num      the number to be decomposed into squared numbers.
 * @param maxTerms the max number of terms allowed.
 * @return whether or not the solution is found.
 * @since July 21th.
 */
bool Lagrange::findSumRB(unsigned int num, int maxTerms) {
    int sum = 0, index = this->maxTerms - maxTerms;
    for (int i = index; i < this->maxTerms; i++) sum += solutions[i];
    if (sum == num) return true;
    else if (maxTerms == 0) return false;
    int shortcut = hashMap[num];
    if (shortcut != 0) {
        solutions[index] = shortcut * shortcut;
        return findSumRB(num - solutions[index], maxTerms - 1);
    } else
        for (int i = (int) sqrt(num); i >= 0; i--) {
            solutions[index] = i * i;
            if (findSumRB(num - solutions[index], maxTerms - 1)) {
                hashMap[num] = i;
                return true;
            }
        }
    return false;
}

/**
 * @return solutions generated from the designated number ranging from start to stop.
 */
std::string *Lagrange::solve() {
    for (int q = start; q <= stop; q++) {
        this->results[q - start] = findSumRB((unsigned int) q, maxTerms);
        if (!debugPrint || q % debugPrint != 0) continue;
        printf("%i -> ", q);
        for (int i = 0; i < 4; i++) {
            printf("[%i]", solutions[i]);
        }
        printf("\n");
    }
    return results;
}