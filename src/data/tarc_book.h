const struct BookPage sAllPages[PAGE_COUNT] =
{
    [PAGE_TEST] =
    {
        .pageTitle = COMPOUND_STRING("TEST TITLE"),
        .leftPage = COMPOUND_STRING("This is some text that should be printed on the left side of the page. It's quite a lot of text so that it can fill a lot of the page. Though it can have 1 more line."),
        .rightPage = COMPOUND_STRING("This is some text that should be printed to the right side of the page. It's quite a lot of text so that it can fill a lot of the page. It'll also have to be passed through the auto-linebreaker because I can't be arsed to put manual breaks into it. And I hope that there's been enough text on the page now to not look stupid."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_TEST2,
    },
    [PAGE_TEST2] =
    {
        .pageTitle = COMPOUND_STRING("Title the second"),
        .leftPage = COMPOUND_STRING("Just some stuff"),
        .rightPage = COMPOUND_STRING("More stuff"),
        .goLeft = PAGE_TEST,
        .goRight = PAGE_NONE,
    },
};
