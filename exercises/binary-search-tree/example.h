#if !defined(_BINARY_SEARCH_TREE_H_)
#define _BINARY_SEARCH_TREE_H_

#include <memory>
#include <cstdint>

namespace binary_tree
{
    template<typename T>
    class binary_tree final
    {
    public:
        class binary_tree_iter;
        using binary_tree_ptr = std::unique_ptr<binary_tree>;

        explicit binary_tree(T data)
            : _data(std::move(data)),
              _left(nullptr),
              _right(nullptr)
        {}

        ~binary_tree() = default;

        binary_tree(binary_tree &) = delete;
        binary_tree& operator=(binary_tree &) = delete;

        binary_tree(binary_tree &&) = delete;
        binary_tree&& operator=(binary_tree &&) = delete;

    public:
        void insert(const T &data);

        const T &data() const {return _data;};
        const binary_tree_ptr& left() const {return _left;};
        const binary_tree_ptr& right() const {return _right;};

        binary_tree_iter begin() const;
        binary_tree_iter end() const;
        
    private:
        void insert(const T &data, binary_tree_ptr &location);
        T _data;
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

            const T& operator*() const;
            const T* operator->() const;
            binary_tree_iter& operator++();

            bool operator==(const binary_tree_iter &) const;
            bool operator!=(const binary_tree_iter &) const;
        
        private:
            void advance_side_iter(state next_state);
            static binary_tree_iter_ptr build_first_side_iter(const binary_tree &tree);
            static binary_tree_iter_ptr copy_side_iter(const binary_tree_iter &other);
        };
    };

    // tree

    template<typename T>
    void binary_tree<T>::insert(const T &data, binary_tree<T>::binary_tree_ptr &location)
    {
        if (!location)
            location = binary_tree_ptr(new binary_tree(data));
        else
            location->insert(data);   
    }

    template<typename T>
    void binary_tree<T>::insert(const T &data)
    {
        binary_tree_ptr &insert_location = data > _data ? _right : _left;
        insert(data, insert_location);
    }

    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::begin() const {return binary_tree_iter(*this);}
    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::end() const {return binary_tree_iter::build_end_iterator(*this);}


    // iter
    template<typename T>
    binary_tree<T>::binary_tree_iter::binary_tree_iter(const binary_tree<T> &tree)
    : _tree(tree),
      _side_iter(build_first_side_iter(tree))
    {
        _state = _tree.left() ? state::Left : state::Middle;
    }

    template<typename T>
    typename binary_tree<T>::binary_tree_iter::binary_tree_iter_ptr binary_tree<T>::binary_tree_iter::build_first_side_iter(const binary_tree &tree)
    {
        if (!tree.left())
            return nullptr;
        return binary_tree_iter_ptr(new binary_tree_iter(*tree.left()));
    }


    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::binary_tree_iter::build_end_iterator(const binary_tree<T> &tree)
    {
        binary_tree_iter iter(tree);
        iter._side_iter.reset(nullptr);
        iter._state = state::Done;

        return iter;
    }

    template<typename T>
    bool binary_tree<T>::binary_tree_iter::operator==(const binary_tree<T>::binary_tree_iter &other) const
    {
        if (&_tree != &other._tree)
            return false;
        if (_state != other._state)
            return false;
        return _side_iter == other._side_iter;
    }


    template<typename T>
    bool binary_tree<T>::binary_tree_iter::operator!=(const binary_tree_iter &other) const
    {
        return !(*this == other);
    }

    template<typename T>
    const T& binary_tree<T>::binary_tree_iter::operator*() const
    {
        switch (_state)
        {
        case state::Done:
            throw std::out_of_range("Access of iterator after end");
        case state::Middle:
            return _tree.data();
        case state::Left:
        case state::Right:
            return _side_iter->operator*();
        default:
            throw std::logic_error("Missing switch value");
        }
    }

    template<typename T>
    const T* binary_tree<T>::binary_tree_iter::operator->() const
    {
        return &this->operator*();
    }

    template<typename T>
    typename binary_tree<T>::binary_tree_iter& binary_tree<T>::binary_tree_iter::operator++()
    {
        switch (_state)
        {
        case state::Done:
            throw std::out_of_range("Cannot advance iterator after end");
        case state::Middle:
            if (!_tree.right())
            {
                _state = state::Done;
                break;
            }
            _state = state::Right;
            _side_iter = binary_tree_iter_ptr(new binary_tree_iter(*_tree.right()));
            break;
        case state::Left:
            advance_side_iter(state::Middle);
            break;
        case state::Right:
            advance_side_iter(state::Done);
            break;
        default:
            throw std::logic_error("Missing switch value");
        }

        return *this;
    }

    template<typename T>
    void binary_tree<T>::binary_tree_iter::advance_side_iter(state next_state)
    {
        _side_iter->operator++();
        if (_side_iter->_state == state::Done)
        {
            _side_iter.reset(nullptr);
            _state = next_state;
        }
    }

}

#endif // _BINARY_SEARCH_TREE_H_
