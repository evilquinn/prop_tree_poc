#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include "c_prop_tree.h"

namespace pt = boost::property_tree;

struct c_prop_tree
{
    pt::ptree prop_tree;
};

struct c_prop_tree* c_prop_tree_create()
{
    struct c_prop_tree* cptree = new struct c_prop_tree();
    return cptree;
}

void c_prop_tree_destroy(struct c_prop_tree* ptree)
{
    delete ptree;
}

bool c_prop_tree_read_json(struct c_prop_tree* ptree, const char* json)
{
    std::istringstream json_is(json);
    pt::read_json(json_is, ptree->prop_tree);
    return true;
}

bool c_prop_tree_get_string(struct c_prop_tree* ptree,
                            const char* key,
                            char* buf,
                            size_t buf_size)
{
    std::string temp = ptree->prop_tree.get<std::string>(key);
    snprintf(buf, buf_size, "%s", temp.c_str());
    return true;
}
