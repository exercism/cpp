#include "binary_search_tree.h"

namespace binary_tree
{
    binary_tree::binary_tree(const tree_data_t data)
    : _data(data),
      _left(nullptr),
      _right(nullptr)
    {}

    binary_tree::tree_data_t binary_tree::data() const
    {
        return _data;
    }

    const binary_tree::binary_tree_ptr &binary_tree::left() const
    {
        return _left;
    }

    const binary_tree::binary_tree_ptr &binary_tree::right() const
    {
        return _right;
    }

    void binary_tree::insert(const tree_data_t data, binary_tree_ptr &location)
    {
        if (!location)
            location = binary_tree_ptr(new binary_tree(data));
        else
            location->insert(data);
    }
    
    void binary_tree::insert(const tree_data_t data)
    {
        binary_tree_ptr &insert_location = data > _data ? _right : _left;
        insert(data, insert_location);
    }
}