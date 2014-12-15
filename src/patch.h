/*
 * patch.h
 *
 *  Created on: 12 dec 2014
 *      Author: Niclas
 */

#ifndef PATCH_H_
#define PATCH_H_
#include <sstream>

namespace patch
{
template < typename T > std::string to_string(const T& n)
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
}



#endif /* SRC_PATCH_H_ */
