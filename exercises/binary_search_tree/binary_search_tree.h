#if !defined(_BINARY_SEARCH_TREE_H_)
#define _BINARY_SEARCH_TREE_H_

#include <memory>
#include <cstdint>

namespace binary_tree
{
    class binary_tree final
    {
    public:
        using tree_data_t = uint32_t;
        using binary_tree_ptr = std::unique_ptr<binary_tree>;

        explicit binary_tree(tree_data_t data);
        ~binary_tree() = default;

        binary_tree(binary_tree &) = delete;
        binary_tree &operator=(binary_tree &) = delete;

        binary_tree(binary_tree &&) = delete;
        binary_tree &&operator=(binary_tree &&) = delete;

        void insert(tree_data_t data);

        tree_data_t data() const;
        const binary_tree_ptr& left() const;
        const binary_tree_ptr& right() const;

    private:
        void insert(tree_data_t data, binary_tree_ptr &location);
        
        tree_data_t _data;
        binary_tree_ptr _left;
        binary_tree_ptr _right;
    };
}

#endif // _BINARY_SEARCH_TREE_H_
