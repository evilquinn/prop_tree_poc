#ifndef C_PROP_TREE_H
#define C_PROP_TREE_H

#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct c_prop_tree;

struct c_prop_tree* c_prop_tree_create();
void c_prop_tree_destroy(struct c_prop_tree* ptree);
bool c_prop_tree_read_json(struct c_prop_tree* ptree, const char* json_data);
bool c_prop_tree_get_string(struct c_prop_tree* ptree,
                            const char* key,
                            char* buf,
                            size_t buf_size);

#ifdef __cplusplus
}
#endif

#endif // C_PROP_TREE_H
