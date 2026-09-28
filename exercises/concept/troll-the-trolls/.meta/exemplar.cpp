namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };

enum class Action { read, write, remove };

bool display_post(AccountStatus poster, AccountStatus viewer) {
    if (poster == AccountStatus::troll) {
        return viewer == AccountStatus::troll;
    }
    return true;
}

bool permission_check(Action action, AccountStatus status) {
    switch (action) {
        case Action::remove:
            return status == AccountStatus::mod;

        case Action::write:
            return status != AccountStatus::guest;

        default:
            return true;
    }
}

bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
    if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
        return false;
    }
    if (player1 == AccountStatus::troll && player2 != AccountStatus::troll) {
        return false;
    }
    if (player1 != AccountStatus::troll && player2 == AccountStatus::troll) {
        return false;
    }
    return true;
}

bool has_priority(AccountStatus player1, AccountStatus player2) {
    return static_cast<int>(player1) > static_cast<int>(player2);
}

}  // namespace hellmath
