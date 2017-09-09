#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "c_prop_tree.h"

namespace pt = boost::property_tree;

static const char* const some_data =
    "{ \"source\": \"applepay\", \"services\": \"something\" }";

int main(int argc, char* argv[])
{
    pt::ptree json_data;
    std::istringstream is(some_data);
    pt::read_json(is, json_data);

    std::cout << "source: "
              << json_data.get<std::string>("source") << std::endl;

    struct c_prop_tree* cptree = c_prop_tree_create();
    c_prop_tree_read_json(cptree, some_data);
    char buf[100];
    c_prop_tree_get_string(cptree, "source", buf, sizeof(buf));

    std::cout << "source: " << buf << std::endl;

    c_prop_tree_destroy(cptree);

    return 0;
}
