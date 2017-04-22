//
//  vector_util.h
//
//  Created by Rick Lan on 4/9/17.
//  See LICENSE
//

#ifndef vector_util_h
#define vector_util_h

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

template <class T>
void display(std::vector<T> &vec) {
    //cout << "[" << ii << "]: " << vec[ii] << " " << endl;
    std::cout << "[ ";
    for (T val : vec) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
}

template <class T>
void read(unsigned long N, const std::string &data, std::vector<T> &vec) {
    
    std::stringstream ss(data);
    vec.resize(N);
    for (unsigned ii = 0; ii < N; ii++) {
        ss >> vec[ii];
    }
}


#endif /* vector_util_h */
