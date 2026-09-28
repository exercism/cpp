# Instructions

Your friend Helma made a small online game that rapidly gained popularity.
It is called _HellMath_.
The small community attracted some trolls who make the game and the forums pretty unpleasant.
Helma has asked you to work on a new permission system to separate troublemakers.

The forum supports three different actions:

- Read
- Write
- Remove

There are four types of accounts, each with different default permissions:

- Guests: can read posts.
- Users and Trolls: can read and write posts.
- Moderators: can read, write and remove posts, they have all the permissions.

Helma has noticed that it is no use to ban troll accounts.
Her strategy is to give them the illusion that their time is "well invested", but their posts are only shown to other trolls.
For anything that requires priority ordering, trolls are last in any sequence.
When they enter a game, the pool of available players is also limited to other trolls.

This practice is called [shadow-banning][shadow-ban].

## 1. Set up user types and permissions.

First, define an `AccountStatus` enumeration to represent the four account types: `troll`, `guest`, `user`, and `mod`.

Next, define an `Action` enumeration to represent the three permission types: `read`, `write`, and `remove`.


## 2. Promote trolls only to other trolls.

Every post on the forums saves the `AccountStatus` of the poster in its metadata.
Make sure that posts by trolls are only displayed to other trolls.

Helma needs a `display_post` function, that gets two arguments of `AccountStatus` and returns a `bool`.
The first argument is the status of the poster, the second one is the status of the viewer.

```cpp
using namespace hellmath;
display_post(AccountStatus::troll, AccountStatus::user);
// => false
display_post(AccountStatus::mod, AccountStatus::guest);
// => true
```

## 3. Check permissions for different users.

Helma needs a way to check if a certain action is allowed for a user.

Please implement a `permission_check` function, that takes an `Action` as a first argument and an `AccountStatus` to check against.
It should return a `bool` according to the permissions listed in the introduction.

```cpp
permission_check(Action::remove, AccountStatus::guest);
// => false
permission_check(Action::write, AccountStatus::mod);
// => true
```

## 4. Grant game access and pair players.

To keep the actual players in the game accountable for their actions, _Hellmath_ denies access to guest users.
As mentioned above, Helma wants trolls to troll other trolls.
Game connections between other users are unrestricted.

Implement the `valid_player_combination` function that checks if two players can join the same game.
The function has two parameters of type `AccountStatus` and returns a `bool`.

```cpp
valid_player_combination(AccountStatus::guest, AccountStatus::mod);
// => false
valid_player_combination(AccountStatus::troll, AccountStatus::troll);
// => true
```

## 5. Build priority queuing.

With the massive growth of the game and the forums, Helma now has to distribute computing power and bandwidth among users.
To handle emergencies, moderators are given the highest priority.
Guests are queued behind normal users, and trolls get sorted behind everyone else.

Implement the `has_priority` function that takes two `AccountStatus` arguments and returns `true`, if and only if the first account has a strictly higher priority than the second.

```cpp
has_priority(AccountStatus::guest, AccountStatus::mod);
// => false
has_priority(AccountStatus::user, AccountStatus::troll);
// => true
```

[shadow-ban]: https://en.wikipedia.org/wiki/Shadow_banning
