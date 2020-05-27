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

    var log = Logger::get("main");

    DBEnvironment env;
    string user = std::getenv("app_user");
    string pass = std::getenv("app_pass");
    string tnsn = std::getenv("app_tnsn");


    var conn = env.connect(user, pass, tnsn);
    var stmt = conn.statement("insert into employees(name) values (:1)");

    stmt.setString("1", "Lebron");
    stmt.exec();
    var rowId = stmt.getLastRowId();

    println(rowId);
    conn.commit();

    log.info("pop");
    return EXIT_SUCCESS;
}
