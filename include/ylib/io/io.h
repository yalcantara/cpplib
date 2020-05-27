#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <string>

#include <ylib/core/sutils.h>

using ylib::core::endsWith;

namespace ylib {
namespace io {
        

    void write(string& path, string& content) {
        FILE* file = fopen(path.c_str(), "w");
        if (file == NULL) {
            throw Exception(sfput("Could not open file: '${}'.", path));
        }

        fprintf(file, "%s", content.c_str());
        fflush(file);
        fclose(file);
    };

    void writeln(const char* dir, const char* fileName, const char* mode, const char* content) {

        string full;

        string sdir{ dir };
        string sfileName{ fileName };
        if (endsWith(sdir, '/')) {
            full = sdir + fileName;
        } else {
            full = sdir + "/" + fileName;
        }

        struct stat sb;
        if (stat(dir, &sb) != 0 || S_ISDIR(sb.st_mode) == false) {

            if (mkdir(dir, 0777) != 0) {
                throw Exception(sfput("The directory '${}' does not exist and could not be created.", dir));
            }

            
        }

        FILE* file = fopen(full.c_str(), mode);
        if (file == NULL) {
            throw Exception(sfput("Could not open file: '${}'.", full));
        }

        fprintf(file, "%s", content);
        fputc('\n', file);
        fflush(file);
        fclose(file);
    }

    void writeln(string& dir, string& fileName, const char* mode, string& content) {
        writeln(dir.c_str(), fileName.c_str(), mode, content.c_str());
    }

    void writeln(const char* dir, string& fileName, const char* mode, string& content) {
        writeln(dir, fileName.c_str(), mode, content.c_str());
    }

    void write(string&& path, string& content) {
        write(path, content);
    }
}
}