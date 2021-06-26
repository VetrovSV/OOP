#include <math.h>       // для random
#include "random_name.h"

const std::vector< std::string > NAMES = {"Llewellyn", "Redd", "Daniel", "Aldrich", "Herebert", 
"Ealric", "Alric", "Havarr", "Havarr", "Ingvarr", "Kyra", "Keila", "Gretchen", "Clare", "Hildegyth",
"Cynwise", "Aedwen", "Inger", "Hannah", "Bera"};


std::string random_name(){
    return NAMES[ rand()%NAMES.size() ];
}