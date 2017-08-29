#define notnull(m) \
if (NULL==(m)) { \
    std::cerr << "null pointer line " << __LINE__ << std::endl; \
    abort(); \
}
