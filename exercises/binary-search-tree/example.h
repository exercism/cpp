#if !defined(_BINARY_SEARCH_TREE_H_)
#define _BINARY_SEARCH_TREE_H_

#include <memory>
#include <cstdint>
#include <utility>
#include <stdexcept>

namespace binary_search_tree
{
    template <bool B, class T = void>
    using enable_if_t = typename std::enable_if<B, T>::type;
    template <typename T>
    using remove_reference_t = typename std::remove_reference<T>::type;

    template<typename T>
    class binary_tree final
    {
    public:
        class binary_tree_iter;
        using binary_tree_ptr = std::unique_ptr<binary_tree>;

        template <typename TParam,
                  typename = enable_if_t<std::is_constructible<T, remove_reference_t<TParam>>::value>>
        explicit binary_tree(TParam &&data)
            : _data(std::forward<TParam>(data)),
              _left(nullptr),
              _right(nullptr)
        {}

        ~binary_tree() = default;

        binary_tree(binary_tree &) = delete;
        binary_tree& operator=(binary_tree &) = delete;

        binary_tree(binary_tree &&) = delete;
        binary_tree&& operator=(binary_tree &&) = delete;

    public:
        template <typename TParam,
                  typename = enable_if_t<std::is_constructible<T, remove_reference_t<TParam>>::value>>
        void insert(TParam &&data);

        const T &data() const {return _data;};
        const binary_tree_ptr& left() const {return _left;};
        const binary_tree_ptr& right() const {return _right;};

        binary_tree_iter begin() const;
        binary_tree_iter end() const;
        
    private:
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
                LEFT,
                RIGHT,
                MIDDLE,
                DONE
            };

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
            void advance_branch_iter(state next_state);
            static binary_tree_iter_ptr build_first_branch_iter(const binary_tree &tree);
            static binary_tree_iter_ptr copy_branch_iter(const binary_tree_iter &other);

            const binary_tree &_tree;
            state _state;
            binary_tree_iter_ptr _branch_iter;
        };
    };

    // tree

    template <typename T>
    template <typename TParam, typename>
    void binary_tree<T>::insert(TParam &&data)
    {
        binary_tree_ptr &insert_location = data > _data ? _right : _left;
        if (!insert_location)
            insert_location = binary_tree_ptr(new binary_tree(std::forward<TParam>(data)));
        else
            insert_location->insert(std::forward<TParam>(data));
    }

    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::begin() const {return binary_tree_iter(*this);}
    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::end() const {return binary_tree_iter::build_end_iterator(*this);}


    // iter
    template<typename T>
    binary_tree<T>::binary_tree_iter::binary_tree_iter(const binary_tree<T> &tree)
    : _tree(tree),
      _branch_iter(build_first_branch_iter(tree))
    {
        _state = _tree.left() ? state::LEFT : state::MIDDLE;
    }

    template<typename T>
    typename binary_tree<T>::binary_tree_iter::binary_tree_iter_ptr binary_tree<T>::binary_tree_iter::build_first_branch_iter(const binary_tree &tree)
    {
        if (!tree.left())
            return nullptr;
        return binary_tree_iter_ptr(new binary_tree_iter(*tree.left()));
    }


    template<typename T>
    typename binary_tree<T>::binary_tree_iter binary_tree<T>::binary_tree_iter::build_end_iterator(const binary_tree<T> &tree)
    {
        binary_tree_iter iter(tree);
        iter._branch_iter.reset(nullptr);
        iter._state = state::DONE;

        return iter;
    }

    template<typename T>
    bool binary_tree<T>::binary_tree_iter::operator==(const binary_tree<T>::binary_tree_iter &other) const
    {
        if (&_tree != &other._tree)
            return false;
        if (_state != other._state)
            return false;
        return _branch_iter == other._branch_iter;
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
        case state::DONE:
            throw std::out_of_range("Access of iterator after end");
        case state::MIDDLE:
            return _tree.data();
        case state::LEFT:
        case state::RIGHT:
            return _branch_iter->operator*();
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
        case state::DONE:
            throw std::out_of_range("Cannot advance iterator after end");
        case state::MIDDLE:
            if (!_tree.right())
            {
                _state = state::DONE;
                break;
            }
            _state = state::RIGHT;
            _branch_iter = binary_tree_iter_ptr(new binary_tree_iter(*_tree.right()));
            break;
        case state::LEFT:
            advance_branch_iter(state::MIDDLE);
            break;
        case state::RIGHT:
            advance_branch_iter(state::DONE);
            break;
        default:
            throw std::logic_error("Missing switch value");
        }

        return *this;
    }

    template<typename T>
    void binary_tree<T>::binary_tree_iter::advance_branch_iter(state next_state)
    {
        _branch_iter->operator++();
        if (_branch_iter->_state == state::DONE)
        {
            _branch_iter.reset(nullptr);
            _state = next_state;
        }
    }

}

#endif // _BINARY_SEARCH_TREE_H_
