#include <cstdio>
#include <array>
#include <cstring>
#include <iostream>
#include <vector>

#include <optional>

#include <ylib/db/dpiw.h>
#include <ylib/logging/Logger.h>

using namespace ylib::core;
using namespace ylib::db::dpiw;
using namespace ylib::logging;

#define var auto

int main(){

    Time a{3, 3, 3, 10};

println(a.toString());
    return EXIT_SUCCESS;
}
