#pragma once

#include <sstream>
#include <algorithm>
#include <ylib/core/lang.h>

namespace ylib {
namespace core {


void findAndReplaceInplace(string& txt, const string& search, const string& replace) {
    size_t pos = 0;
    while ((pos = txt.find(search, pos)) != std::string::npos) {
         txt.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

string findAndReplace(const string& txt, const string& search, const string& replace){
	string copy = txt;
	findAndReplaceInplace(copy, search, replace);
	return copy;
}
        
bool endsWith(string& txt, const char c) {
	if (txt.length() == 0) {
		return false;
	}

	size_t idx = txt.length() - 1;
	return txt.at(idx) == c;
}

string repeat(Int16 count, const char c) {
	stringstream ss;

	for (Int16 i = 0; i < count; i++) {
		ss << c;
	}

	return ss.str();
}

string numFill(Int64 num, UInt16 count, const char c) {
	checkParamIsPositive("count", count);

	string snum = std::to_string(num);

	size_t len = snum.length();

	if (len >= (size_t)count) {
		//nothing to fill.
		return snum;
	}

	size_t diff = count - len;
	stringstream ss;

	for (size_t i = 0; i < diff; i++) {
		ss << c;
	}

	ss << snum;
	return ss.str();
}

void toLowerInplace(string& txt) {

	std::transform(txt.begin(), txt.end(), txt.begin(), [](int c) {
		return std::tolower(c);
	});
}

string toLower(const string& txt) {
	string ans = txt;

	std::transform(ans.begin(), ans.end(), ans.begin(), [](int c) {
		return std::tolower(c);
	});

	return ans;
}

string toLower(const char* txt) {
	string stxt{ txt };
	return toLower(stxt);
}


string trim(const string& txt) {
	return __ylib_core_trim(txt);
}

string trim(const string&& txt) {
    return __ylib_core_trim(txt);
}

Bool isStrBlank(const char* s){

	for(size_t i =0; ; i++){
		char c = s[i];
		if(c == '\0'){
			break;
		}

		if(isblank(c) == false){
			return False;
		}
	}

	return True;
}



}//namespace core
}//namespace ylib
