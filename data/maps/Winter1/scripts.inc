Winter1_MapScripts::
	.byte 0


Winter1_1::
# 5 "data/maps/Winter1/scripts.pory"
	checkbossstatus 1
# 6 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_1_2
# 12 "data/maps/Winter1/scripts.pory"
	choosecurrentboss 1
# 13 "data/maps/Winter1/scripts.pory"
	waitstate
# 14 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_1_5
Winter1_1_4:
# 17 "data/maps/Winter1/scripts.pory"
	release
	return

Winter1_1_2:
# 7 "data/maps/Winter1/scripts.pory"
	msgbox Winter1_1_Text_0
# 8 "data/maps/Winter1/scripts.pory"
	waitmessage
# 9 "data/maps/Winter1/scripts.pory"
	release
	end

Winter1_1_5:
# 15 "data/maps/Winter1/scripts.pory"
	warpsilent MAP_WINTER1BOSS, 15, 24
	goto Winter1_1_4


Winter1_2::
# 21 "data/maps/Winter1/scripts.pory"
	checkbossstatus 2
# 22 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_2_2
# 28 "data/maps/Winter1/scripts.pory"
	choosecurrentboss 2
# 29 "data/maps/Winter1/scripts.pory"
	waitstate
# 30 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_2_5
Winter1_2_4:
# 33 "data/maps/Winter1/scripts.pory"
	release
	return

Winter1_2_2:
# 23 "data/maps/Winter1/scripts.pory"
	msgbox Winter1_1_Text_0
# 24 "data/maps/Winter1/scripts.pory"
	waitmessage
# 25 "data/maps/Winter1/scripts.pory"
	release
	end

Winter1_2_5:
# 31 "data/maps/Winter1/scripts.pory"
	warpsilent MAP_WINTER1BOSS, 15, 24
	goto Winter1_2_4


Winter1_3::
# 37 "data/maps/Winter1/scripts.pory"
	checkbossstatus 3
# 38 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_3_2
# 44 "data/maps/Winter1/scripts.pory"
	choosecurrentboss 3
# 45 "data/maps/Winter1/scripts.pory"
	waitstate
# 46 "data/maps/Winter1/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter1_3_5
Winter1_3_4:
# 49 "data/maps/Winter1/scripts.pory"
	release
	return

Winter1_3_2:
# 39 "data/maps/Winter1/scripts.pory"
	msgbox Winter1_1_Text_0
# 40 "data/maps/Winter1/scripts.pory"
	waitmessage
# 41 "data/maps/Winter1/scripts.pory"
	release
	end

Winter1_3_5:
# 47 "data/maps/Winter1/scripts.pory"
	warpsilent MAP_WINTER1BOSS, 15, 24
	goto Winter1_3_4


Winter1_1_Text_0:
# 7 "data/maps/Winter1/scripts.pory"
	.string "The image of {STR_VAR_1} has faded.$"
