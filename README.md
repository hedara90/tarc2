# Trait System (Full Release)

This is the full release of the Multi-Ability function I'm calling the Trait System!
Currently updated to Pokeemerald Expansion 1.12.1

The Trait System allows you to assign more than one ability to each pokemon for more complex and more interesting setups.

- General terminology I'm going for is:
   - Ability = Same as vanilla.
   - Innate = Additional abilities that are the same for all members of a species.
   - Trait = Encompassing term for either one
  Note: for the sake of making merging a little easier, "Ability" is still used in many places when "Trait" is intended.
- Abilities work exactly the same as vanilla where a pokemon could have one of 3 ability options, however Innates are fixed to each species and don't change.
- To add Innates you just need to add a new .innates parameter underneath the existing .abilities one using the same formatting.  Example innate setups have been included commented out for all pokemon in the Gen 1 families.
   - ex: .innates = { ABILITY_PROTEAN, ABILITY_ROUGH_SKIN, ABILITY_CLEAR_BODY },
- Uses the MAX_MON_INNATES variable to control how many Innates are available, default is 3 totaling up to 4 active abilities per pokemon.  If you assign more innates than the max, surplus entries will simply be ignored.  This means you could even set MAX_MON_INATES to 0 and you would functionally just get the original vanilla system.
- There is a new Summary Page "Traits" to display the four slots along with some color changes across the vanilla pages for color balance.
- Most effects that target Abilities still only target a pokemon's primary Ability, ignoring their Innates.  Neutralizing Gas, Worry Seed, Trace, and Mummy for example all only affect Abilities but not Innates.  Mold Breaker type Traits however work on everything, including Innates.  (NOTE: Trace is also not designed to be an Innate since it replaces itself as part of its effect.  Trace in particular should ALWAYS be assigned as an Ability or else you'll get an infinite loop lock.)
- The basic code design is all Ability checks have been replaced with Trait checks, reading all passives a pokemon has whenever an Ability is looked for.  All previously mutually exclusive abilities like the weather ones which use a Switch Case format has been replaced with If statements so that they can all be called anyway (though natually any abilities that actually conflict will overwrite by code order, Drought and Snow Warning will both activate, but Snow Warning is later in the list so ultimately the weather will be snow/hail.  Really this is only a consideration for future randomizer settings.
- Ability popups have been modified into a Stack system so that when multiple abilities are triggered at once, they are stored then read out in the correct order.  Battle Message logic has also been updated to account for the new timings.
- Make Test system updated to account for Innates as well, original vanilla ability tests prefixed with "ABILITY:" while Innate versions prefixed with "INNATE:".  Tests that account for abilities but aren't in the ability group have still been given "INNATE:" versions, but their vanilla tests were left alone.
- A useful template for organizing pokemon and assigning Traits can be found here: https://docs.google.com/spreadsheets/d/1pNtGGapXx20svfM0PpztHYHJnbgvXHS8tc_i-h0a0Po/edit?gid=0#gid=0
Note that the Data sheet includes a collumn for automatically generating the .innate line to be added into Expansion's lists based on how you fill out the Pokemon's innate list.

- The AI system largely works the same just with Innates added on top and fixed.  This means the AI can still treat Abilities as unknown until they learn what the Ability is directly, but Innates will always be treated as known.

Basic code bedrock design comes from old Emerald Redux code with permission.

Huge thanks to the RH Hideout discord community for their help, advice, and testing, especially Alex, Surskitty, Kleem, Meister_anon, and MGriffin who helped make this possible.


# About `pokeemerald-expansion`

![Gif that shows debugging functionality that is unique to pokeemerald-expansion such as rerolling Trainer Id, Cheat Start, PC from Debug Menu, Debug PC Fill, Pokemon Sprite Visualizer, Debug Warp to Map, and Battle Debug Menu](https://github.com/user-attachments/assets/cf9dfbee-4c6b-4bca-8e0a-07f116ef891c) ![Gif that shows overworld functionality that is unique to pokeemerald-expansion such as indoor running, BW2 style map popups, overworld followers, DNA Splicers, Gen 1 style fishing, OW Item descriptions, Quick Run from Battle, Use Last Ball, Wild Double Battles, and Catch from EXP](https://github.com/user-attachments/assets/383af243-0904-4d41-bced-721492fbc48e) ![Gif that shows off a number of modern Pokemon battle mechanics happening in the pokeemerald-expansion engine: 2 vs 1 battles, modern Pokemon, items, moves, abilities, fully customizable opponents and partners, Trainer Slides, and generational gimmicks](https://github.com/user-attachments/assets/50c576bc-415e-4d66-a38f-ad712f3316be)

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->

**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.** 

# [Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those featues can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.

```
Based off RHH's pokeemerald-expansion 1.12.1 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches. 

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide on forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [Rom Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!
