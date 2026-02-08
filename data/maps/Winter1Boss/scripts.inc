Winter1Boss_MapScripts::
	.byte 0


Winter1_BossBattle::
# 6 "data/maps/Winter1Boss/scripts.pory"
	lock
# 7 "data/maps/Winter1Boss/scripts.pory"
	faceplayer
# 8 "data/maps/Winter1Boss/scripts.pory"
	callnative SetBossForBattle
# 9 "data/maps/Winter1Boss/scripts.pory"
	setwildbattle VAR_RESULT, BOSS_LEVEL, ITEM_NONE
# 10 "data/maps/Winter1Boss/scripts.pory"
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
# 11 "data/maps/Winter1Boss/scripts.pory"
	bufferremoveobject LOCALID_BOSS
# 12 "data/maps/Winter1Boss/scripts.pory"
	waitmoncry
# 13 "data/maps/Winter1Boss/scripts.pory"
	dowildbattle
# 14 "data/maps/Winter1Boss/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_ne Winter1_BossBattle_2
Winter1_BossBattle_1:
# 28 "data/maps/Winter1Boss/scripts.pory"
	release
	return

Winter1_BossBattle_2:
# 15 "data/maps/Winter1Boss/scripts.pory"
	bufferspeciesname STR_VAR_3, VAR_CURRENT_ENEMY
# 16 "data/maps/Winter1Boss/scripts.pory"
	callnative SetAbilityReward
# 17 "data/maps/Winter1Boss/scripts.pory"
	msgBox Winter1_BossBattle_Text_0
# 18 "data/maps/Winter1Boss/scripts.pory"
	waitmessage
# 19 "data/maps/Winter1Boss/scripts.pory"
	setvar VAR_0x8004, 0
# 20 "data/maps/Winter1Boss/scripts.pory"
	setvar VAR_0x8005, 2
# 21 "data/maps/Winter1Boss/scripts.pory"
	setvar VAR_0x8006, 8
# 22 "data/maps/Winter1Boss/scripts.pory"
	setvar VAR_0x8007, 3
# 23 "data/maps/Winter1Boss/scripts.pory"
	special ShakeCamera
# 24 "data/maps/Winter1Boss/scripts.pory"
	waitstate
# 25 "data/maps/Winter1Boss/scripts.pory"
	delay 40
# 26 "data/maps/Winter1Boss/scripts.pory"
	warpcontinuescript MAP_WINTER2, 10, 10, MythHub_AfterBoss
	goto Winter1_BossBattle_1


Winter1_Miniboss1::
# 32 "data/maps/Winter1Boss/scripts.pory"
	lock
# 33 "data/maps/Winter1Boss/scripts.pory"
	faceplayer
# 34 "data/maps/Winter1Boss/scripts.pory"
	setminiboss 1, 0
# 35 "data/maps/Winter1Boss/scripts.pory"
	setflag FLAG_AREA1_MINIBOSS1
# 36 "data/maps/Winter1Boss/scripts.pory"
	playmoncry VAR_RESULT, CRY_MODE_ENCOUNTER
# 37 "data/maps/Winter1Boss/scripts.pory"
	bufferremoveobject LOCALID_MINIBOSS1
# 38 "data/maps/Winter1Boss/scripts.pory"
	waitmoncry
# 39 "data/maps/Winter1Boss/scripts.pory"
	setwildbattle VAR_RESULT, BOSS_LEVEL, ITEM_NONE
# 40 "data/maps/Winter1Boss/scripts.pory"
	dowildbattle
# 41 "data/maps/Winter1Boss/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_ne Winter1_Miniboss1_2
Winter1_Miniboss1_1:
# 46 "data/maps/Winter1Boss/scripts.pory"
	release
	return

Winter1_Miniboss1_2:
# 42 "data/maps/Winter1Boss/scripts.pory"
	bufferspeciesname STR_VAR_3, VAR_CURRENT_ENEMY
# 43 "data/maps/Winter1Boss/scripts.pory"
	callnative SetMoveReward
# 44 "data/maps/Winter1Boss/scripts.pory"
	msgBox Winter1_BossBattle_Text_0
	goto Winter1_Miniboss1_1


Winter1_Miniboss2::
# 50 "data/maps/Winter1Boss/scripts.pory"
	lock
# 51 "data/maps/Winter1Boss/scripts.pory"
	faceplayer
# 52 "data/maps/Winter1Boss/scripts.pory"
	setminiboss 1, 1
# 53 "data/maps/Winter1Boss/scripts.pory"
	setflag FLAG_AREA1_MINIBOSS2
# 54 "data/maps/Winter1Boss/scripts.pory"
	playmoncry VAR_RESULT, CRY_MODE_ENCOUNTER
# 55 "data/maps/Winter1Boss/scripts.pory"
	bufferremoveobject LOCALID_MINIBOSS2
# 56 "data/maps/Winter1Boss/scripts.pory"
	waitmoncry
# 57 "data/maps/Winter1Boss/scripts.pory"
	setwildbattle VAR_RESULT, BOSS_LEVEL, ITEM_NONE
# 58 "data/maps/Winter1Boss/scripts.pory"
	dowildbattle
# 59 "data/maps/Winter1Boss/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_ne Winter1_Miniboss2_2
Winter1_Miniboss2_1:
# 64 "data/maps/Winter1Boss/scripts.pory"
	release
	return

Winter1_Miniboss2_2:
# 60 "data/maps/Winter1Boss/scripts.pory"
	bufferspeciesname STR_VAR_3, VAR_CURRENT_ENEMY
# 61 "data/maps/Winter1Boss/scripts.pory"
	callnative SetMoveReward
# 62 "data/maps/Winter1Boss/scripts.pory"
	msgBox Winter1_BossBattle_Text_0
	goto Winter1_Miniboss2_1


Winter1_Miniboss3::
# 68 "data/maps/Winter1Boss/scripts.pory"
	lock
# 69 "data/maps/Winter1Boss/scripts.pory"
	faceplayer
# 70 "data/maps/Winter1Boss/scripts.pory"
	setminiboss 1, 2
# 71 "data/maps/Winter1Boss/scripts.pory"
	setflag FLAG_AREA1_MINIBOSS3
# 72 "data/maps/Winter1Boss/scripts.pory"
	playmoncry VAR_RESULT, CRY_MODE_ENCOUNTER
# 73 "data/maps/Winter1Boss/scripts.pory"
	bufferremoveobject LOCALID_MINIBOSS3
# 74 "data/maps/Winter1Boss/scripts.pory"
	waitmoncry
# 75 "data/maps/Winter1Boss/scripts.pory"
	setwildbattle VAR_RESULT, BOSS_LEVEL, ITEM_NONE
# 76 "data/maps/Winter1Boss/scripts.pory"
	dowildbattle
# 77 "data/maps/Winter1Boss/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_ne Winter1_Miniboss3_2
Winter1_Miniboss3_1:
# 82 "data/maps/Winter1Boss/scripts.pory"
	release
	return

Winter1_Miniboss3_2:
# 78 "data/maps/Winter1Boss/scripts.pory"
	bufferspeciesname STR_VAR_3, VAR_CURRENT_ENEMY
# 79 "data/maps/Winter1Boss/scripts.pory"
	callnative SetMoveReward
# 80 "data/maps/Winter1Boss/scripts.pory"
	msgBox Winter1_BossBattle_Text_0
	goto Winter1_Miniboss3_1


Winter1_BossBattle_Text_0:
# 17 "data/maps/Winter1Boss/scripts.pory"
	.string "You gained the power of {STR_VAR_3}!\nObtained {STR_VAR_2}!$"
