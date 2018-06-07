#include <unordered_map>
#include <functional>
#include <cstring>
#include <cstdio>
#include "symbol.h"
#include "utils.h"

struct str_cmp{
    bool operator()(char *s1, char *s2) const
    {
        return std::strcmp(s1, s2) == 0;
    }
};

struct str_hash_func{
    size_t operator()(char *str) const
    {
        int strLength = 0;
        size_t result = 0;
        const size_t prime = 31;

        for (; *(str + strLength) != '\0'; ++strLength)
        	result = result * prime + str[strLength];

        return result;
    }
};

typedef std::unordered_map<char*, S_symbol, str_hash_func, str_cmp> SymbolHashMap;

SymbolHashMap symbolMap;

S_symbol S_Symbol(char * name){
	S_symbol s = NULL;
	if(symbolMap.find(name) == symbolMap.end()){
		s = (S_symbol)checked_malloc(sizeof(*s));
		s->name = (char*)checked_malloc(sizeof(char) * (std::strlen(name)+1) );
		std::strcpy(s->name, name);
		symbolMap[name] = s;
	}else{
		s = symbolMap[name];
	}
	
	return s;
}

char *S_name(S_symbol s){
	return s->name;
}