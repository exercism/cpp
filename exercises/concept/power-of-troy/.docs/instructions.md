# Instructions

This exercise takes you to the world of Troy.
The lives of its people are full of wonder and magic.
Many humans in Troy possess _powers_, that are used frequently in their daily lives.
Powers are used to re-shape the world or influence Troy's fauna and other people.
Magic also manifests in _unique artifacts_, that are highly sought after by adventurers, artisans and sages.

In this exercise you are going to write code to model the humans of Troy, their possessed artifacts and power interactions.

You have six tasks.
The first one is related to creating a human, the other five are about handling powers and artifacts.

## 1. Bring humans to the world of Troy

For your model of Troy humans are the most important feature.
Your model human should be able to possess a _unique artifact_.
They should also have the ability to manifest a _power_.
These powers might affect other humans, so you also want to model if a human is influenced by some other power.

You are provided with basic implementations of `artifact` and `power` structs.
Implement a `human` struct (or class) that has a _smart-pointer_ to an `artifact` as `possession` member variable.
Each artifact can only be possessed by a single human at any given time.

The `human` should also have variables for their `own_power` and `influenced_by`, which should be _smart-pointers_ to `powers`.
Each `power` might be owned by a single human, but also influence other humans at the same time.

By default, humans are born without any artifact and neither own any powers nor are they influenced by them.

```cpp
human mindy_mccready{};
mindy_mccready.possession;
// => nullptr
mindy_mccready.own_power;
// => nullptr
mindy_mccready.influenced_by;
// => nullptr
```

## 2. Bring Artifacts into Troy

Your model is boring without the interaction of its parts.
You want to create unique artifacts and give them to certain humans.

Define the function `give_new_artifact` which returns nothing but takes a `human` and a `string`.
With the `string` it should define a new `artifact` object and set the `possession` pointer of the `human` accordingly.
The function should not return anything.

```cpp
human erik_magnus_lehnsherr{};
give_new_artifact(erik_magnus_lehnsherr, "Mind shielding helmet");

erik_magnus_lehnsherr.possession->name;
// "Mind shielding helmet"
```

## 3. Make items tradeable

The world of Troy is all about interaction.
You want people to make trades by exchanging their possessions.

Write a function `exchange_artifacts` that returns nothing but takes two artifact smart-pointers to exchange the items.
Remember, that you cannot copy a `unique_ptr`.
This includes the usage in function parameters.
Use a reference to the `unique_ptr` instead.

```cpp
human uchiha{};
give_new_artifact(uchiha, "konoha headband");
human uzumaki{};
give_new_artifact(uzumaki, "forehead protector");

exchange_artifacts(uchiha.possession, uzumaki.possession);

uchiha.possession->name;
// "forehead protector"
uzumaki.possession->name;
// "konoha headband"
```

## 4. Give Power to the People

The most exiting feature of Troy are the special powers, that people might wield.
Some can smelt iron with their thoughts, while others can heal every wound instantly at nighttime.

Define the function `manifest_power` which returns nothing but takes a `human` and a `string`.
With the `string` it should define a new `power` object and set the `own_power` pointer of the `human` accordingly.
The function should not return anything.

```cpp
human eleven {};
manifest_power(eleven, "psychokinesis");

eleven.own_power->effect;
// "psychokinesis"
```

## 5. Use the Power

What use are the greatest powers, if you cannot use them.
Your model concentrates on humans, so you want to track the influence of powers.

Write a _void_ function `use_power` that takes two humans, first: a caster and secondly: a target.
The target's `influenced_by` pointer should be pointed to the power of the caster.

For simplicity, humans can only be influenced by a single power and this power stays in place even if the caster does not exist any longer.

```cpp
human pamela_isley{};
manifest_power(pamela_isley, "control pheromones");

human count_vertigo{};
use_power(pamela_isley, count_vertigo);
count_vertigo.influenced_by->effect;
// "control pheromones"
```

## 6. Keep watch on the power's intensity

Certain powers lose their potency or trigger certain effects in your simulation when they are applied to several humans.
You want to track the number of people who are connected to each power.

Define the function `power_intensity`, that takes a human and returns the intensity of their power as an _int_.
If the person has no power, the return value should be `0`.
Otherwise the intensity should reflect the caster and all currently influenced people.

```cpp
human jean_grey{};
manifest_power(jean_grey, "uplifting personality");

human scott{};
human logan{};
human ororo{};

use_power(jean_grey, ororo);
use_power(jean_grey, logan);
use_power(jean_grey, scott);

power_intensity(jean_grey);
// 4
```
