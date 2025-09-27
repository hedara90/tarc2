const struct BookPage sAllPages[PAGE_COUNT] =
{
    [PAGE_TEST] =
    {
        .pageTitle = COMPOUND_STRING("TEST TITLE"),
        .leftPage = COMPOUND_STRING("This is some text that should be printed on the left side of the page.\nIt's quite a lot of text so that it can fill a lot of the page. Though it can have 1 more line."),
        .rightPage = COMPOUND_STRING("This is some text that should be printed to the right side of the page. It's quite a lot of text so that it can fill a lot of the page. It'll also have to be passed through the auto-linebreaker because I can't be arsed to put manual breaks into it. And I hope that there's been enough text on the page now to not look stupid."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_NONE,
    },
    [PAGE_TEST2] =
    {   
        .pageTitle = COMPOUND_STRING(""),
        .leftPage = COMPOUND_STRING(""),
        .rightPage = COMPOUND_STRING(""),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_NONE,
    },
    [PAGE_XERNEAS_UNFINISHED_1] =
    {
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("Once upon a time, humanity knew not of death. Happiness lasted eternally, as they sung and danced around the tree. An eternal paradise. But eternity came to an end."),
        .rightPage = COMPOUND_STRING("The first death caused great uproar and chaos. Not long after, many more succumbed. It did not take long for the chaos to spread everywhere and reduce the once prosperous civilization to ashes and rubble. Now, their cities lay in ruin, the roads forgotten and the fields returned to nature."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_XERNEAS_UNFINISHED_2,
    },
    [PAGE_XERNEAS_UNFINISHED_2] =
    {
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("Palaces crumbling away, vessels sunken to the depths, houses overgrown. But like the vines sprawling over the facades, humanity endured. Through famine, war, peace and abundance."),
        .rightPage = COMPOUND_STRING(" The ruins now stand as a reminder that we can and will endure even in the face of death."),
        .goLeft = PAGE_XERNEAS_UNFINISHED_1,
        .goRight = PAGE_NONE,
    },
    [PAGE_XERNEAS_FALSE_1] =
    {
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("'It's done.'\nFenrir reached for the blade pierced through the deer's heart. After a grueling battle, they were finally succesful. The battle had lasted multiple days, and he could still feel every wound suffered. The ground was soaked in his blood, many times more than could fit in a human's body."),
        .rightPage = COMPOUND_STRING("'It's finally done.'\n\nThe words echoed in Fenrir's head as he heard Morgan scream. He turned around to see her arm impaled by new growths on the monster's head.\n\nAnd then it stood up."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_NONE,
    },
    [PAGE_XERNEAS_TRUE_1] =
    {   
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("What happens when a sapling sprouts, but never stops growing? Will it protect those underneath its shade? Or will it suffocate them?"),
        .rightPage = COMPOUND_STRING("Xerneas, the bearer of Life. Once worshipped for it's ability to grant people a long life. But in the end, it was just a simple Pokemon itself. One whose very presence would bestow immortality on those around it. "),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_XERNEAS_TRUE_2,
    },
    [PAGE_XERNEAS_TRUE_2] =
    {   
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("Yet neither it nor its recipients were aware of the consequences of this curse. People were unable to die, yet still felt pain all the same. Some lost their sanity. Others their empathy."),
        .rightPage = COMPOUND_STRING(" After all, centuries of time will wear down even the strongest wills.\n\nBut one day, it all came to an end. A blade forged in the depths of Nifl pierced Xerneas's heart and brought an end to the eternal paradise. "),
        .goLeft = PAGE_XERNEAS_TRUE_1,
        .goRight = PAGE_XERNEAS_TRUE_3,
    },
    [PAGE_XERNEAS_TRUE_3] =
    {   
        .pageTitle = COMPOUND_STRING("Overflowing Abundance"),
        .leftPage = COMPOUND_STRING("The unending plant growth ceased. Pokemon and humanity alike became mortal. Death became known once more."),
        .rightPage = COMPOUND_STRING("The heroes who quelled the beast were lauded with the highest praise. Fenrir, Morgan and Siegfried are still greatly influencial names, and their legacy lives forever."),
        .goLeft = PAGE_XERNEAS_TRUE_2,
        .goRight = PAGE_NONE,
    },
    [PAGE_LUGIA_UNFINISHED] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("It's said that the eternal storm was caused by the hubris of a now lost civilization. They thought they could outsmart the guardian of the seas and have now paid the price for it."),
        .rightPage = COMPOUND_STRING("The nation was spread across many islands and long enjoyed the protection of the winds and blessing of the currents. People lived a peaceful life, for the most part. Occasional conflict was not unknown, but usually resolved. Perhaps this lack of conflict was the reason which ultimately doomed the archipelago."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_NONE,
    },
    [PAGE_LUGIA_FALSE_1] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("The islanders were under assault. They were woefully unprepared for the monstrosities that washed ashore, spat out from the sea. Cries of panic were washed out by the heavy downpour and bellowing thunder."),
        .rightPage = COMPOUND_STRING("In a state of desperation, the people used the Beacon of the Sea to call forth a storm to wash the enemies and their ships back out to sea. When Lugia caught wind of this, he was outraged. They were not meant to use the relic, as this was a test of willpower and strength. "),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_LUGIA_FALSE_2,
    },
    [PAGE_LUGIA_FALSE_2] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("Lugia offered one more test. A single person was to overcome the trials he set in place. The nameless hero stepped forth and offered to set out to complete them."),
        .rightPage = COMPOUND_STRING("Eventually, he returned. Despite his best efforts, he never managed to overcome the final obstacle. With a heavy heart, he shared the verdict: 20 people were to leave the island, with him as the leader. The rest was to stay behind, and be sunk to the bottom of the ocean together with the archipelago."),
        .goLeft = PAGE_LUGIA_FALSE_1,
        .goRight = PAGE_LUGIA_FALSE_3,
    },
    [PAGE_LUGIA_FALSE_3] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("It did not take long for people to fall in to discord, viying over who gets to leave. When the dust settled, less than 20 people remained at all."),
        .rightPage = COMPOUND_STRING("Hyoku departed with those who remained. The remains of the nation he once knew, now in a small boat seeking refuge on land. As he was granted passage through the storms, he looked back at the islands sinking beneath the waves"),
        .goLeft = PAGE_LUGIA_FALSE_2,
        .goRight = PAGE_NONE,
    },
    [PAGE_LUGIA_TRUE_1] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("There was once an archipelago where Lugia resided. For centuries, they simply let the ocean shape the islands. Pokemon lived their normal life, and weather went its normal course."),
        .rightPage = COMPOUND_STRING("One day, the humans arrived. At first, Lugia ignored them. They were just more beings inhabiting the archipelago. But over time, Lugia grew curious about these new inhabitants. Their way of living was vastly different from normal Pokemon."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_LUGIA_TRUE_2,
    },
    [PAGE_LUGIA_TRUE_2] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("The first person to meet Lugia was just a child, named Ryoku. Yet this meeting would have a monumental impact on the people's future. After witnessing the hardships and endurance of the people, Lugia made sure that the people on the islands could live in peace for years to come."),
        .rightPage = COMPOUND_STRING("Decades later, the islanders had grown complacent. Lugia looked at what had become of the once steadfast people, and saw nothing of the qualities they once admired. They came up with a plan to test their resolve. But when it truly mattered, only a single man was brave enough to face his fears."),
        .goLeft = PAGE_LUGIA_TRUE_1,
        .goRight = PAGE_LUGIA_TRUE_3,
    },
    [PAGE_LUGIA_TRUE_3] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("Lugia had seen enough. They told the islanders to leave this place and never return. The people begged for another chance, but Lugia would not hear it. Until the man stood up. He proclaimed to be the king that would lead the people back on the right path."),
        .rightPage = COMPOUND_STRING("Amused, Lugia set forth a number of trials for the man to overcome. If he passed them, the people would be allowed to remain on the islands. Lugia watched as the man took on the trials. Though he struggled mightily, his determination never wavered. "),
        .goLeft = PAGE_LUGIA_TRUE_2,
        .goRight = PAGE_LUGIA_TRUE_4,
    },
    [PAGE_LUGIA_TRUE_4] =
    {   
        .pageTitle = COMPOUND_STRING("The Lost Archipelago"),
        .leftPage = COMPOUND_STRING("After 5 weeks, he returned to his people, the Beacon of the Sea in hand as a symbol of Lugia's accordance. The people celebrated and crowned him king. To this day, Ryoku's statue still stands tall on the Whirl Isles."),
        .rightPage = COMPOUND_STRING("Lugia was never seen after that day."),
        .goLeft = PAGE_LUGIA_TRUE_3,
        .goRight = PAGE_NONE,
    },
    
    [PAGE_GIRATINA_UNFINISHED_1] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("Giratina. The Devil, the Monster From the Other Side, the Original Sinner. Little is known about them, and there exist many different tales about them. But throughout all of them, a single thread unites them: Giratina was banished to the Distortion World, from where it now conspires its revenge."),
        .rightPage = COMPOUND_STRING("Chaos seeps through the tears in reality, bridges between our world and the Other Side that unravel the very fabric of our reality. Where a rift appears, the surrounding area will start to show very strange phenomena. Gravity may cease working, plants turn a hellish red, and geometry stops working as expected. Sound speeding up, light slowing down."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_GIRATINA_UNFINISHED_2,
    },
    [PAGE_GIRATINA_UNFINISHED_2] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("It is undeniably fascinating, but also must be stopped at all costs. Areas tainted by the chaos become completely inhabitable. Some people claim that these rifts are divine punishment by Arceus himself for interfering with that which is not ours."),
        .rightPage = COMPOUND_STRING("There exist those that sympathise with Giratina. These people are considered heretics by most nations, and outcast from society. Rumors about them are common to find. From claims that they are building a new society in the Distortion World to whispers that they can create portals at will. These accusations appear to be baseless."),
        .goLeft = PAGE_GIRATINA_UNFINISHED_1,
        .goRight = PAGE_NONE,
    },
    [PAGE_GIRATINA_FALSE_1] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("It was only recently that Giratina was slain. A group of highly trained paladins ventured to a rift nearby, and brought their very best Pokemon. The Empress Luciana had gone missing, and the Palace had full reason to suspect she was taken to the Distortion World. On arrival, they located the portal end entered."),
        .rightPage = COMPOUND_STRING("When they emerged with the Empress, most of them had lost their minds.\n\nThe only reason we know this is due to the lone paladin who remained outside. He brought the Empress back to the capital. Strangely, she was sound of mind and completely unharmed."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_GIRATINA_FALSE_2,
    },
    [PAGE_GIRATINA_FALSE_2] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("What really happened remains a mystery. The Palace has remained silent in the days since, which has caused great unrest in the capital. On top of that, it appears that the reality warping effects near the rifts have become more intense and are spreading faster."),
        .rightPage = COMPOUND_STRING("After closer examination, we've found out that the Distortion World requires something to anchor it down, otherwise it will collapse in on itself and seep into our world. This seems to be an object. For now, we have named it the Griseous orb. It's wherabouts are currently unknown."),
        .goLeft = PAGE_GIRATINA_FALSE_1,
        .goRight = PAGE_NONE,
    },
    [PAGE_GIRATINA_TRUE_1] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("Harmony is the core concept with which this world is founded on. Light and Dark, Life and Death, Order and Chaos. One cannot exist without the other. But if everything has its counterpart, does our world have one?"),
        .rightPage = COMPOUND_STRING("When the universe was created, Arceus made a mirror dimension to keep everything in balance. However, this mirror dimension was full with chaotic energy, a mirror to our more ordered world."),
        .goLeft = PAGE_NONE,
        .goRight = PAGE_GIRATINA_TRUE_2,
    },
    [PAGE_GIRATINA_TRUE_2] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("It soon became apparant that this world was too unstable, with nothing inside it to control it. It started affecting our world, chaos tearing up the landscape. One Pokemon offered itself to stay in the mirror world and prevent it from negatively affecting us."),
        .rightPage = COMPOUND_STRING("And thus, Giratina settled in the Distortion World, a lone being in a sea of chaos. Where our side teemed with life, the other side had just a single entity in there. Destined to be forgotten. Centuries went by in the blink of an eye, yet stretching out for eternity."),
        .goLeft = PAGE_GIRATINA_TRUE_1,
        .goRight = PAGE_GIRATINA_TRUE_3,
    },
    [PAGE_GIRATINA_TRUE_3] =
    {   
        .pageTitle = COMPOUND_STRING("The Original Sinner"),
        .leftPage = COMPOUND_STRING("At some point, Giratina's grip on the chaos weakened, and slowly but surely, rifts started appearing in our world. By now, Giratina was long forgotten, all that remains were folklore and fairy tales.\n\nUntil recently."),
        .rightPage = COMPOUND_STRING("Through Empress Luciana, we finally realized the truth about the Distortion World. She fell into the Distortion World one day and met Giratina. It turned out that Giratina had slowly been working on special prisms that contain its energy. This way, they could ensure that even in their absence, the chaos would be anchored down."),
        .goLeft = PAGE_GIRATINA_TRUE_2,
        .goRight = PAGE_NONE,
    },
};
