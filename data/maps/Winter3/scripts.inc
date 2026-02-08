Winter3_MapScripts::
	.byte 0


Winter3_1::
# 5 "data/maps/Winter3/scripts.pory"
	checkbossstatus 7
# 6 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_1_2
# 12 "data/maps/Winter3/scripts.pory"
	choosecurrentboss 7
# 13 "data/maps/Winter3/scripts.pory"
	waitstate
# 14 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_1_5
Winter3_1_4:
# 17 "data/maps/Winter3/scripts.pory"
	release
	return

Winter3_1_2:
# 7 "data/maps/Winter3/scripts.pory"
	msgbox Winter3_1_Text_0
# 8 "data/maps/Winter3/scripts.pory"
	waitmessage
# 9 "data/maps/Winter3/scripts.pory"
	release
	end

Winter3_1_5:
# 15 "data/maps/Winter3/scripts.pory"
	warpsilent MAP_WINTER3BOSS, 15, 10
	goto Winter3_1_4


Winter3_2::
# 21 "data/maps/Winter3/scripts.pory"
	checkbossstatus 8
# 22 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_2_2
# 28 "data/maps/Winter3/scripts.pory"
	choosecurrentboss 8
# 29 "data/maps/Winter3/scripts.pory"
	waitstate
# 30 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_2_5
Winter3_2_4:
# 33 "data/maps/Winter3/scripts.pory"
	release
	return

Winter3_2_2:
# 23 "data/maps/Winter3/scripts.pory"
	msgbox Winter3_1_Text_0
# 24 "data/maps/Winter3/scripts.pory"
	waitmessage
# 25 "data/maps/Winter3/scripts.pory"
	release
	end

Winter3_2_5:
# 31 "data/maps/Winter3/scripts.pory"
	warpsilent MAP_WINTER3BOSS, 15, 10
	goto Winter3_2_4


Winter3_3::
# 37 "data/maps/Winter3/scripts.pory"
	checkbossstatus 9
# 38 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_3_2
# 44 "data/maps/Winter3/scripts.pory"
	choosecurrentboss 9
# 45 "data/maps/Winter3/scripts.pory"
	waitstate
# 46 "data/maps/Winter3/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter3_3_5
Winter3_3_4:
# 49 "data/maps/Winter3/scripts.pory"
	release
	return

Winter3_3_2:
# 39 "data/maps/Winter3/scripts.pory"
	msgbox Winter3_1_Text_0
# 40 "data/maps/Winter3/scripts.pory"
	waitmessage
# 41 "data/maps/Winter3/scripts.pory"
	release
	end

Winter3_3_5:
# 47 "data/maps/Winter3/scripts.pory"
	warpsilent MAP_WINTER3BOSS, 15, 10
	goto Winter3_3_4


Winter3_1_Text_0:
# 7 "data/maps/Winter3/scripts.pory"
	.string "The image of {STR_VAR_1} has faded.$"
