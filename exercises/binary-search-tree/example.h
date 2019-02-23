#if !defined(_BINARY_SEARCH_TREE_H_)
#define _BINARY_SEARCH_TREE_H_

#include <memory>
#include <cstdint>

namespace binary_tree
{
    class binary_tree final
    {
    public:
        class binary_tree_iter;

        using tree_data_t = uint32_t;
        using binary_tree_ptr = std::unique_ptr<binary_tree>;

        explicit binary_tree(tree_data_t data);
        ~binary_tree() = default;

        binary_tree(binary_tree &) = delete;
        binary_tree& operator=(binary_tree &) = delete;

        binary_tree(binary_tree &&) = delete;
        binary_tree&& operator=(binary_tree &&) = delete;

        void insert(tree_data_t data);

        const tree_data_t &data() const;
        const binary_tree_ptr& left() const;
        const binary_tree_ptr& right() const;

        binary_tree_iter begin() const;
        binary_tree_iter end() const;

    private:
        void insert(tree_data_t data, binary_tree_ptr &location);
        
        tree_data_t _data;
        binary_tree_ptr _left;
        binary_tree_ptr _right;

    public:
        class binary_tree_iter final
        {
            friend binary_tree_iter binary_tree::begin() const;
            friend binary_tree_iter binary_tree::end() const;
        public:
            using binary_tree_iter_ptr = std::unique_ptr<binary_tree_iter>;
        private:
            enum class state
            {
                Left,
                Right,
                Middle,
                Done
            };

            const binary_tree &_tree;
            state _state;
            binary_tree_iter_ptr _side_iter;

            explicit binary_tree_iter(const binary_tree &tree);
            static binary_tree_iter build_end_iterator(const binary_tree &tree);

        public:
            ~binary_tree_iter() = default;

            binary_tree_iter(binary_tree_iter &) = delete;
            binary_tree_iter & operator=(binary_tree_iter &) = delete;

            binary_tree_iter(binary_tree_iter &&) = default;
            binary_tree_iter & operator=(binary_tree_iter &&) = default;

            const tree_data_t& operator*() const;
            const tree_data_t* operator->() const;
            binary_tree_iter& operator++();

            bool operator==(const binary_tree_iter &) const;
            bool operator!=(const binary_tree_iter &) const;
        
        private:
            void advance_side_iter(state next_state);
            static binary_tree_iter_ptr build_first_side_iter(const binary_tree &tree);
            static binary_tree_iter_ptr copy_side_iter(const binary_tree_iter &other);
        };
    };
}

#endif // _BINARY_SEARCH_TREE_H_
