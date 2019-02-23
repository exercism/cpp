#include "binary_search_tree.h"
#include <exception>

namespace binary_tree
{
    // tree

    binary_tree::binary_tree(const tree_data_t data)
    : _data(data),
      _left(nullptr),
      _right(nullptr)
    {}

    const binary_tree::tree_data_t &binary_tree::data() const
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

    // iterator

    binary_tree::binary_tree_iter::binary_tree_iter(const binary_tree_ptr &tree)
    : _tree(tree),
      _side_iter(build_first_side_iter(tree))
    {
        _state = _tree->left() ? state::Left : state::Middle;
    }

    binary_tree::binary_tree_iter::binary_tree_iter_ptr binary_tree::binary_tree_iter::build_first_side_iter(const binary_tree_ptr &tree)
    {
        if (!tree->left())
            return nullptr;
        return binary_tree_iter_ptr(new binary_tree_iter(tree->left()));
    }

    binary_tree::binary_tree_iter binary_tree::binary_tree_iter::build_end_iterator(const binary_tree_ptr &tree)
    {
        binary_tree_iter iter(tree);
        iter._side_iter.reset(nullptr);
        iter._state = state::Done;

        return iter;
    }

    // binary_tree::binary_tree_iter::binary_tree_iter(binary_tree_iter &other)
    // : _tree(other._tree),
    //   _state(other._state),
    //   _side_iter()
    // {
    // }

    // binary_tree::binary_tree_iter::binary_tree_iter_ptr binary_tree::binary_tree_iter::copy_side_iter(const binary_tree::binary_tree_iter &other)
    // {
    //     if (!other._side_iter)
    //         return nullptr;
    //     return binary_tree_iter_ptr(new binary_tree_iter(*other._side_iter);
    // }

    bool binary_tree::binary_tree_iter::operator==(const binary_tree::binary_tree_iter &other) const
    {
        if (_tree != other._tree)
            return false;
        if (_state != other._state)
            return false;
        return _side_iter == other._side_iter;
    }

    bool binary_tree::binary_tree_iter::operator!=(const binary_tree_iter &other) const
    {
        return !(*this == other);
    }

    const binary_tree::tree_data_t& binary_tree::binary_tree_iter::operator*() const
    {
        switch (_state)
        {
        case state::Done:
            throw std::out_of_range("Access of iterator after end");
        case state::Middle:
            return _tree->data();
        case state::Left:
        case state::Right:
            return _side_iter->operator*();
        default:
            throw std::logic_error("Missing switch value");
        }
    }

    const binary_tree::tree_data_t* binary_tree::binary_tree_iter::operator->() const
    {
        return &this->operator*();
    }

    binary_tree::binary_tree_iter& binary_tree::binary_tree_iter::operator++()
    {
        switch (_state)
        {
        case state::Done:
            throw std::out_of_range("Cannot advance iterator after end");
        case state::Middle:
            if (!_tree->right())
            {
                _state = state::Done;
                break;
            }
            _state = state::Right;
            _side_iter = binary_tree_iter_ptr(new binary_tree_iter(_tree->right()));
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

    void binary_tree::binary_tree_iter::advance_side_iter(state next_state)
    {
        _side_iter->operator++();
        if (_side_iter->_state == state::Done)
        {
            _side_iter.reset(nullptr);
            _state = next_state;
        }
    }
}