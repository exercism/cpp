# Instructions

As a magician-to-be, Elyse needs to practice some basics.
She has a stack of cards that she wants to manipulate.

To make things a bit easier she only uses the cards 1 to 10.

## 1. Retrieve a card from a stack

As Elyse will remove and add cards to her deck, we will use the `vector` type for the functions.

Implement the function `get_card` that returns the card at the `index` position from the given stack of cards.

```cpp
#include<vector>
std::vector<int> cards{1, 2, 4, 1};
get_card(3, cards);
// => 4
```

## 2. Change a card in the stack

Implement the function `set_card` that returns a stack that is a copy of the input stack but which has the card at position `index` changed to the new card provided.
If the given `index` is not a valid index in the stack, the original stack should be returned, unchanged.

```swift
let index = 2
let newCard = 6
setCard(at: index, in: [1, 2, 4, 1], to: newCard)
// => [1, 2, 6, 1]
```

## 3. Insert a card at the of top the stack

Implement the function `insert(_:atTopOf:)` that returns a copy of the stack with the new card provided added to the top of the stack.

```swift
let newCard = 8
insert(newCard, atTopOf: [5, 9, 7, 1])
// => [5, 9, 7, 1, 8]
```

## 4. Remove a card from the stack

Implement the function `removeCard(at:from:)` that returns a copy of the stack which has had the card at position `index` removed.
If the given `index` is not a valid index in the stack, the original stack should be returned, unchanged.

```swift
let index = 2
removeCard(at: index, from: [3, 2, 6, 4, 8])
// => [3, 2, 4, 8]
```

## 5. Remove the top card from the stack

Implement the function `removeTopCard(_:)` that returns a copy of the stack which has had the card at the top of the stack removed.
If the given stack is empty, the original stack should be returned, unchanged.

```swift
removeTopCard([3, 2, 6, 4, 8])
// => [3, 2, 6, 4]
```

## 6. Insert a card at the bottom of the stack

Implement the function `insert(_:atBottomOf:)` that returns a copy of the stack with the new card provided added to the bottom of the stack.

```swift
let newCard = 8
insert(newCard, atBottomOf: [5, 9, 7, 1])
// => [8, 5, 9, 7, 1]
```

## 7. Remove a card from the bottom of the stack

Implement the function `removeBottomCard(_:)` that returns a copy of the stack which has had the card at the bottom of the stack removed.
If the given stack is empty, the original stack should be returned, unchanged.

```swift
removeBottomCard([8, 5, 9, 7, 1])
// => [5, 9, 7, 1]
```

## 8. Check size of the stack

Implement the function `checkSizeOfStack(_:_:)` that checks whether the size of the stack is equal to a given `stackSize` or not.

```swift
let stackSize = 4
checkSizeOfStack([3, 2, 6, 4, 8], stackSize)
// => false
```

## 9. Count the number of even cards in the stack

Implement the function `evenCardCount(_:)` that steps through the stack and counts the number of even cards in it.

```swift
evenCardCount([3,8,4,5,1,6,10])
// => 4
```