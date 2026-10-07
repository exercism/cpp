# Additional Instructions

## Grapheme Clusters

Unicode supports a lot of characters and languages.
The displayed 'graphemes' are constructed from code points.
Their combination and _order_ is the basis of the resulting grapheme.
Imagine, a simple algorithm that might flip the 'dots' from one place to another during reversal: `Noël` becomes `leöN`.
Now consider more [complex constructions][grapheme-construction] like the Bengali word `ঝিল্লি`, which consists of six code points.

As graphemes make the string reversal process a lot more complicated, we made the respective test cases optional.
You can try them out by setting the `TEST_GRAPHEMES` compiler flag or editing the test file accordingly.

[grapheme-construction]: https://r12a.github.io/uniview/?charlist=%E0%A6%9D%E0%A6%BF%E0%A6%B2%E0%A7%8D%E0%A6%B2%E0%A6%BF
