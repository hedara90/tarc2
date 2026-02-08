Winter2_MapScripts::
	.byte 0


Winter2_1::
# 5 "data/maps/Winter2/scripts.pory"
	checkbossstatus 4
# 6 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_1_2
# 12 "data/maps/Winter2/scripts.pory"
	choosecurrentboss 4
# 13 "data/maps/Winter2/scripts.pory"
	waitstate
# 14 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_1_5
Winter2_1_4:
# 17 "data/maps/Winter2/scripts.pory"
	release
	return

Winter2_1_2:
# 7 "data/maps/Winter2/scripts.pory"
	msgbox Winter2_1_Text_0
# 8 "data/maps/Winter2/scripts.pory"
	waitmessage
# 9 "data/maps/Winter2/scripts.pory"
	release
	end

Winter2_1_5:
# 15 "data/maps/Winter2/scripts.pory"
	warpsilent MAP_WINTER2BOSS, 15, 15
	goto Winter2_1_4


Winter2_2::
# 21 "data/maps/Winter2/scripts.pory"
	checkbossstatus 5
# 22 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_2_2
# 28 "data/maps/Winter2/scripts.pory"
	choosecurrentboss 5
# 29 "data/maps/Winter2/scripts.pory"
	waitstate
# 30 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_2_5
Winter2_2_4:
# 33 "data/maps/Winter2/scripts.pory"
	release
	return

Winter2_2_2:
# 23 "data/maps/Winter2/scripts.pory"
	msgbox Winter2_1_Text_0
# 24 "data/maps/Winter2/scripts.pory"
	waitmessage
# 25 "data/maps/Winter2/scripts.pory"
	release
	end

Winter2_2_5:
# 31 "data/maps/Winter2/scripts.pory"
	warpsilent MAP_WINTER2BOSS, 15, 15
	goto Winter2_2_4


Winter2_3::
# 37 "data/maps/Winter2/scripts.pory"
	checkbossstatus 6
# 38 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_3_2
# 44 "data/maps/Winter2/scripts.pory"
	choosecurrentboss 6
# 45 "data/maps/Winter2/scripts.pory"
	waitstate
# 46 "data/maps/Winter2/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Winter2_3_5
Winter2_3_4:
# 49 "data/maps/Winter2/scripts.pory"
	release
	return

Winter2_3_2:
# 39 "data/maps/Winter2/scripts.pory"
	msgbox Winter2_1_Text_0
# 40 "data/maps/Winter2/scripts.pory"
	waitmessage
# 41 "data/maps/Winter2/scripts.pory"
	release
	end

Winter2_3_5:
# 47 "data/maps/Winter2/scripts.pory"
	warpsilent MAP_WINTER2BOSS, 15, 15
	goto Winter2_3_4


Winter2_1_Text_0:
# 7 "data/maps/Winter2/scripts.pory"
	.string "The image of {STR_VAR_1} has faded.$"
