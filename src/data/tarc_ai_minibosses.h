const struct BossMoveList sBlastoise1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AQUA_RING,
        MOVE_SHELL_SMASH,
        MOVE_HYDRO_PUMP,
        MOVE_ICE_BEAM
    },
};

const struct BossMoveList sBlastoise2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HYDRO_PUMP,
        MOVE_FLASH_CANNON,
        MOVE_ICE_BEAM,
        MOVE_ORIGIN_PULSE
    },
};

const struct BossAi sBlastoiseAi =
{
    .phaseMoves =
    {
        &sBlastoise1,
        &sBlastoise2,
        &sBlastoise2,
        &sBlastoise2,
    },
};

const struct BossMoveList sButterfree1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SLEEP_POWDER,
        MOVE_QUIVER_DANCE,
        MOVE_HURRICANE,
        MOVE_BUG_BUZZ,
    },
};

const struct BossAi sButterfreeAi =
{
    .phaseMoves =
    {
        &sButterfree1,
        &sButterfree1,
        &sButterfree1,
        &sButterfree1,
    },
};

const struct BossMoveList sPidgeot1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FEATHER_DANCE,
        MOVE_CALM_MIND,
        MOVE_ROOST,
        MOVE_HURRICANE,
        MOVE_HEAT_WAVE
    },
};

const struct BossAi sPidgeotAi =
{
    .phaseMoves =
    {
        &sPidgeot1,
        &sPidgeot1,
        &sPidgeot1,
        &sPidgeot1,
    },
};

const struct BossMoveList sArbok1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_COIL,
        MOVE_POISON_FANG,
        MOVE_POWER_TRIP,
        MOVE_REST
    },
};

const struct BossAi sArbokAi =
{
    .phaseMoves =
    {
        &sArbok1,
        &sArbok1,
        &sArbok1,
        &sArbok1,
    },
};

const struct BossMoveList sPikachu1 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_VOLT_TACKLE,
        MOVE_DOUBLE_EDGE,
    },
};

const struct BossAi sPikachuAi =
{
    .phaseMoves =
    {
        &sPikachu1,
        &sPikachu1,
        &sPikachu1,
        &sPikachu1,
    },
};

const struct BossMoveList sNidoking1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_EARTH_POWER,
        MOVE_SLUDGE_WAVE,
        MOVE_ICE_BEAM,
        MOVE_THUNDERBOLT,
        MOVE_FLAMETHROWER
    },
};

const struct BossAi sNidokingAi =
{
    .phaseMoves =
    {
        &sNidoking1,
        &sNidoking1,
        &sNidoking1,
        &sNidoking1,
    },
};

const struct BossMoveList sVileplume1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_TOXIC,
        MOVE_STRENGTH_SAP,
        MOVE_LEECH_SEED,
        MOVE_GIGA_DRAIN,
        MOVE_NIGHT_SHADE,
        MOVE_MOONLIGHT
    },
};

const struct BossAi sVileplumeAi =
{
    .phaseMoves =
    {
        &sVileplume1,
        &sVileplume1,
        &sVileplume1,
        &sVileplume1,
    },
};

const struct BossMoveList sParasect1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_X_SCISSOR,
        MOVE_DIG,
        MOVE_BRICK_BREAK
    },
};

const struct BossAi sParasectAi =
{
    .phaseMoves =
    {
        &sParasect1,
        &sParasect1,
        &sParasect1,
        &sParasect1,
    },
};

const struct BossMoveList sVenomoth1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_QUIVER_DANCE,
        MOVE_SLUDGE_BOMB,
        MOVE_FOCUS_BLAST,
        MOVE_PSYCHIC
    },
};

const struct BossAi sVenomothAi =
{
    .phaseMoves =
    {
        &sVenomoth1,
        &sVenomoth1,
        &sVenomoth1,
        &sVenomoth1,
    },
};

const struct BossMoveList sDugtrio1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_EARTHQUAKE,
        MOVE_STONE_EDGE,
        MOVE_ENDURE,
        MOVE_REVERSAL
    },
};

const struct BossAi sDugtrioAi =
{
    .phaseMoves =
    {
        &sDugtrio1,
        &sDugtrio1,
        &sDugtrio1,
        &sDugtrio1,
    },
};

const struct BossMoveList sArcanine1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FLARE_BLITZ,
        MOVE_CRUNCH,
        MOVE_MOONLIGHT,
        MOVE_THUNDER_FANG,
        MOVE_PLAY_ROUGH
    },
};

const struct BossAi sArcanineAi =
{
    .phaseMoves =
    {
        &sArcanine1,
        &sArcanine1,
        &sArcanine1,
        &sArcanine1,
    },
};

const struct BossMoveList sAlakazam1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PSYCHIC,
        MOVE_FUTURE_SIGHT,
        MOVE_DAZZLING_GLEAM,
        MOVE_FOCUS_BLAST
    },
};

const struct BossAi sAlakazamAi =
{
    .phaseMoves =
    {
        &sAlakazam1,
        &sAlakazam1,
        &sAlakazam1,
        &sAlakazam1,
    },
};

const struct BossMoveList sRapidash1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AGILITY,
        MOVE_PYROCLASM,
        MOVE_SWORDS_DANCE,
        MOVE_HIGH_HORSEPOWER
    },
};

const struct BossAi sRapidashAi =
{
    .phaseMoves =
    {
        &sRapidash1,
        &sRapidash1,
        &sRapidash1,
        &sRapidash1,
    },
};

const struct BossMoveList sSlowbro1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_YAWN,
        MOVE_IRON_DEFENSE,
        MOVE_BODY_PRESS,
        MOVE_SCALD,
        MOVE_SLACK_OFF
    },
};

const struct BossAi sSlowbroAi =
{
    .phaseMoves =
    {
        &sSlowbro1,
        &sSlowbro1,
        &sSlowbro1,
        &sSlowbro1,
    },
};

const struct BossMoveList sDewgong1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_AQUA_RING,
        MOVE_ICE_BEAM,
        MOVE_DIVE,
        MOVE_ICY_WIND,
        MOVE_SCALD,
        MOVE_SNOWSCAPE
    },
};

const struct BossAi sDewgongAi =
{
    .phaseMoves =
    {
        &sDewgong1,
        &sDewgong1,
        &sDewgong1,
        &sDewgong1,
    },
};

const struct BossMoveList sCloyster1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SHELL_SMASH,
        MOVE_ICICLE_SPEAR,
        MOVE_ROCK_BLAST,
        MOVE_RAZOR_SHELL
    },
};

const struct BossAi sCloysterAi =
{
    .phaseMoves =
    {
        &sCloyster1,
        &sCloyster1,
        &sCloyster1,
        &sCloyster1,
    },
};

const struct BossMoveList sGengar1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SHADOW_BALL,
        MOVE_NASTY_PLOT,
        MOVE_SLUDGE_BOMB,
        MOVE_FOCUS_BLAST
    },
};

const struct BossAi sGengarAi =
{
    .phaseMoves =
    {
        &sGengar1,
        &sGengar1,
        &sGengar1,
        &sGengar1,
    },
};

const struct BossMoveList sExeggutor1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_ENERGY_BALL,
        MOVE_CALM_MIND,
        MOVE_STORED_POWER,
        MOVE_GIGA_DRAIN
    },
};

const struct BossAi sExeggutorAi =
{
    .phaseMoves =
    {
        &sExeggutor1,
        &sExeggutor1,
        &sExeggutor1,
        &sExeggutor1,
    },
};

const struct BossMoveList sMarowak1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_BONEMERANG,
        MOVE_ROCK_TOMB,
        MOVE_DOUBLE_EDGE,
        MOVE_BRUTAL_SWING,
    },
};

const struct BossAi sMarowakAi =
{
    .phaseMoves =
    {
        &sMarowak1,
        &sMarowak1,
        &sMarowak1,
        &sMarowak1,
    },
};

const struct BossMoveList sHitmonlee1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_AGILITY,
        MOVE_ENDURE,
        MOVE_REVERSAL
    },
};

const struct BossMoveList sHitmonlee2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_HIGH_JUMP_KICK,
        MOVE_ENDURE,
        MOVE_REVERSAL,
        MOVE_THROAT_CHOP,
        MOVE_POISON_JAB
    },
};

const struct BossAi sHitmonleeAi =
{
    .phaseMoves =
    {
        &sHitmonlee1,
        &sHitmonlee2,
        &sHitmonlee2,
        &sHitmonlee2,
    },
};

const struct BossMoveList sWeezing1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TOXIC,
        MOVE_VENOSHOCK,
        MOVE_HAZE,
        MOVE_FLAMETHROWER
    },
};

const struct BossAi sWeezingAi =
{
    .phaseMoves =
    {
        &sWeezing1,
        &sWeezing1,
        &sWeezing1,
        &sWeezing1,
    },
};

const struct BossMoveList sStarmie1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CALM_MIND,
        MOVE_SURF,
        MOVE_PSYSHOCK,
        MOVE_RECOVER,
        MOVE_POWER_GEM
    },
};

const struct BossAi sStarmieAi =
{
    .phaseMoves =
    {
        &sStarmie1,
        &sStarmie1,
        &sStarmie1,
        &sStarmie1,
    },
};

const struct BossMoveList sMrMime1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_REFLECT,
        MOVE_NASTY_PLOT,
        MOVE_PSYCHIC,
        MOVE_SHADOW_BALL,
        MOVE_DAZZLING_GLEAM,
        MOVE_THUNDERBOLT
    },
};

const struct BossAi sMrMimeAi =
{
    .phaseMoves =
    {
        &sMrMime1,
        &sMrMime1,
        &sMrMime1,
        &sMrMime1,
    },
};

const struct BossMoveList sScyther1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_AERIAL_ACE,
        MOVE_X_SCISSOR,
        MOVE_TRAILBLAZE,
        MOVE_ROCK_SMASH
    },
};

const struct BossAi sScytherAi =
{
    .phaseMoves =
    {
        &sScyther1,
        &sScyther1,
        &sScyther1,
        &sScyther1,
    },
};

const struct BossMoveList sLapras1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FREEZE_DRY,
        MOVE_ALLURING_VOICE,
        MOVE_LIFE_DEW,
        MOVE_ANCIENT_POWER
    },
};

const struct BossAi sLaprasAi =
{
    .phaseMoves =
    {
        &sLapras1,
        &sLapras1,
        &sLapras1,
        &sLapras1,
    },
};

const struct BossMoveList sVaporeon1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BOUNCY_BUBBLE,
        MOVE_ICE_BEAM,
        MOVE_ACID_ARMOR,
        MOVE_CALM_MIND
    },
};

const struct BossAi sVaporeonAi =
{
    .phaseMoves =
    {
        &sVaporeon1,
        &sVaporeon1,
        &sVaporeon1,
        &sVaporeon1,
    },
};

const struct BossMoveList sJolteon1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_ELECTROWEB,
        MOVE_ELECTRO_BALL,
        MOVE_ALLURING_VOICE,
        MOVE_SHADOW_BALL,
    },
};

const struct BossAi sJolteonAi =
{
    .phaseMoves =
    {
        &sJolteon1,
        &sJolteon1,
        &sJolteon1,
        &sJolteon1,
    },
};

const struct BossMoveList sAerodactyl1 =
{
    .numMoves = 4,
    .moves =
    {

        MOVE_STONE_EDGE,
        MOVE_BRAVE_BIRD,
        MOVE_HEAD_SMASH,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sAerodactylAi =
{
    .phaseMoves =
    {
        &sAerodactyl1,
        &sAerodactyl1,
        &sAerodactyl1,
        &sAerodactyl1,
    },
};

const struct BossMoveList sSnorlax1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CURSE,
        MOVE_BODY_SLAM,
        MOVE_CRUNCH,
        MOVE_SLACK_OFF,

    },
};

const struct BossAi sSnorlaxAi =
{
    .phaseMoves =
    {
        &sSnorlax1,
        &sSnorlax1,
        &sSnorlax1,
        &sSnorlax1,
    },
};

const struct BossMoveList sMeganium1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CURSE,
        MOVE_SEED_BOMB,
        MOVE_BODY_PRESS,
        MOVE_SYNTHESIS
    },
};

const struct BossAi sMeganiumAi =
{
    .phaseMoves =
    {
        &sMeganium1,
        &sMeganium1,
        &sMeganium1,
        &sMeganium1,
    },
};

const struct BossMoveList sFeraligatr1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_WATERFALL,
        MOVE_DRAGON_DANCE,
        MOVE_ICE_FANG,
        MOVE_CRUNCH
    },
};

const struct BossAi sFeraligatrAi =
{
    .phaseMoves =
    {
        &sFeraligatr1,
        &sFeraligatr1,
        &sFeraligatr1,
        &sFeraligatr1,
    },
};

const struct BossMoveList sCrobat1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LEECH_LIFE,
        MOVE_CROSS_POISON,
        MOVE_DUAL_WINGBEAT,
        MOVE_TOXIC
    },
};

const struct BossAi sCrobatAi =
{
    .phaseMoves =
    {
        &sCrobat1,
        &sCrobat1,
        &sCrobat1,
        &sCrobat1,
    },
};

const struct BossMoveList sLanturn1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_THUNDER_WAVE,
        MOVE_PARABOLIC_CHARGE,
        MOVE_STOCKPILE,
        MOVE_SURF
    },
};

const struct BossMoveList sLanturn2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PARABOLIC_CHARGE,
        MOVE_TAIL_GLOW,
        MOVE_SURF,
        MOVE_ICE_BEAM
    },
};

const struct BossAi sLanturnAi =
{
    .phaseMoves =
    {
        &sLanturn1,
        &sLanturn2,
        &sLanturn2,
        &sLanturn2,
    },
};

const struct BossMoveList sXatu1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_FUTURE_SIGHT,
        MOVE_ROOST,
        MOVE_FOCUS_BLAST
    },
};

const struct BossAi sXatuAi =
{
    .phaseMoves =
    {
        &sXatu1,
        &sXatu1,
        &sXatu1,
        &sXatu1,
    },
};

const struct BossMoveList sAmpharos1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CHARGE_BEAM,
        MOVE_COTTON_GUARD,
        MOVE_PARABOLIC_CHARGE,
        MOVE_LIGHT_SCREEN,
        MOVE_DAZZLING_GLEAM
    },
};

const struct BossAi sAmpharosAi =
{
    .phaseMoves =
    {
        &sAmpharos1,
        &sAmpharos1,
        &sAmpharos1,
        &sAmpharos1,
    },
};

const struct BossMoveList sAzumarill1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BELLY_DRUM,
        MOVE_PLAY_ROUGH,
        MOVE_AQUA_JET,
        MOVE_SUPERPOWER
    },
};

const struct BossAi sAzumarillAi =
{
    .phaseMoves =
    {
        &sAzumarill1,
        &sAzumarill1,
        &sAzumarill1,
        &sAzumarill1,
    },
};

const struct BossMoveList sEspeon1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PSYCHIC_NOISE,
        MOVE_NASTY_PLOT,
        MOVE_MOONBLAST,
        MOVE_PSYSHOCK
    },
};

const struct BossAi sEspeonAi =
{
    .phaseMoves =
    {
        &sEspeon1,
        &sEspeon1,
        &sEspeon1,
        &sEspeon1,
    },
};

const struct BossMoveList sScizor1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_BULLET_PUNCH,
        MOVE_DUAL_WINGBEAT,
        MOVE_ROOST,
        MOVE_ROCK_SMASH
    },
};

const struct BossAi sScizorAi =
{
    .phaseMoves =
    {
        &sScizor1,
        &sScizor1,
        &sScizor1,
        &sScizor1,
    },
};

const struct BossMoveList sHeracross1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MEGAHORN,
        MOVE_CLOSE_COMBAT,
        MOVE_STONE_EDGE,
        MOVE_NIGHT_SLASH
    },
};

const struct BossAi sHeracrossAi =
{
    .phaseMoves =
    {
        &sHeracross1,
        &sHeracross1,
        &sHeracross1,
        &sHeracross1,
    },
};

const struct BossMoveList sHoundoom1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_DARK_PULSE,
        MOVE_FLAMETHROWER,
        MOVE_NASTY_PLOT,
        MOVE_OVERHEAT
    },
};

const struct BossAi sHoundoomAi =
{
    .phaseMoves =
    {
        &sHoundoom1,
        &sHoundoom1,
        &sHoundoom1,
        &sHoundoom1,
    },
};

const struct BossMoveList sDonphan1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SMACK_DOWN,
        MOVE_EARTHQUAKE,
        MOVE_BULK_UP,
        MOVE_HEADLONG_RUSH
    },
};

const struct BossAi sDonphanAi =
{
    .phaseMoves =
    {
        &sDonphan1,
        &sDonphan1,
        &sDonphan1,
        &sDonphan1,
    },
};

const struct BossMoveList sSceptile1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_GROWTH,
        MOVE_LEAF_BLADE,
        MOVE_ACROBATICS,
        MOVE_DRAGON_PULSE
    },
};

const struct BossAi sSceptileAi =
{
    .phaseMoves =
    {
        &sSceptile1,
        &sSceptile1,
        &sSceptile1,
        &sSceptile1,
    },
};

const struct BossMoveList sLinoone1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_BELLY_DRUM,
        MOVE_EXTREMESPEED,
        MOVE_EXTREMESPEED,
        MOVE_EXTREMESPEED,
        MOVE_EXTREMESPEED,
        MOVE_EXTREMESPEED,
    },
};

const struct BossMoveList sLinoone2 =
{
    .numMoves = 1,
    .moves =
    {
        MOVE_EXTREMESPEED,
    },
};

const struct BossAi sLinooneAi =
{
    .phaseMoves =
    {
        &sLinoone1,
        &sLinoone2,
        &sLinoone2,
        &sLinoone2,
    },
};

const struct BossMoveList sGardevoir1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MOONBLAST,
        MOVE_PSYCHIC,
        MOVE_CALM_MIND,
        MOVE_MYSTICAL_FIRE
    },
};

const struct BossAi sGardevoirAi =
{
    .phaseMoves =
    {
        &sGardevoir1,
        &sGardevoir1,
        &sGardevoir1,
        &sGardevoir1,
    },
};

const struct BossMoveList sNinjask1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_SWORDS_DANCE,
        MOVE_X_SCISSOR,
        MOVE_POWER_TRIP,
        MOVE_NIGHT_SLASH
    },
};

const struct BossAi sNinjaskAi =
{
    .phaseMoves =
    {
        &sNinjask1,
        &sNinjask1,
        &sNinjask1,
        &sNinjask1,
    },
};

const struct BossMoveList sExploud1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BOOMBURST,
        MOVE_SHADOW_BALL,
        MOVE_FOCUS_BLAST,
        MOVE_TAUNT
    },
};

const struct BossAi sExploudAi =
{
    .phaseMoves =
    {
        &sExploud1,
        &sExploud1,
        &sExploud1,
        &sExploud1,
    },
};

const struct BossMoveList sHariyama1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ARM_THRUST,
        MOVE_DRAIN_PUNCH,
        MOVE_THUNDERPUNCH,
        MOVE_ICE_PUNCH,
        MOVE_DRAIN_PUNCH,
    },
};

const struct BossAi sHariyamaAi =
{
    .phaseMoves =
    {
        &sHariyama1,
        &sHariyama1,
        &sHariyama1,
        &sHariyama1,
    },
};

const struct BossMoveList sMawile1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_FOCUS_PUNCH,
        MOVE_IRON_HEAD,
        MOVE_SWORDS_DANCE
    },
};

const struct BossAi sMawileAi =
{
    .phaseMoves =
    {
        &sMawile1,
        &sMawile1,
        &sMawile1,
        &sMawile1,
    },
};

const struct BossMoveList sAggron1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HEAD_SMASH,
        MOVE_IRON_HEAD,
        MOVE_BODY_PRESS,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sAggronAi =
{
    .phaseMoves =
    {
        &sAggron1,
        &sAggron1,
        &sAggron1,
        &sAggron1,
    },
};

const struct BossMoveList sVolbeat1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TAIL_GLOW,
        MOVE_BUG_BUZZ,
        MOVE_OVERDRIVE,
        MOVE_ENCORE
    },
};

const struct BossAi sVolbeatAi =
{
    .phaseMoves =
    {
        &sVolbeat1,
        &sVolbeat1,
        &sVolbeat1,
        &sVolbeat1,
    },
};

const struct BossMoveList sSharpedo1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CRUNCH,
        MOVE_WATERFALL,
        MOVE_ICE_FANG,
        MOVE_SWORDS_DANCE
    },
};

const struct BossAi sSharpedoAi =
{
    .phaseMoves =
    {
        &sSharpedo1,
        &sSharpedo1,
        &sSharpedo1,
        &sSharpedo1,
    },
};

const struct BossMoveList sFlygon1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SAND_TOMB,
        MOVE_DRAGON_DANCE,
        MOVE_EARTHQUAKE,
        MOVE_ROCK_SLIDE
    },
};

const struct BossAi sFlygonAi =
{
    .phaseMoves =
    {
        &sFlygon1,
        &sFlygon1,
        &sFlygon1,
        &sFlygon1,
    },
};

const struct BossMoveList sAltaria1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_DRAGON_DANCE,
        MOVE_DRAGON_CLAW,
        MOVE_EARTHQUAKE,
        MOVE_ROOST,
        MOVE_ACROBATICS
    },
};

const struct BossAi sAltariaAi =
{
    .phaseMoves =
    {
        &sAltaria1,
        &sAltaria1,
        &sAltaria1,
        &sAltaria1,
    },
};

const struct BossMoveList sCradily1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_LEECH_SEED,
        MOVE_GIGA_DRAIN,
        MOVE_ANCIENT_POWER,
        MOVE_STOCKPILE, 
        MOVE_EARTH_POWER,
    },
};

const struct BossAi sCradilyAi =
{
    .phaseMoves =
    {
        &sCradily1,
        &sCradily1,
        &sCradily1,
        &sCradily1,
    },
};

const struct BossMoveList sMilotic1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SCALD,
        MOVE_LIFE_DEW,
        MOVE_CALM_MIND,
        MOVE_DRAINING_KISS,
        MOVE_HYPER_VOICE
    },
};

const struct BossAi sMiloticAi =
{
    .phaseMoves =
    {
        &sMilotic1,
        &sMilotic1,
        &sMilotic1,
        &sMilotic1,
    },
};

const struct BossMoveList sCastform1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_WEATHER_BALL,
        MOVE_HURRICANE,
        MOVE_FIRE_BLAST,
        MOVE_BLIZZARD,
        MOVE_THUNDER,
    },
};

const struct BossAi sCastformAi =
{
    .phaseMoves =
    {
        &sCastform1,
        &sCastform1,
        &sCastform1,
        &sCastform1,
    },
};

const struct BossMoveList sBanette1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_PHANTOM_FORCE,
        MOVE_TAUNT,
        MOVE_SWORDS_DANCE,
        MOVE_DISABLE,
        MOVE_POISON_JAB,

    },
};

const struct BossAi sBanetteAi =
{
    .phaseMoves =
    {
        &sBanette1,
        &sBanette1,
        &sBanette1,
        &sBanette1,
    },
};

const struct BossMoveList sAbsol1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_SWORDS_DANCE,
        MOVE_NIGHT_SLASH,
        MOVE_PSYCHO_CUT,
        MOVE_IRON_TAIL
    },
};

const struct BossAi sAbsolAi =
{
    .phaseMoves =
    {
        &sAbsol1,
        &sAbsol1,
        &sAbsol1,
        &sAbsol1,
    },
};

const struct BossMoveList sLuvdisc1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SCALE_SHOT,
        MOVE_LIQUIDATION,
        MOVE_BULLET_SEED,
        MOVE_ZEN_HEADBUTT
    },
};

const struct BossAi sLuvdiscAi =
{
    .phaseMoves =
    {
        &sLuvdisc1,
        &sLuvdisc1,
        &sLuvdisc1,
        &sLuvdisc1,
    },
};

const struct BossMoveList sTorterra1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACKLE,
        MOVE_ICE_BEAM,
        MOVE_HAZE,
        MOVE_ROOST
    },
};

const struct BossAi sTorterraAi =
{
    .phaseMoves =
    {
        &sTorterra1,
        &sTorterra1,
        &sTorterra1,
        &sTorterra1,
    },
};

const struct BossMoveList sInfernape1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TACKLE,
        MOVE_ICE_BEAM,
        MOVE_HAZE,
        MOVE_ROOST
    },
};

const struct BossAi sInfernapeAi =
{
    .phaseMoves =
    {
        &sInfernape1,
        &sInfernape1,
        &sInfernape1,
        &sInfernape1,
    },
};

const struct BossMoveList sStaraptor1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BRAVE_BIRD,
        MOVE_CLOSE_COMBAT,
        MOVE_DOUBLE_EDGE,
        MOVE_ROOST
    },
};

const struct BossAi sStaraptorAi =
{
    .phaseMoves =
    {
        &sStaraptor1,
        &sStaraptor1,
        &sStaraptor1,
        &sStaraptor1,
    },
};

const struct BossMoveList sRoserade1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SUNNY_DAY,
        MOVE_LEAF_STORM,
        MOVE_NASTY_PLOT,
        MOVE_WEATHER_BALL,
        MOVE_SLUDGE_BOMB
    },
};

const struct BossAi sRoseradeAi =
{
    .phaseMoves =
    {
        &sRoserade1,
        &sRoserade1,
        &sRoserade1,
        &sRoserade1,
    },
};

const struct BossMoveList sRampardos1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HEAD_SMASH,
        MOVE_EARTHQUAKE,
        MOVE_ROCK_SLIDE,
        MOVE_CRUNCH
    },
};

const struct BossAi sRampardosAi =
{
    .phaseMoves =
    {
        &sRampardos1,
        &sRampardos1,
        &sRampardos1,
        &sRampardos1,
    },
};

const struct BossMoveList sFloatzel1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_WAVE_CRASH,
        MOVE_AQUA_JET,
        MOVE_BITE
    },
};

const struct BossAi sFloatzelAi =
{
    .phaseMoves =
    {
        &sFloatzel1,
        &sFloatzel1,
        &sFloatzel1,
        &sFloatzel1,
    },
};

const struct BossMoveList sCherrim1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUNNY_DAY,
        MOVE_SOLAR_BEAM,
        MOVE_WEATHER_BALL,
        MOVE_DAZZLING_GLEAM
    },
};

const struct BossAi sCherrimAi =
{
    .phaseMoves =
    {
        &sCherrim1,
        &sCherrim1,
        &sCherrim1,
        &sCherrim1,
    },
};

const struct BossMoveList sMismagius1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_WILL_O_WISP,
        MOVE_CHARGE_BEAM,
        MOVE_HEX,
        MOVE_DAZZLING_GLEAM
    },
};

const struct BossAi sMismagiusAi =
{
    .phaseMoves =
    {
        &sMismagius1,
        &sMismagius1,
        &sMismagius1,
        &sMismagius1,
    },
};

const struct BossMoveList sSkuntank1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SCREECH,
        MOVE_GUNK_SHOT,
        MOVE_TEMPER_FLARE,
        MOVE_NIGHT_SLASH,
        MOVE_SUCKER_PUNCH
    },
};

const struct BossAi sSkuntankAi =
{
    .phaseMoves =
    {
        &sSkuntank1,
        &sSkuntank1,
        &sSkuntank1,
        &sSkuntank1,
    },
};

const struct BossMoveList sLucario1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AURA_SPHERE,
        MOVE_IRON_HEAD,
        MOVE_PSYCHIC,
        MOVE_STONE_EDGE
    },
};

const struct BossAi sLucarioAi =
{
    .phaseMoves =
    {
        &sLucario1,
        &sLucario1,
        &sLucario1,
        &sLucario1,
    },
};

const struct BossMoveList sDrapion1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CROSS_POISON,
        MOVE_NIGHT_SLASH,
        MOVE_TOXIC,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sDrapionAi =
{
    .phaseMoves =
    {
        &sDrapion1,
        &sDrapion1,
        &sDrapion1,
        &sDrapion1,
    },
};

const struct BossMoveList sToxicroak1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FURY_SWIPES,
        MOVE_POISON_JAB,
        MOVE_FOCUS_BLAST,
        MOVE_VENOSHOCK
    },
};

const struct BossAi sToxicroakAi =
{
    .phaseMoves =
    {
        &sToxicroak1,
        &sToxicroak1,
        &sToxicroak1,
        &sToxicroak1,
    },
};

const struct BossMoveList sRhyperior1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_HEAD_SMASH,
        MOVE_DOUBLE_EDGE,
        MOVE_EARTHQUAKE,
        MOVE_BODY_PRESS
    },
};

const struct BossAi sRhyperiorAi =
{
    .phaseMoves =
    {
        &sRhyperior1,
        &sRhyperior1,
        &sRhyperior1,
        &sRhyperior1,
    },
};

const struct BossMoveList sElectivire1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_PLASMA_FISTS,
        MOVE_FIRE_PUNCH,
        MOVE_ICE_PUNCH,
        MOVE_ZAP_CANNON
    },
};

const struct BossAi sElectivireAi =
{
    .phaseMoves =
    {
        &sElectivire1,
        &sElectivire1,
        &sElectivire1,
        &sElectivire1,
    },
};

const struct BossMoveList sMagmortar1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FLAMETHROWER,
        MOVE_DARK_PULSE,
        MOVE_AURA_SPHERE,
        MOVE_THUNDERBOLT
    },
};

const struct BossAi sMagmortarAi =
{
    .phaseMoves =
    {
        &sMagmortar1,
        &sMagmortar1,
        &sMagmortar1,
        &sMagmortar1,
    },
};

const struct BossMoveList sYanmega1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BUG_BUZZ,
        MOVE_PSYCHIC_NOISE,
        MOVE_SHADOW_BALL,
        MOVE_AIR_SLASH
    },
};

const struct BossAi sYanmegaAi =
{
    .phaseMoves =
    {
        &sYanmega1,
        &sYanmega1,
        &sYanmega1,
        &sYanmega1,
    },
};

const struct BossMoveList sMamoswine1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_CURSE,
        MOVE_ICE_SHARD,
        MOVE_EARTHQUAKE,
        MOVE_CURSE,
        MOVE_ROCK_SLIDE,
        MOVE_AVALANCHE
    },
};

const struct BossAi sMamoswineAi =
{
    .phaseMoves =
    {
        &sMamoswine1,
        &sMamoswine1,
        &sMamoswine1,
        &sMamoswine1,
    },
};

const struct BossMoveList sProbopass1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SANDSTORM,
        MOVE_CHARGE_BEAM,
        MOVE_POWER_GEM,
        MOVE_EARTH_POWER,
        MOVE_GRAVITY,
        MOVE_ZAP_CANNON,
    },
};

const struct BossAi sProbopassAi =
{
    .phaseMoves =
    {
        &sProbopass1,
        &sProbopass1,
        &sProbopass1,
        &sProbopass1,
    },
};

const struct BossMoveList sSamurott1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FOCUS_ENERGY,
        MOVE_AQUA_CUTTER,
        MOVE_SACRED_SWORD,
        MOVE_SUCKER_PUNCH,
        MOVE_X_SCISSOR
    },
};

const struct BossMoveList sSamurott2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_AQUA_CUTTER,
        MOVE_SACRED_SWORD,
        MOVE_SUCKER_PUNCH,
        MOVE_X_SCISSOR
    },
};

const struct BossAi sSamurottAi =
{
    .phaseMoves =
    {
        &sSamurott1,
        &sSamurott2,
        &sSamurott1,
        &sSamurott1,
    },
};

const struct BossMoveList sLiepard1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SWAGGER,
        MOVE_FOUL_PLAY,
        MOVE_THUNDER_WAVE,
        MOVE_SCREECH,
        MOVE_GUNK_SHOT
    },
};

const struct BossAi sLiepardAi =
{
    .phaseMoves =
    {
        &sLiepard1,
        &sLiepard1,
        &sLiepard1,
        &sLiepard1,
    },
};

const struct BossMoveList sSimisage1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SUBSTITUTE,
        MOVE_POWER_UP_PUNCH,
        MOVE_GRASSY_GLIDE,
        MOVE_JUNGLE_HEALING,
    },
};

const struct BossAi sSimisageAi =
{
    .phaseMoves =
    {
        &sSimisage1,
        &sSimisage1,
        &sSimisage1,
        &sSimisage1,
    },
};

const struct BossMoveList sUnfezant1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FOCUS_ENERGY,
        MOVE_SLASH,
        MOVE_AERIAL_ACE,
        MOVE_NIGHT_SLASH,
        MOVE_ROOST,
    },
};

const struct BossAi sUnfezantAi =
{
    .phaseMoves =
    {
        &sUnfezant1,
        &sUnfezant1,
        &sUnfezant1,
        &sUnfezant1,
    },
};

const struct BossMoveList sSwoobat1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CALM_MIND,
        MOVE_AIR_SLASH,
        MOVE_FAKE_TEARS,
        MOVE_STORED_POWER,
        MOVE_GIGA_DRAIN
    },
};

const struct BossAi sSwoobatAi =
{
    .phaseMoves =
    {
        &sSwoobat1,
        &sSwoobat1,
        &sSwoobat1,
        &sSwoobat1,
    },
};

const struct BossMoveList sAudino1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_COTTON_GUARD,
        MOVE_CALM_MIND,
        MOVE_STORED_POWER,
        MOVE_DRAINING_KISS
    },
};

const struct BossAi sAudinoAi =
{
    .phaseMoves =
    {
        &sAudino1,
        &sAudino1,
        &sAudino1,
        &sAudino1,
    },
};

const struct BossMoveList sConkeldurr1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_BULK_UP,
        MOVE_DRAIN_PUNCH,
        MOVE_THUNDERPUNCH,
        MOVE_ICE_PUNCH,
        MOVE_ROCK_SLIDE
    },
};

const struct BossAi sConkeldurrAi =
{
    .phaseMoves =
    {
        &sConkeldurr1,
        &sConkeldurr1,
        &sConkeldurr1,
        &sConkeldurr1,
    },
};

const struct BossMoveList sWhimsicott1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_TAILWIND,
        MOVE_SUBSTITUTE,
        MOVE_LEECH_SEED,
        MOVE_MOONBLAST,
        MOVE_GIGA_DRAIN
    },
};

const struct BossAi sWhimsicottAi =
{
    .phaseMoves =
    {
        &sWhimsicott1,
        &sWhimsicott1,
        &sWhimsicott1,
        &sWhimsicott1,
    },
};

const struct BossMoveList sKrookodile1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_BULK_UP,
        MOVE_SCALE_SHOT,
        MOVE_EARTHQUAKE,
        MOVE_POWER_TRIP,
        MOVE_THUNDER_FANG,
        MOVE_FIRE_FANG
    },
};

const struct BossAi sKrookodileAi =
{
    .phaseMoves =
    {
        &sKrookodile1,
        &sKrookodile1,
        &sKrookodile1,
        &sKrookodile1,
    },
};

const struct BossMoveList sZoroark1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_FLAMETHROWER,
        MOVE_DARK_PULSE,
        MOVE_GRASS_KNOT,
        MOVE_SLUDGE_BOMB
    },
};

const struct BossAi sZoroarkAi =
{
    .phaseMoves =
    {
        &sZoroark1,
        &sZoroark1,
        &sZoroark1,
        &sZoroark1,
    },
};

const struct BossMoveList sCinccino1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_TIDY_UP,
        MOVE_TAIL_SLAP,
        MOVE_BULLET_SEED,
        MOVE_ROCK_BLAST,
        MOVE_TRIPLE_AXEL
    },
};

const struct BossAi sCinccinoAi =
{
    .phaseMoves =
    {
        &sCinccino1,
        &sCinccino1,
        &sCinccino1,
        &sCinccino1,
    },
};

const struct BossMoveList sReuniclus1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ACID_ARMOR,
        MOVE_CALM_MIND,
        MOVE_PSYCH_UP,
        MOVE_STORED_POWER,
        MOVE_FOCUS_BLAST
    },
};

const struct BossAi sReuniclusAi =
{
    .phaseMoves =
    {
        &sReuniclus1,
        &sReuniclus1,
        &sReuniclus1,
        &sReuniclus1,
    },
};

const struct BossMoveList sVanilluxe1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_BLIZZARD,
        MOVE_AURORA_VEIL,
        MOVE_FREEZE_DRY,
        MOVE_ACID_ARMOR,
        MOVE_FLASH_CANNON
    },
};

const struct BossAi sVanilluxeAi =
{
    .phaseMoves =
    {
        &sVanilluxe1,
        &sVanilluxe1,
        &sVanilluxe1,
        &sVanilluxe1,
    },
};

const struct BossMoveList sGalvantula1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_ELECTROWEB,
        MOVE_INFESTATION,
        MOVE_CHARGE_BEAM,
        MOVE_THUNDER,
        MOVE_THUNDER_WAVE,
        MOVE_MEGA_DRAIN
    },
};

const struct BossAi sGalvantulaAi =
{
    .phaseMoves =
    {
        &sGalvantula1,
        &sGalvantula1,
        &sGalvantula1,
        &sGalvantula1,
    },
};

const struct BossMoveList sHaxorus1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_DRAGON_CLAW,
        MOVE_MIGHTY_CLEAVE,
        MOVE_POISON_JAB,
        MOVE_CRUNCH,
        MOVE_SUPERPOWER
    },
};

const struct BossAi sHaxorusAi =
{
    .phaseMoves =
    {
        &sHaxorus1,
        &sHaxorus1,
        &sHaxorus1,
        &sHaxorus1,
    },
};

const struct BossMoveList sCryogonal1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_BLIZZARD,
        MOVE_FREEZE_DRY,
        MOVE_ACID_ARMOR,
        MOVE_RECOVER,
        MOVE_CHILLING_WATER
    },
};

const struct BossAi sCryogonalAi =
{
    .phaseMoves =
    {
        &sCryogonal1,
        &sCryogonal1,
        &sCryogonal1,
        &sCryogonal1,
    },
};

const struct BossMoveList sGolurk1 =
{
    .numMoves = 7,
    .moves =
    {
        MOVE_SHADOW_PUNCH,
        MOVE_FLY,
        MOVE_DYNAMIC_PUNCH,
        MOVE_THUNDERPUNCH,
        MOVE_ICE_PUNCH,
        MOVE_FIRE_PUNCH,
        MOVE_DRAIN_PUNCH
    },
};

const struct BossAi sGolurkAi =
{
    .phaseMoves =
    {
        &sGolurk1,
        &sGolurk1,
        &sGolurk1,
        &sGolurk1,
    },
};

const struct BossMoveList sBouffalant1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_HEAD_CHARGE,
        MOVE_WILD_CHARGE,
        MOVE_HEAD_SMASH,
        MOVE_SWORDS_DANCE,
        MOVE_CLOSE_COMBAT
    },
};

const struct BossAi sBouffalantAi =
{
    .phaseMoves =
    {
        &sBouffalant1,
        &sBouffalant1,
        &sBouffalant1,
        &sBouffalant1,
    },
};

const struct BossMoveList sHeatmor1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_FIRE_SPIN,
        MOVE_CURSE,
        MOVE_AMNESIA,
        MOVE_FIRE_LASH
    },
};

const struct BossMoveList sHeatmor2 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_FIRE_SPIN,
        MOVE_FIRE_LASH,
        MOVE_DRAIN_PUNCH,
        MOVE_NIGHT_SLASH,
        MOVE_THUNDER_PUNCH
    },
};

const struct BossAi sHeatmorAi =
{
    .phaseMoves =
    {
        &sHeatmor1,
        &sHeatmor2,
        &sHeatmor2,
        &sHeatmor2,
    },
};

const struct BossMoveList sVolcarona1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_QUIVER_DANCE,
        MOVE_FIERY_DANCE,
        MOVE_BUG_BUZZ,
        MOVE_SUBSTITUTE,
        MOVE_SOLAR_BEAM,
        MOVE_WILL_O_WISP
    },
};

const struct BossAi sVolcaronaAi =
{
    .phaseMoves =
    {
        &sVolcarona1,
        &sVolcarona1,
        &sVolcarona1,
        &sVolcarona1,
    },
};

const struct BossMoveList sChesnaught1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_CURSE,
        MOVE_LEECH_SEED,
        MOVE_BODY_PRESS,
        MOVE_TAUNT,
        MOVE_SPIKY_SHIELD,
        MOVE_GYRO_BALL
    },
};

const struct BossAi sChesnaughtAi =
{
    .phaseMoves =
    {
        &sChesnaught1,
        &sChesnaught1,
        &sChesnaught1,
        &sChesnaught1,
    },
};

const struct BossMoveList sDelphox1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_MYSTICAL_FIRE,
        MOVE_WILL_O_WISP,
        MOVE_PSYCHIC_NOISE,
        MOVE_HEX
    },
};

const struct BossAi sDelphoxAi =
{
    .phaseMoves =
    {
        &sDelphox1,
        &sDelphox1,
        &sDelphox1,
        &sDelphox1,
    },
};

const struct BossMoveList sGogoat1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_HIGH_HORSEPOWER,
        MOVE_GRASSY_GLIDE,
        MOVE_BODY_PRESS,
        MOVE_PROTECT,
        MOVE_TRAILBLAZE
    },
};

const struct BossAi sGogoatAi =
{
    .phaseMoves =
    {
        &sGogoat1,
        &sGogoat1,
        &sGogoat1,
        &sGogoat1,
    },
};

const struct BossMoveList sFurfrou1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_CHARM,
        MOVE_TOXIC,
        MOVE_SNARL,
        MOVE_COTTON_GUARD,
        MOVE_ENDEAVOR,
        MOVE_HEADBUTT
    },
};

const struct BossAi sFurfrouAi =
{
    .phaseMoves =
    {
        &sFurfrou1,
        &sFurfrou1,
        &sFurfrou1,
        &sFurfrou1,
    },
};

const struct BossMoveList sAegislash1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_KINGS_SHIELD,
        MOVE_SACRED_SWORD,
        MOVE_SWORDS_DANCE,
        MOVE_IRON_HEAD,
        MOVE_METAL_SOUND,
        MOVE_SHADOW_BALL
    },
};

const struct BossAi sAegislashAi =
{
    .phaseMoves =
    {
        &sAegislash1,
        &sAegislash1,
        &sAegislash1,
        &sAegislash1,
    },
};

const struct BossMoveList sMalamar1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SUPERPOWER,
        MOVE_STORED_POWER,
        MOVE_FLATTER,
        MOVE_TOPSY_TURVY,
        MOVE_PSYCHO_BOOST,
        MOVE_NIGHT_SLASH
    },
};

const struct BossAi sMalamarAi =
{
    .phaseMoves =
    {
        &sMalamar1,
        &sMalamar1,
        &sMalamar1,
        &sMalamar1,
    },
};

const struct BossMoveList sDragalge1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_TOXIC,
        MOVE_DRAGON_PULSE,
        MOVE_SURF,
        MOVE_THUNDERBOLT,
        MOVE_SHADOW_BALL,
        MOVE_VENOSHOCK
    },
};

const struct BossAi sDragalgeAi =
{
    .phaseMoves =
    {
        &sDragalge1,
        &sDragalge1,
        &sDragalge1,
        &sDragalge1,
    },
};

const struct BossMoveList sAurorus1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_GLACIATE,
        MOVE_HYPER_VOICE,
        MOVE_FROSTWISP,
        MOVE_EARTH_POWER
    },
};

const struct BossAi sAurorusAi =
{
    .phaseMoves =
    {
        &sAurorus1,
        &sAurorus1,
        &sAurorus1,
        &sAurorus1,
    },
};

const struct BossMoveList sGourgeist1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_LEECH_SEED,
        MOVE_FLARE_BLITZ,
        MOVE_PHANTOM_FORCE,
        MOVE_WILL_O_WISP,
        MOVE_SKITTER_SMACK
    }
};

const struct BossAi sGourgeistAi =
{
    .phaseMoves =
    {
        &sGourgeist1,
        &sGourgeist1,
        &sGourgeist1,
        &sGourgeist1,
    },
};

const struct BossMoveList sNoivern1 =
{
    .numMoves = 1,
    .moves =
    {
        MOVE_ECHOED_VOICE
    },
};

const struct BossAi sNoivernAi =
{
    .phaseMoves =
    {
        &sNoivern1,
        &sNoivern1,
        &sNoivern1,
        &sNoivern1,
    },
};

const struct BossMoveList sIncineroar1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_BULK_UP,
        MOVE_FLARE_BLITZ,
        MOVE_DARKEST_LARIAT,
        MOVE_EARTHQUAKE,
        MOVE_DOUBLE_EDGE
    },
};

const struct BossAi sIncineroarAi =
{
    .phaseMoves =
    {
        &sIncineroar1,
        &sIncineroar1,
        &sIncineroar1,
        &sIncineroar1,
    },
};

const struct BossMoveList sCrabominable1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ICE_HAMMER,
        MOVE_DRAIN_PUNCH,
        MOVE_THUNDER_PUNCH,
        MOVE_POWER_UP_PUNCH,
        MOVE_DRAIN_PUNCH
    },
};

const struct BossAi sCrabominableAi =
{
    .phaseMoves =
    {
        &sCrabominable1,
        &sCrabominable1,
        &sCrabominable1,
        &sCrabominable1,
    },
};

const struct BossMoveList sAraquanid1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_LIQUIDATION,
        MOVE_AQUA_RING,
        MOVE_REFLECT,
        MOVE_LEECH_LIFE,
        MOVE_MIRROR_COAT,
        MOVE_LUNGE,
    },
};

const struct BossAi sAraquanidAi =
{
    .phaseMoves =
    {
        &sAraquanid1,
        &sAraquanid1,
        &sAraquanid1,
        &sAraquanid1,
    },
};

const struct BossMoveList sLurantis1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_SUPERPOWER,
        MOVE_LEAF_STORM,
        MOVE_SYNTHESIS,
        MOVE_SOLAR_BLADE,
        MOVE_NIGHT_SLASH,
        MOVE_WEATHER_BALL
    },
};

const struct BossAi sLurantisAi =
{
    .phaseMoves =
    {
        &sLurantis1,
        &sLurantis1,
        &sLurantis1,
        &sLurantis1,
    },
};

const struct BossMoveList sSalazzle1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SLUDGE_BOMB,
        MOVE_NASTY_PLOT,
        MOVE_FIRE_BLAST,
        MOVE_TOXIC,
        MOVE_VENOSHOCK
    },
};

const struct BossAi sSalazzleAi =
{
    .phaseMoves =
    {
        &sSalazzle1,
        &sSalazzle1,
        &sSalazzle1,
        &sSalazzle1,
    },
};

const struct BossMoveList sComfey1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CALM_MIND,
        MOVE_MISTY_TERRAIN,
        MOVE_DRAINING_KISS,
        MOVE_LEECH_SEED,
        MOVE_GIGA_DRAIN,
    },
};

const struct BossAi sComfeyAi =
{
    .phaseMoves =
    {
        &sComfey1,
        &sComfey1,
        &sComfey1,
        &sComfey1,
    },
};

const struct BossMoveList sMinior1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SHELL_SMASH,
        MOVE_POWER_GEM,
        MOVE_ACROBATICS,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sMiniorAi =
{
    .phaseMoves =
    {
        &sMinior1,
        &sMinior1,
        &sMinior1,
        &sMinior1,
    },
};

const struct BossMoveList sTurtonator1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_WORK_UP,
        MOVE_FIRE_SPIN,
        MOVE_SHELL_TRAP,
        MOVE_FIRE_BLAST,
        MOVE_DRAGON_PULSE,
        MOVE_IRON_DEFENSE
    },
};

const struct BossAi sTurtonatorAi =
{
    .phaseMoves =
    {
        &sTurtonator1,
        &sTurtonator1,
        &sTurtonator1,
        &sTurtonator1,
    },
};

const struct BossMoveList sTogedemaru1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_MAGNET_RISE,
        MOVE_NUZZLE,
        MOVE_LIGHT_SCREEN,
        MOVE_ZING_ZAP,
        MOVE_STEEL_ROLLER
    },
};

const struct BossAi sTogedemaruAi =
{
    .phaseMoves =
    {
        &sTogedemaru1,
        &sTogedemaru1,
        &sTogedemaru1,
        &sTogedemaru1,
    },
};

const struct BossMoveList sCorviknight1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_IRON_DEFENSE,
        MOVE_BRAVE_BIRD,
        MOVE_LIGHT_SCREEN,
        MOVE_BODY_PRESS,
        MOVE_METAL_SOUND,
        MOVE_ROOST
    },
};

const struct BossAi sCorviknightAi =
{
    .phaseMoves =
    {
        &sCorviknight1,
        &sCorviknight1,
        &sCorviknight1,
        &sCorviknight1,
    },
};

const struct BossMoveList sCoalossal1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_TAR_SHOT,
        MOVE_FLAME_CHARGE,
        MOVE_TAR_SHOT,
        MOVE_SCALD,
        MOVE_FIRE_BLAST
    },
};

const struct BossAi sCoalossalAi =
{
    .phaseMoves =
    {
        &sCoalossal1,
        &sCoalossal1,
        &sCoalossal1,
        &sCoalossal1,
    },
};

const struct BossMoveList sBarraskewda1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_LIQUIDATION,
        MOVE_CRUNCH,
        MOVE_ICE_FANG,
        MOVE_PSYCHIC_FANGS
    },
};

const struct BossAi sBarraskewdaAi =
{
    .phaseMoves =
    {
        &sBarraskewda1,
        &sBarraskewda1,
        &sBarraskewda1,
        &sBarraskewda1,
    },
};

const struct BossMoveList sPerrserker1 =
{
    .numMoves = 2,
    .moves =
    {
        MOVE_METAL_SOUND,
        MOVE_IRON_HEAD,
    },
};

const struct BossMoveList sPerrserker2 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_IRON_HEAD,
        MOVE_CLOSE_COMBAT,
        MOVE_GUNK_SHOT,
        MOVE_DOUBLE_EDGE
    },
};

const struct BossAi sPerrserkerAi =
{
    .phaseMoves =
    {
        &sPerrserker1,
        &sPerrserker2,
        &sPerrserker2,
        &sPerrserker2,
    },
};

const struct BossMoveList sCursola1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_CALM_MIND,
        MOVE_BURNING_JEALOUSY,
        MOVE_WILL_O_WISP,
        MOVE_SCALD,
        MOVE_STRENGTH_SAP,
        MOVE_PSYCHIC
    },
};

const struct BossMoveList sCursola2 =
{
    .numMoves = 1,
    .moves =
    {
        MOVE_HEX
    },
};

const struct BossAi sCursolaAi =
{
    .phaseMoves =
    {
        &sCursola1,
        &sCursola2,
        &sCursola2,
        &sCursola2,
    },
};

const struct BossMoveList sWyrdeer1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_PSYSHIELD_BASH,
        MOVE_EARTH_POWER,
        MOVE_TRAILBLAZE,
        MOVE_CHARGE_BEAM,
        MOVE_STORED_POWER
    },
};

const struct BossAi sWyrdeerAi =
{
    .phaseMoves =
    {
        &sWyrdeer1,
        &sWyrdeer1,
        &sWyrdeer1,
        &sWyrdeer1,
    },
};

const struct BossMoveList sUrsaluna1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_BULK_UP,
        MOVE_TRAILBLAZE,
        MOVE_BODY_PRESS,
        MOVE_HEADLONG_RUSH
    },
};

const struct BossAi sUrsalunaAi =
{
    .phaseMoves =
    {
        &sUrsaluna1,
        &sUrsaluna1,
        &sUrsaluna1,
        &sUrsaluna1,
    },
};

const struct BossMoveList sMarowakAlola1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SHADOW_BONE,
        MOVE_POWER_UP_PUNCH,
        MOVE_FLARE_BLITZ,
        MOVE_BONE_RUSH,
        MOVE_ROCK_TOMB,
    },
};


const struct BossAi sMarowakAlolaAi =
{
    .phaseMoves =
    {
        &sMarowakAlola1,
        &sMarowakAlola1,
        &sMarowakAlola1,
        &sMarowakAlola1,
    },
};

const struct BossMoveList sMrMimeGalar1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_LIGHT_SCREEN,
        MOVE_SNOWSCAPE,
        MOVE_ICY_WIND,
        MOVE_PSYSHOCK,
        MOVE_BLIZZARD,
        MOVE_FOCUS_BLAST
    },
};

const struct BossAi sMrMimeGalarAi =
{
    .phaseMoves =
    {
        &sMrMimeGalar1,
        &sMrMimeGalar1,
        &sMrMimeGalar1,
        &sMrMimeGalar1,
    },
};

const struct BossMoveList sBraviary1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_ESPER_WING,
        MOVE_HEAT_WAVE,
        MOVE_HURRICANE,
        MOVE_PSYSHOCK,
        MOVE_ROOST
    },
};

const struct BossAi sBraviaryAi =
{
    .phaseMoves =
    {
        &sBraviary1,
        &sBraviary1,
        &sBraviary1,
        &sBraviary1,
    },
};

const struct BossMoveList sDarmanitan1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_CLOSE_COMBAT,
        MOVE_GUARD_SWAP,
        MOVE_ICE_PUNCH,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sDarmanitanAi =
{
    .phaseMoves =
    {
        &sDarmanitan1,
        &sDarmanitan1,
        &sDarmanitan1,
        &sDarmanitan1,
    },
};

const struct BossMoveList sSkeledirge1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_TORCH_SONG,
        MOVE_CURSE,
        MOVE_SLACK_OFF,
        MOVE_TORCH_SONG,
        MOVE_SHADOW_BALL,
        MOVE_OVERHEAT
    },
};

const struct BossAi sSkeledirgeAi =
{
    .phaseMoves =
    {
        &sSkeledirge1,
        &sSkeledirge1,
        &sSkeledirge1,
        &sSkeledirge1,
    },
};

const struct BossMoveList sSpidops1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_TOXIC_THREAD,
        MOVE_SUBSTITUTE,
        MOVE_LEECH_LIFE,
        MOVE_BRICK_BREAK,
        MOVE_INFESTATION
    },
};

const struct BossAi sSpidopsAi =
{
    .phaseMoves =
    {
        &sSpidops1,
        &sSpidops1,
        &sSpidops1,
        &sSpidops1,
    },
};

const struct BossMoveList sGarganacl1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_SALT_CURE,
        MOVE_CURSE,
        MOVE_RECOVER,
        MOVE_EARTHQUAKE
    },
};

const struct BossAi sGarganaclAi =
{
    .phaseMoves =
    {
        &sGarganacl1,
        &sGarganacl1,
        &sGarganacl1,
        &sGarganacl1,
    },
};

const struct BossMoveList sBellibolt1 =
{
    .numMoves = 7,
    .moves =
    {
        MOVE_CHARGE_BEAM,
        MOVE_REFLECT,
        MOVE_SOAK,
        MOVE_PARABOLIC_CHARGE,
        MOVE_ACID_SPRAY,
        MOVE_SOAK,
        MOVE_TOXIC,
    },
};

const struct BossAi sBelliboltAi =
{
    .phaseMoves =
    {
        &sBellibolt1,
        &sBellibolt1,
        &sBellibolt1,
        &sBellibolt1,
    },
};

const struct BossMoveList sEspathra1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_CALM_MIND,
        MOVE_LUMINA_CRASH,
        MOVE_DAZZLING_GLEAM,
        MOVE_STORED_POWER,
        MOVE_STORED_POWER
    },
};

const struct BossAi sEspathraAi =
{
    .phaseMoves =
    {
        &sEspathra1,
        &sEspathra1,
        &sEspathra1,
        &sEspathra1,
    },
};

const struct BossMoveList sBombirdier1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_HONE_CLAWS,
        MOVE_ROCK_TOMB,
        MOVE_DUAL_WINGBEAT,
        MOVE_DRILL_RUN,
        MOVE_THIEF
    },
};

const struct BossAi sBombirdierAi =
{
    .phaseMoves =
    {
        &sBombirdier1,
        &sBombirdier1,
        &sBombirdier1,
        &sBombirdier1,
    },
};

const struct BossMoveList sHoundstone1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SANDSTORM,
        MOVE_IRON_DEFENSE,
        MOVE_BODY_PRESS,
        MOVE_FROSTWISP,
        MOVE_PHANTOM_FORCE
    },
};

const struct BossAi sHoundstoneAi =
{
    .phaseMoves =
    {
        &sHoundstone1,
        &sHoundstone1,
        &sHoundstone1,
        &sHoundstone1,
    },
};

const struct BossMoveList sFarigiraf1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_TWIN_BEAM,
        MOVE_WISH,
        MOVE_CHARGE_BEAM,
        MOVE_ENERGY_BALL
    },
};

const struct BossAi sFarigirafAi =
{
    .phaseMoves =
    {
        &sFarigiraf1,
        &sFarigiraf1,
        &sFarigiraf1,
        &sFarigiraf1,
    },
};

const struct BossMoveList sKingambit1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_SWORDS_DANCE,
        MOVE_KOWTOW_CLEAVE,
        MOVE_IRON_HEAD,
        MOVE_SUCKER_PUNCH,
        MOVE_AERIAL_ACE
    },
};

const struct BossAi sKingambitAi =
{
    .phaseMoves =
    {
        &sKingambit1,
        &sKingambit1,
        &sKingambit1,
        &sKingambit1,
    },
};

const struct BossMoveList sScreamTail1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_HYPER_VOICE,
        MOVE_DRAIN_PUNCH,
        MOVE_PSYSHOCK,
        MOVE_FIRE_PUNCH,
        MOVE_STORED_POWER,
        MOVE_DOUBLE_EDGE
    },
};

const struct BossAi sScreamTailAi =
{
    .phaseMoves =
    {
        &sScreamTail1,
        &sScreamTail1,
        &sScreamTail1,
        &sScreamTail1,
    },
};

const struct BossMoveList sGholdengo1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_STEEL_BEAM,
        MOVE_RECOVER,
        MOVE_NASTY_PLOT,
        MOVE_SHADOW_BALL,
        MOVE_THUNDERBOLT,
        MOVE_MAKE_IT_RAIN,
    },
};

const struct BossAi sGholdengoAi =
{
    .phaseMoves =
    {
        &sGholdengo1,
        &sGholdengo1,
        &sGholdengo1,
        &sGholdengo1,
    },
};

const struct BossMoveList sHydrapple1 =
{
    .numMoves = 6,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_FICKLE_BEAM,
        MOVE_SYRUP_BOMB,
        MOVE_DRACO_METEOR,
        MOVE_EARTH_POWER,
        MOVE_RECOVER
    },
};

const struct BossAi sHydrappleAi =
{
    .phaseMoves =
    {
        &sHydrapple1,
        &sHydrapple1,
        &sHydrapple1,
        &sHydrapple1,
    },
};

const struct BossMoveList sMagcargo1 =
{
    .numMoves = 3,
    .moves =
    {
        MOVE_SHELL_SMASH,
        MOVE_EARTH_POWER,
        MOVE_OVERHEAT,
    },
};

const struct BossAi sMagcargoAi =
{
    .phaseMoves =
    {
        &sMagcargo1,
        &sMagcargo1,
        &sMagcargo1,
        &sMagcargo1,
    }
};

const struct BossMoveList sClawitzer1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_WATER_PULSE,
        MOVE_DRAGON_PULSE,
        MOVE_TERRAIN_PULSE,
        MOVE_AURA_SPHERE,
        MOVE_ORIGIN_PULSE
    },
};

const struct BossAi sClawitzerAi =
{
    .phaseMoves =
    {
        &sClawitzer1,
        &sClawitzer1,
        &sClawitzer1,
        &sClawitzer1,
    }
};

const struct BossMoveList sSimisear1 =
{
    .numMoves = 4,
    .moves =
    {
        MOVE_NASTY_PLOT,
        MOVE_FLAMETHROWER,
        MOVE_POWER_UP_PUNCH,
        MOVE_FIRE_SPIN,
        MOVE_ROCK_TOMB

    },
};

const struct BossAi sSimisearAi =
{
    .phaseMoves =
    {
        &sSimisear1,
        &sSimisear1,
        &sSimisear1,
        &sSimisear1,
    }
};

const struct BossMoveList sKleavor1 =
{
    .numMoves = 5,
    .moves =
    {
        MOVE_AGILITY,
        MOVE_STONE_AXE,
        MOVE_X_SCISSOR,
        MOVE_CLOSE_COMBAT,
        MOVE_ROOST
    },
};

const struct BossAi sKleavorAi =
{
    .phaseMoves =
    {
        &sKleavor1,
        &sKleavor1,
        &sKleavor1,
        &sKleavor1,
    }
};
