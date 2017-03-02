#ifndef NR_FUNC_H_INCLUDED
#define NR_FUNC_H_INCLUDED

class nr_func {
public:
    static unsigned int nr_indexof(const char *, const char *);
    static char *nr_substr(const char *, int, int);
    static bool nr_equals(const char *, const char *);
};

#endif // NR_FUNC_H_INCLUDED
