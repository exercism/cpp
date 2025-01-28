# Hints

## 1. Bring humans to the world of Troy

- The core of this exercise is the usage of `unique_ptr` and `shared_ptr`.
  Which kind of smart pointer should be used for each of the `human` variables?
- `artifacts` are not shared, but `powers` are needed to track influenced people.
- the `possession` pointer should be unique, the power pointers should be shared.

## 2. Bring Artifacts into Troy

- You need to create a smart pointer and assign it to the `possession` variable
- Use _references_ to change the object outside of the function.
- Look up [`std::make_unique`][make_unique] for some hints.
- The type of the pointer's target object has to be put in the angled brackets and again inside the parens to define the object.
- Here is a full example: `variable = std::make_unique<int>(int{23});`

## 3. Make items tradeable

- You can look through the [unique_ptr reference][unique_ptr] to find a fitting function.
- Do you think `std::swap` can help you?

## 4. Give Power to the People

- You need to create a smart pointer and assign it to the `own_power` variable
- Use _references_ to change the object outside of the function.
- Look up [`std::make_shared`][make_shared] for some hints.
- The type of the pointer's target object has to be put in the angled brackets and again inside the parens to define the object.
- Here is a full example: `variable = std::make_shared<int>(int{23});`

## 5. Use the Power

- Use _references_ to change the object outside of the function.

## 6. Keep watch on the power's intensity

- You can look through the [shared_ptr reference][shared_ptr] to find a fitting function.
- Do you think `use_count` can help you?

[unique_ptr]: https://en.cppreference.com/w/cpp/memory/unique_ptr
[make_unique]: https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
[shared_ptr]: https://en.cppreference.com/w/cpp/memory/shared_ptr
[make_shared]: https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
