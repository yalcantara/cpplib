#include <cstdio>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>

#include <optional>

#include <ylib/db/dpiw.h>
#include <ylib/logging/Logger.h>

using namespace ylib::db::dpiw;
using namespace ylib::logging;

#define var auto

int main(){

    Int64 n = 23;
    string val = numFill(n, 3, '0');

    println(val);

    return EXIT_SUCCESS;
}
