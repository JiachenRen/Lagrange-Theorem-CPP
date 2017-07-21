//
// Created by Jiachen Ren on 7/21/17.
// First C++ header I ever wrote.
//

#ifndef BACKTRACKING_LAGRANGE_LAGRANGE_H
#define BACKTRACKING_LAGRANGE_LAGRANGE_H

#include <string>

class Lagrange {
    typedef std::string str;
    int* hashMap;
    str* results;
    int* solutions;
    unsigned int debugPrint;
    int start;
    int stop;
    int maxTerms;
private:
    bool findSumRB(unsigned int num, int maxTerms);
    unsigned int onePercentStp;
public:
    Lagrange(int start, int stop, int maxTerms);
    void setPrintInterval(unsigned int i);
    str* solve();
};


#endif //BACKTRACKING_LAGRANGE_LAGRANGE_H
