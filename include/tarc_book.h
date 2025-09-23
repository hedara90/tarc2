#ifndef GUARD_TARC_BOOK_H
#define GUARD_TARC_BOOK_H

#include "global.h"
#include "data.h"
#include "main.h"
#include "script.h"
#include "constants/tarc_book.h"

struct BookPage
{
    const u8 *pageTitle;
    //const u32 *sprite;
    //const u16 *palette;
    //u8 spriteShape:2;
    //u8 spriteSize:2;
    //bool8 compressed;
    //enum BookSpriteType spriteType;
    //u32 species;
    const u8 *leftPage;
    const u8 *rightPage;
    enum BookPages goLeft;
    enum BookPages goRight;
};

void Tarc_InitBookScreen(MainCallback callback, enum BookPages page);
void Tarc_InitBookScreenFromScript(struct ScriptContext *ctx);

#endif
