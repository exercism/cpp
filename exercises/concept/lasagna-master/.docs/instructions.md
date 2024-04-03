# Instructions

In this exercise you are going to write some more code related to preparing and cooking your brilliant lasagna from your favorite cookbook.

You have five tasks.
The first one is related to the cooking itself, the other four are about the perfect preparation.

## 1. Estimate the preparation time

For the next lasagna that you will prepare, you want to make sure you have enough time reserved so you can enjoy the cooking.
You already planned which layers your lasagna will have.
Now you want to estimate how long the preparation will take based on that.

Implement a function `preparationTime` that accepts a vector of layers as `string` and the average preparation time per layer in minutes as an `int`.
The function should return the estimate for the total preparation time based on the number of layers as an `int`.
If the average preparation time is not passed then the default value of `2` should be used.

```cpp
std::vector<std::string> layers{"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"};
preparationTime(layers, 3)
// => 18
preparationTime(layers)
// => 12
```

## 2. Compute the amounts of noodles and sauce needed

Besides reserving the time, you also want to make sure you have enough sauce and noodles to cook the lasagna of your dreams.
For each noodle layer in your lasagna, you will need 50 grams of noodles.
For each sauce layer in your lasagna, you will need 0.2 liters of sauce.

Define the function `quantities` that takes a vector of layers as parameter as `string`.
The function will then determine the quantity of noodles and sauce needed to make your meal.
The result should be returned as an `amount` _struct_, which is already  defined for you.
`amount` has two member variables one for the weight of the `noodles` as an `int` and the second one as the volume of the `sauce` as a `double`.

```cpp
struct amount { int noodles; double sauce; };

amount needed{quantities({"sauce", "noodles", "sauce", "meat", "mozzarella", "noodles"})};
// needed.noodles => 100
// needed.sauce => 0.4
```

## 3. Add the secret ingredient

A while ago you visited a friend and ate lasagna there.
It was amazing and had something special to it.
The friend sent you the list of ingredients and told you the last item on the list is the "secret ingredient" that made the meal so special.
Now you want to add that secret ingredient to your recipe as well.

Write a function `addSecretIngredient` that accepts two `string` vectors of ingredients as parameters.
The first parameter is the ingredient list of your own recipe, the second is the list your friend sent you.
The last element in your ingredient list is always `"?"`.
The function should replace it with the last item from your friends list.
**Note:** `addSecretIngredient` does not return anything - you should modify the list of your ingredients directly.
The list with your friend's ingredients should **not** be modified.
Make sure the list will not be modified with a `const` reference.

```cpp
std::vector<std::string> friendsList{"noodles", "sauce", "mozzarella", "kampot pepper"};
std::vector<std::string> myList{"noodles", "meat", "sauce", "mozzarella", "?"};

addSecretIngredient(myList, friendsList);
// myList => {"noodles", "meat", "sauce", "mozzarella", "kampot pepper"}
```

## 4. Scale the recipe

The amounts listed in your cookbook only yield enough lasagna for two portions.
Since you want to cook for more people next time, you want to calculate the amounts for different numbers of portions.

Implement a function `scaleRecipe` that takes two parameters.

- A vector of `double` amounts needed for 2 portions.
- The number of portions you want to cook.

The function should return a new vector of the amounts needed for the desired number of portions.
You want to keep the original recipe though.
This means the `quantities` argument should not be modified in this function.

```cpp
std::vector<double> quantities{1.2, 3.6, 10.5};
scaleRecipe(quantities, 4);
// => { 2.4, 7.2, 21 }
```

## 5. Unlock the Family Secret

You remember stories from your childhood, tales of your great-grand auntie, the guardian of the family's deepest culinary secrets.
Legend has it that she holds the key to unlocking flavors beyond imagination, but her methods are unconventional.
She doesn't deal in lists or measurements; she speaks in whispers, revealing only one ingredient at a time.

With a mixture of excitement and trepidation, you decide to reach out to your great-grand auntie.
As expected, she responds in her cryptic manner, offering a single secret ingredient, wrapped in mystery.

Your great-grand auntie's contribution adds a layer of complexity, that you want to use in your recipe.
Implement another version of the `addSecretIngredient` function that accepts two arguments: a reference to a vector representing your list of ingredients and a single string representing the enigmatic offering from your great-grand auntie.

```cpp
std::vector<std::string> myList{"noodles", "meat", "sauce", "mozzarella", "?"};
std::string secretIngredient{"spice melange"};
addSecretIngredient(myList, secretIngredient);
// myList => {"noodles", "meat", "sauce", "mozzarella", "spice melange"}
```

Good luck, brave chef!
