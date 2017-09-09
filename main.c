
#include <c_prop_tree.h>
#include <stdio.h>

static const char* const some_data =
    "{ \"source\": \"applepay\", \"services\": \"something\" }";

int main(int argc, char* argv[])
{

    struct c_prop_tree* cptree = c_prop_tree_create();
    c_prop_tree_read_json(cptree, some_data);

    char buf[100];
    c_prop_tree_get_string(cptree, "source", buf, sizeof(buf));

    printf("source: %s\n", buf);

    c_prop_tree_destroy(cptree);
    return 0;
}
